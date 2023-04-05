#include<stdio.h>
#define max 10

typedef struct node
{
	int info;
	int used;
}NODE;

void initTree(NODE bst[max])
{
	for(int i=0;i<max;i++)
		bst[i].used=0;
}
void createTree(NODE bst[max])
{
	int ele,ch;
	printf("enter root node info:");
	scanf("%d",&ele);
	bst[0].info=ele;
	bst[0].used=1;
	printf("\ndo you want add more nodes:");
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
				printf("duplicate\n");
				break;
			}
			if(ele<bst[i].info)
				i=2*i+1;
			else
				i=2*i+2;
		}
		if(i>=max)
		{
			printf("outside array bound,insertion not possible\n");
			continue;
		}
		if(bst[i].used)
			continue;
		
		bst[i].info=ele;
		bst[i].used=1;
		printf("\ndo you want add more nodes:");
		scanf("%d",&ch);
	}
}
void levelorder(NODE bst[max])
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
	initTree(bst);
	createTree(bst);
	printf("level order:");
	levelorder(bst);
	printf(" \nInorder:");
	inorder(bst,0);
	printf(" \npreorder:");
	preorder(bst,0);
	printf(" \nPostorder:");
	postorder(bst,0);
}