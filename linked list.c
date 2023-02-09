#include<stdio.h>
#include<stdlib.h>

void initlist(llist *);
void insertFront(llist*,int);
void insertLast(llist*,int);



typedef struct node{
    int data;
    struct node;
}NODE;

typedef struct llist{
    NODE*head;
}llist;

void initlist(llist *sll)
{
    sll->head=NULL;
}

NODE * getNode(int ele)
{

}