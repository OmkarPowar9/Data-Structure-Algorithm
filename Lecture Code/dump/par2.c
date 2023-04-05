#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *left,*right;
}NODE;

NODE *root=NULL;

void createtree()
{
    NODE*temp=malloc(sizeof(NODE));
    temp->left=temp->right=NULL;
    printf("Enter Root info:");
    scanf("%d",&temp->info);
    root=temp;
    int ch;
    printf("do you want to add more ele's:");
    scanf("%d",&ch);
    while(ch)
    {
        NODE *temp=malloc(sizeof(NODE));
        temp->left=temp->right=NULL;
        printf("\nEnter info:");
        scanf("%d",&temp->info);
        NODE *p=root;
        NODE *q=NULL;
        while(p!=NULL)
        {
            q=p;
            if(temp->info < p->info)
              p=p->left;
           else
           p=p->right;
        }
        if(temp->info<q->info)
         q->left=temp;
        else
         q->right=temp;
        
        printf("Do you want To add more ele's:");
        scanf("%d",&ch);
    }
}

void inord(NODE *r)
{
    if(r==NULL)
      return;
    inord(r->left);
    printf("%d ",r->info);
    inord(r->right);
}
void preord(NODE *r)
{
    if(r==NULL)
      return;
    printf("%d ",r->info);
    preord(r->left);
    preord(r->right);
}

void postord(NODE* r)
{
    if(r==NULL)
      return;
    postord(r->left);
    postord(r->right);
    printf("%d ",r->info);
}

// void destroyTree(NODE* r)
// {
//     if(r!=NULL)
//     {


//     }
// }

int findmax(NODE* r)
{
    if(r==NULL)
      return -1;
    while(r->right!=NULL)
       r=r->right;
    return r->info;
}
int findmin(NODE* r)
{
    if(r==NULL)
      return -1;
    while(r->left!=NULL)
      r=r->left;
    return r->info;
}
NODE* delnode(NODE* r,int ele)
{
    if(r==NULL)
      return r;
    NODE* temp=NULL;
    if(ele<r->info)
      r->left=delnode(r->left,ele);
    else if(ele>r->info)
      r->right=delnode(r->right,ele);
    else if(r->left==NULL)
    {
        temp=r->right;
        free(r);
        return temp;
    }
    else if(r->right==NULL)
    {
        temp=r->left;
        free(r);
        return temp;
    }
    else
    {
        temp=r->right;
        while(temp->left!=NULL)
          temp=temp->left;
        r->info=temp->info;
        r->right=delnode(r->right,temp->info);
    }
    return r;
}
int search(NODE* r,int ele)
{
    while(r!=NULL)
    {
        if(ele==r->info)
          return 1;
        else if(ele<r->info)
         return search(r->left,ele);
        else
         return search(r->right,ele);
    }
    return 0;
}



int main()
{
    int ele;
    createtree();
    printf("\nInorder traversal:");
    inord(root);
    printf("\nPreorder traversal:");
    preord(root);
    printf("\nPostorder traversal:");
    postord(root);
    int x=findmax(root);
    if(x==-1)
     printf("Empry tree\n");
    else 
     printf("\nmax=%d",x);
    int y=findmin(root);
    if(y==-1)
     printf("Empty tree\n");
    else 
     printf("\nmin=%d",y);
    printf("\nEnter the node to del:");
    scanf("%d",&ele);
    if(search(root,ele))
    {
        delnode(root,ele);
        inord(root);
    }
    else
    printf("Element not found\n");
    return 0;

     


    

}
