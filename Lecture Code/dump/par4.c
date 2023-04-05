#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left,*right;
    int rthread;
}NODE;

typedef struct tree
{
    NODE *root;
}TREE;

void initTree(TREE *pt)
{
    pt->root=NULL;
}

NODE *getnode()
{
    NODE *temp=malloc(sizeof(NODE));
    printf("Enter the info:");
    scanf("%d",&temp->info);
    temp->left=NULL;
    temp->right=NULL;
    temp->rthread=1;
    return temp;
}
void setleft(NODE *q,NODE *t)
{
    if(q==NULL) return;
    if(q->left!=NULL)return;
    q->left=t;
    t->right=q;
}

void setright(NODE *p,NODE *t)
{
    if(p==NULL)return;
    if(!p->rthread)return;
    t->right=p->right;
    p->right=t;
    p->rthread=0;
}

void create(TREE *pt)
{
    NODE *temp,*p,*q;
    int ch;
    pt->root=getnode();
    do
    {
        temp=getnode();
        q=NULL;
        p=pt->root;
        while(p!=NULL)
        {
            q=p;
            if(temp->info<p->info)
               p=p->left;
            else
            {
                if(p->rthread)
                  break;
                p=p->right;
            }
        }
        if(p==NULL)
          setleft(q,temp);
        else 
        setright(p,temp);

        printf("do u want to add node:");
        scanf("%d",&ch);

    

    }while(ch);
}

void io(TREE *pt)
{
    NODE *p,*q;
    p=pt->root;
    do{
        q=NULL;
        while(p!=NULL)
        {
            q=p;
            p=p->left;
        }
        if(q!=NULL)
        {
            printf("%d",q->info);
            p=q->right;
        }
        while(q!=NULL && q->rthread && p!=NULL)
        {
            printf("%d",p->info);
            q=p;
            p=p->right;
        }
    }while(q!=NULL);
}
int main()
{
    TREE tobj;
    initTree(&tobj);
    create(&tobj);
    io(&tobj);
    return 0;
}

