#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void slltraversal(struct Node * ptr)
{
    while(ptr!=NULL)
    {
    printf("Element data%d \n",ptr->data);
    ptr=ptr->next;
    }
}


int main()
{
   struct Node * head;
   struct Node * second;
   struct Node * thrid;


   //allocate the memory for the Linked list in heap
   head=(struct Node *)malloc(sizeof(struct Node));
   second=(struct Node *)malloc(sizeof(struct Node));
   thrid=(struct Node *)malloc(sizeof(struct Node));

   //Link 1st and 2nd node
   head->data=7;
   head->next=second;

   //Link second and thrid nodes
   second->data=11;
   second->next=thrid;

   //Terminate the list at the thrid node
   thrid->data=66;
   thrid->next=NULL;

   slltraversal(head);




   return 0;   
}