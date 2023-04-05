#include<stdio.h>
#define MAX 5
typedef struct priq
{
	int info;
	int pri;
}PRIQ;
void insert(PRIQ *pq,int ele,int pri,int *count)
{
	int j=(*count)-1;
	PRIQ key;
	key.info=ele;
	key.pri=pri;
	while(j>=0 && key.pri > pq[j].pri)
	{
		pq[j+1]=pq[j];
		j--;
	}
	pq[j+1]=key;
	(*count)++;
}
PRIQ maxdelete(PRIQ *pq, int *count)
{
	PRIQ key=pq[0];
	for(int i=1;i<*count;i++)
		pq[i-1]=pq[i];
	(*count)--;
	return key;
}
void display(PRIQ *pq,int *count)
{
	if(*count==0)
	{
		printf("queue is empty\n");
		return; 
	}
	for(int i=0;i<(*count);i++)
	{
		printf("data:%d Pri:%d|",pq[i].info,pq[i].pri);
	}
}
int main()
{
	PRIQ pq[MAX],temp;
	int ch,count=0;
	int ele,pri;
	
	printf("1.Enqueue 2.Maxdequeue 3.display\n");
	scanf("%d",&ch);
	do
	{
		switch(ch)
		{
			case 1:if(count!=MAX)
				   {
					printf("enter the ele and priority:");
					scanf("%d %d",&ele,&pri);
					insert(pq,ele,pri,&count);
				   }
				   else
					   printf("queue overflow\n");
				   break; 
			case 2:if(count!=0)
					{
						temp=maxdelete(pq,&count);
						printf("data:%d pri:%d",temp.info,temp.pri);
					}
				   else
					   printf("queue undeflow");
				   break;
			case 3:display(pq,&count);
					break;	   
		}
		printf("\n1.Enqueue 2.Maxdequeue 3.dispalay\n");
		scanf("%d",&ch);
	}while(ch<4);
	return 0;
}