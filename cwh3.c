// This is code is to implement Deletion of Singly Linked list
// CASE: 01 DELETION AT THE BEGINNING
// CASE: 02 DELETION IN BETWEEN
// CASE: 03 DELETION AT THE END
// CASE: 04 DELETION AT A NODE

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void slltraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element Data:%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteatindex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

struct Node *deleteatend(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

struct Node *deleteatnode(struct Node *head,int value)
{ 
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!= value && q->next !=NULL)
    { 
        p=p->next;
        q=q->next;

    }
     if(q->data == value)
     {
        p->next=q->next;
        free(q);
     }

return head;
}



int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *thrid;
    struct Node *fourth;
    struct Node *fivth;

    // allocate the memory for the Linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    thrid = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fivth = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st and 2nd node
    head->data = 3;
    head->next = second;

    // Link second and thrid nodes
    second->data = 8;
    second->next = thrid;

    // Terminate the list at the thrid node
    thrid->data = 1;
    thrid->next = fourth;

    fourth->data = 5;
    fourth->next = fivth;

    fivth->data = 6;
    fivth->next = NULL;

    printf("Linked List before Deletion:\n");
    slltraversal(head);

    // head = deletefirst(head); //FOR Deleting First element of the linked list
    // head = deleteatindex(head, 4);
    //head = deleteatend(head);
    head=deleteatnode(head,1);
    printf("Linked List After Deletion:\n");
    slltraversal(head);

    return 0;
}