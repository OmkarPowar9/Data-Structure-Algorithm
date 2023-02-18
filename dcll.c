// Doubley Circular Linked list
// CASE:01:INSERTION AT BEGINNING
// CASE:02:DISPLAYING OF DLL
// CASE:03:INSERTION AT END
// CASE:04:INSERTION AT GIVEN POSITION
// CASE:05:COUNT THE NUM OF NODES
// CASE:06:DELETION AT BEGIN
// CASE:06:DELETION AT END
// CASE:06:DELETION AT ANY POSTIION
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head, *tail;

// Creating Doubly circular linked list
void create()
{
    struct Node *temp;
    head = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The data:");
    scanf("%d", &temp->data);

    if (head == NULL)
    {
        head = tail = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        temp->next = head;
        head->prev = temp;
        tail = temp;
    }
    printf("The Node is Inserted!!!!");
}

// Display
void display()
{
    struct Node *p = head;
    printf("The Linked List is:\n");
    if (head == NULL)
    {
        printf("The List is Empty!!!!!");
    }
    else
    {
        while (p != tail)
        {
            printf("%d \n", p->data);
            p = p->next;
        }
        printf("%d", p->data);
    }
}

// Inserition at Beginning
void insertatbegin()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        head = tail = temp; // Only 1 node in list so pointing the tail and head to itself
        temp->prev = tail;
        temp->next = head;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = tail;
        tail->next = temp;
        head = temp;
    }
    printf("The Given Node is inserted!!!!!");
}

// Insertion at End

void insertatend()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data:");
    scanf("%d", &temp->data);

    if (head == NULL)
    {
        head = tail = temp;
        temp->prev = tail;
        temp->next = head;
    }

    else
    {
        temp->prev = tail;
        tail->next = temp;
        temp->next = head;
        head->prev = temp;
        tail = temp;
    }

    printf("The Given Node is inserted!!!!!\n");
}

// INSERTION AT ANY POSTIION

void insertatpos()
{
    struct Node *temp, *p = head;
    int pos, i = 1;

    printf("Enter the Position:");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertatbegin();
    }

    else
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the Data:");
        scanf("%d", &temp->data);
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        temp->prev = p;
        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
    }
    printf("The Given node is Inserted!!!!!\n");
}

// Deletion
void deleteatbegin()
{
    struct Node *q;
    q = head;
    if (head == 0)
    {
        printf("The list is empty!!!!\n");
    }
    else if (head->next == head)
    {
        head = tail = NULL; /*If only 1 node is there then,the Head and tail is
                             pointing to single node then turn them to NULL and free the p*/
        free(q);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    free(q);
    printf("The Given node is deleted!!!!");
}

// Deletion at end
void deleteatend()
{
    struct Node *q;
    q = tail;
    if (tail == NULL)
    {
        printf("The list is Empty\n");
    }
    else if (tail->prev == tail)
    {
        head = tail = NULL;
        free(q);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(q);
    }
    printf("The Given List is Deleted!!!!!\n");
}
// Deletion At ANY Position
void deleteatpos()
{
    struct Node *p = head;
    int pos, i = 1;

    printf("Enter the Position:");
    scanf("%d", &pos);

    if (pos == 1)
    {
        deleteatbegin();
    }

    else
    {
        while (i < pos)
        {
            p = p->next;
            i++;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;

        if (p->next == head)
        {
            tail = p->prev;
            free(p);
        }
        else
        {
            free(p);
        }
    }
    printf("The Given Node is Delelted!!!!!\n");
}
int main()
{
    int choice;

    while (1)
    {
        printf("\n------------------------------------\n");
        printf("0.CREATE A DOUBLY CIRCULAR LINKED LIST\n");
        printf("1.DISPLAY\n");
        printf("2.INSERITION AT BEGIN\n");
        printf("3.INSERTION AT END\n");
        printf("4.INSERTION AT ANY POSITION\n");
        printf("5.Deletion At Beginning\n");
        printf("6.Deletion At END \n");
        printf("7.Deletion At any Position\n");
        printf("\n-------------------------------------\n");

        printf("Enter Your Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            create();
            break;

        case 1:
            display();
            break;

        case 2:
            insertatbegin();
            break;

        case 3:
            insertatend();
            break;

        case 4:
            insertatpos();
            break;

        case 5:
            deleteatbegin();
            break;

        case 6:
            deleteatend();
            break;

        case 7:
            deleteatpos();
            break;

        default:
            break;
        }
    }

    return 0;
}
