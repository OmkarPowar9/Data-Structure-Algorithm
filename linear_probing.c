//Chapter 5:Hashing Trie (Linear probing)
#include<stdio.h>
#include<string.h>
#define size 7

typedef struct student
{
int Rno;
char name[30];
int mark;
}NODE;

void initTable(NODE ht[size],int *n)
{
	for(int i=0;i<size;i++)
		ht[i].mark=0;
	(*n)=0;
}
int insert(NODE ht[size],int Rno,char name[30],int *n)
{
	if(*n==size)
		return 0;
	int index=Rno%size;
	while(ht[index].mark!=0)
		index=(index+1)%size;
	ht[index].Rno=Rno;
	strcpy(ht[index].name,name);
	ht[index].mark=1;
	(*n)++;
	return 1;
}
int delete(NODE ht[size],int Rno,int *n)
{
	if(*n==0)
		return 0;
	int index=Rno%size;
	int i=1;
	while(ht[index].Rno!=Rno && i<*n)
	{
		index=(index+1)%size;
		if(ht[index].mark==1)
			i++;
	}
	if(ht[index].Rno==Rno && ht[index].mark==1)
	{
		ht[index].mark=0;
		(*n)--;
		return 1;
	}
	return 0;			
}
int search(NODE ht[size],int Rno,char name[30],int n)
{
	if(n==0)
		return 0;
	int index=Rno%size;
	int i=1;
	while(ht[index].Rno!=Rno && i<n)
	{
		index=(index+1)%size;
		if(ht[index].mark==1)
			i++;
	}
	if(ht[index].Rno==Rno && ht[index].mark==1)
	{
		strcpy(ht[index].name,name);
		return 1;
	}
	return 0;	
}
void display(NODE ht[size],int n)
{
	if(n==0)
	{
		printf("Empty hash Table\n");
		return;
	}
	for(int i=0;i<size;i++)
	{
		if(ht[i].mark==1)
			printf("ht[%d]:%d %s\n",i,ht[i].Rno,ht[i].name);
		else
			printf("ht[%d]:\n",i);
	}
}

int main()
{
	int n=0;
	NODE ht[size];
	initTable(ht,&n);
	
	int choice,Rno;
	char name[30];
	printf("1.INSERT  2.DELETE  3.SEARCH  4.DISPLAY  5.EXIT\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:printf("enter the Rno:");
				   scanf("%d",&Rno);
				   printf("\nenter name:");
				   scanf("%s",name);
				   if(!insert(ht,Rno,name,&n))
					   printf("Table full, cannot insert\n");
				   break;
			case 2:printf("enter the Rno:");
				   scanf("%d",&Rno);
				   if(delete(ht,Rno,&n))
					   printf("record with Rno %d is deleted",Rno);
				   else
					   printf("record not found");
				   break;
			case 3:printf("enter the Rno:");
				   scanf("%d",&Rno);
				   if(search(ht,Rno,name,n))
					   printf("Record found:Details %d %s\n",Rno,name);
				   else
					   printf("record not found");
				   break;
			case 4:display(ht,n);
			       break;
			case 5:return 0;	
		}
		printf("1.INSERT  2.DELETE  3.SEARCH  4.DISPLAY  5.EXIT\n");
		scanf("%d",&choice);
	}while(choice<6);
}