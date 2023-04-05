#include<stdio.h>
#include<stdlib.h>

struct dequeue
{
   struct node * front;
   struct node * rear;
};
struct node 
{
    int data;
    struct node * prev, *next;
};
struct dequeue dq;
void initdeque(struct dequeue *dq)
{
dq->front=dq->rear = NULL;
}
//insert in front of the queue
void qinsert_head(int x,struct dequeue *dq)
   {
     struct node *temp;

     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->prev=temp->next=NULL;

     if(dq->front==NULL) // first element
        dq->front=dq->rear=temp;
      else
       {
          temp->next=dq->front;  // insert in front
          dq->front->prev=temp;
          temp->prev=NULL;
          dq->front=temp;
       }
   }
//insert at the rear of the queue
void qinsert_tail(int x,struct dequeue* dq)
  {
    struct node *temp;

     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->prev=temp->next=NULL;

     if(dq->front==NULL)
        dq->front=dq->rear=temp;
      else
        {
          dq->rear->next=temp;
          temp->prev=dq->rear;
          dq->rear=temp;
        }
   }
//delete at the front of the queue
int qdelete_head(struct dequeue* dq)
  {
     struct node *q;
     int x;
     if(dq->front==NULL)
       return -1;
           
    q=dq->front;
     x=q->data;
    if(dq->front==dq->rear)//only one node
      dq->front=dq->rear=NULL;
    else
      {
        dq->front=dq->front->next;
        dq->front->prev=NULL;
      }
      free(q);
     return x;
   }
//delete at the rear of the queue
int  qdelete_tail(struct dequeue* dq)
  {
    struct node *q;
     int x;
     if(dq->front==NULL)
       return -1;
     q=dq->rear;
     x=q->data;
    if(dq->front==dq->rear)//only one node
      dq->front=dq->rear=NULL;
    else
     {
        dq->rear=dq->rear->prev;
        dq->rear->next=NULL;
      }
     free(q);
      return x;
   }
void display(struct dequeue *dq)
{
	struct node *temp=dq->front;
	if(dq->front==NULL)
       printf("queue empty");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
int main()
{
	struct dequeue dobj;
	int ch,ele;
	initdeque(&dobj);
	printf("1.insertfront \n 2.insertRear\n 3.DeleteFront\n 4. DeleteRear\n 5.Display\n");
	scanf("%d",&ch);
	do{
		switch(ch)
		{
			case 1:printf("enter the element:");
				   scanf("%d",&ele);
				   qinsert_head(ele,&dobj);
				   break;
			case 2:printf("enter the element:");
				   scanf("%d",&ele);
				   qinsert_tail(ele,&dobj);
				   break;
			case 3:ele=qdelete_head(&dobj);
					if(ele==-1)
						printf("queue underflow\n");
					else
						printf("%d deleted\n",ele);
			       break;
			case 4:ele=qdelete_tail(&dobj);
				   if(ele==-1)
						printf("queue underflow\n");
					else
						printf("%d deleted\n",ele);
				   break;
			case 5:display(&dobj);
			       break;
				   
		}
	printf("\n1.insertfront\n 2.insertRear\n 3.DeleteFront\n 4. DeleteRear\n 5.Display:\n");
	scanf("%d",&ch);
		
	}while(ch<6);
	return 0;
}