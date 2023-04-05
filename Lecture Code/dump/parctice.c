#include<stdio.h>
#define max 10

typedef struct node
{
    int info;
    int used;
}NODE;

void intiTree(NODE bst[max])
{
    for(int i=0;i<max;i++)
    bst[i].used=0;
}

void createtree(NODE bst[max])
{
    int ele,ch;
    printf("Enter root node info:");
    scanf("%d",&ele);
    bst[0].info=ele;
    bst[0].used=1;
    printf("]nDo you want to add more nodes:");
    scanf("%d",&ch);
    int i;
    while(ch)
    {
        printf("enter node info:");
        scanf("%d",&ele);
        i=0;
        while(i<max && bst[i].used)
        {
            if(ele==bst[i].info)
            {
                printf("dupicate\n");
                break;
            }
            if(ele<bst[i].info)
              i=2*i+1;             //Left Position
            else
            i=2*1+2;               //Right Position
        }
        if(i>=max)
        {
            printf("outside array bound,insertion not possible");
            continue;
        }
        if(bst[i].used)
        continue;


        bst[i].info=ele;
        bst[i].used=1;
        printf("\nDo you want more nodes:");
        scanf("%d",&ch);
    }
}

void Levelorder(NODE bst[max])
{
    for(int i=0;i<max;i++)
     if(bst[i].used)
       printf("%d ",bst[i].info);
}

void inorder(NODE bst[max],int i)
{
    if(i<max && bst[i].used)
    {
        inorder(bst,2*i+1);
        printf("%d ",bst[i].info);
        inorder(bst,2*i+2);
    }
}

void preorder(NODE bst[max],int i)
{
    if(i<max && bst[i].used)
    {
        printf("%d ",bst[i].info);
        preorder(bst,2*i+1);
        preorder(bst,2*i+2);
    }

}
void postorder(NODE bst[max],int i)
{
    if(i<max && bst[i].used)
    {
        postorder(bst,2*i+1);
        postorder(bst,2*i+2);
        printf("%d ",bst[i].info);
    }
}

int main()
{
    NODE bst[max];
    intiTree(bst);
    createtree(bst);
    printf("level order:");
    Levelorder(bst);
    printf("\ninorder:");
    inorder(bst,0);
    printf("\nPreoder:");
    preorder(bst,0);
    printf("\nPostorder:");
    postorder(bst,0);


}