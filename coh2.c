// Insertion of Linked List
//  CASE: 01 INSERTION AT THE BEGINNING
//  CASE: 02 INSERTION IN BETWEEN
//  CASE: 03 INSERTION AT THE END
//  CASE: 04 INSERTION AT A NOSE

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
        printf("Element data:%d\n", ptr->data);
        ptr = ptr->next;
    }
    return;
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
}

struct Node *insertatindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertatend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *insertafternode(struct Node *head, struct Node *prevnode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr=head;
    ptr->data = data;

    

    ptr->next = prevnode->next;
    prevnode->next = ptr;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *thrid;

    // allocate the memory for the Linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    thrid = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st and 2nd node
    head->data = 7;
    head->next = second;

    // Link second and thrid nodes
    second->data = 11;
    second->next = thrid;

    // Terminate the list at the thrid node
    thrid->data = 66;
    thrid->next = NULL;

    // head = insertAtFirst(head, 56);
    //    head = insertatindex(head, 56, 2);
    //    printf("Linked list before insertion\n");
    //     slltraversal(head);
    //     printf("Linked list After insertion\n");
    //     insertatend(head, 99);
    //     slltraversal(head);

    printf("Linked List Before insertion:\n");
    slltraversal(head);

    head = insertafternode(head, second, 45);
    printf("Linked List After Insertion:\n");
    slltraversal(head);

    return 0;
}
