#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

typedef struct llist
{
	NODE *head;
}LLIST;

void initList(LLIST*);
void insertFront(LLIST*,int);
void insertLast(LLIST*,int);
void insertAtPos(LLIST*,int,int);
void display(LLIST*);

void initList(LLIST *sll)
{
	sll->head=NULL;
}

NODE * getnode(int ele)
{
	NODE *temp=malloc(sizeof(int));
	temp->data= ele;
	temp->next= NULL;
	return temp;
}
void insertFront(LLIST *sll,int ele)
{
	NODE *temp=getnode(ele);
	temp->next=sll->head;
	sll->head=temp;
}
void insertLast(LLIST *sll,int ele)
{
	NODE *temp=getnode(ele);
	if(sll->head==NULL)
	{
		sll->head=temp;
		return;
	}
	NODE *p=sll->head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
}
void insertAtPos(LLIST *sll,int ele,int pos)
{
	NODE *temp=getnode(ele);
	if(pos==0)
	{
		temp->next=sll->head;
		sll->head=temp;
		return;
	}
	NODE *p=sll->head,*q=NULL;
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=temp;
	temp->next=p;
}
void display(LLIST *sll)
{
	NODE *p=sll->head;
	if(sll->head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;	
	}
}
void destroyList(LLIST *sll)
{
	NODE *p=sll->head,*q=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	sll->head=NULL;
}
void deleteFront(LLIST *sll)
{
	NODE *p=sll->head;
	sll->head=p->next;
	printf("%d\n",p->data);
	free(p);
}
void deleteLast(LLIST *sll)
{
	NODE *p=sll->head, *q=NULL;
	if(p->next==NULL)
	{
		sll->head=NULL;
		printf("%d",p->data);
		free(p);
		return;
	}
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	printf("%d",p->data);
	free(p);
}
void deleteAtPos(LLIST *sll,int pos)
{
	NODE *p=sll->head,*q=NULL;
	if(pos==0)
	{
		sll->head=p->next;
		printf("%d",p->data);
		free(p);
		return;
	}
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	printf("%d",p->data);
	free(p);
}
void search(LLIST *sll,int key)
{
	NODE *p=sll->head;
	int pos=1;
	while(p->next!=NULL && p->data!=key)
	{
		p=p->next;
		pos++;
	}
	if(p->data==key)
		printf("The key %d is present at pos %d\n",key,pos);
	else
		printf("key not found");
}
void reverseList(LLIST *sll)
{
	NODE *p=NULL,*c=sll->head,*n=NULL;
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	sll->head=p;
}
void delAlt(LLIST *sll)
{
	NODE *p=NULL,*c=sll->head;
	while(c->next!=NULL)
	{
		p=c;
		c=c->next;
		p->next=c->next;
		free(c);
		c=p->next;
	}
}
int main()
{
    int ele,pos,ch;
	LLIST lobj;
	initList(&lobj);
	do{
		printf("1.InsertFront 2.InsertLast 3.InsertAtPos 4.Display\n");
		printf("6.DeleteFront 7.DeleteLast 8.DeleteAtPos 5.Destroy\n");
		printf("9.search 10.reverseList 11.delAlt\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter ele");
				   scanf("%d",&ele);
				   insertFront(&lobj,ele);
				   break;
			case 2:printf("enter ele");
				   scanf("%d",&ele);
				   insertLast(&lobj,ele);
				   break;
			case 3:printf("enter ele");
				   scanf("%d",&ele);
				   printf("enter the pos:");
				   scanf("%d",&pos);
				   insertAtPos(&lobj,ele,pos);
				   break;
			case 4:display(&lobj);
					break;
			case 5:destroyList(&lobj);
				   break;
			case 6:deleteFront(&lobj);
			       break;
			case 7:deleteLast(&lobj);
			       break;
			case 8:printf("enter pos:");
				   scanf("%d",&pos);
				   deleteAtPos(&lobj,pos);
			       break;
			case 9:printf("enter the key:");
				   scanf("%d",&ele);
				   search(&lobj,ele);
				   break;
			case 10:reverseList(&lobj);
				    display(&lobj);
					break;
			case 11:delAlt(&lobj);
					display(&lobj);
					break;
		}
	}while(ch);
	return 0;
}