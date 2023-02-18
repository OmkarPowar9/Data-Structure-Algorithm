// Singly Linked List
// CASE:01:INSERTION AT BEGINNING
// CASE:02:DISPLAYING OF DLL
// CASE:03:INSERTION AT END
// CASE:04:INSERTION AT GIVEN POSITION
// CASE:05:COUNT THE NUM OF NODES
// CASE:06:DELETION AT BEGIN
// CASE:06:DELETION AT END
// CASE:06:DELETION AT ANY POSTIION
// CASE:07:REVERSE THE LIST
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL, *temp;

void create()
{

    struct Node *p = head;

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data in Node:");
    scanf("%d", &temp->data);
    // printf("%d",temp->data);
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }

    printf("Node is Inserted!!!!!!!");
}

void display()
{

    printf("The Linked List is:\n");
    if (head == NULL)
    {
        printf("The List is Empty!!!!");
        return;
    }

    else
    {
        struct Node *p = head;
        while (p != NULL)
        {
            printf("%d \n", p->data);
            p = p->next;
        }

        printf("\n");
    }
}

int count()
{
    int count = 0;
    struct Node *p = head;

    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    // count++;
    // printf("The Number of nodes are:%d", count);
    return count;
}

// insertatbegin
void insertatbegin()
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data:");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    printf("THE NODE IS INSERTED!!!!!\n");
}
// InsertAtEnd
void insertend()
{
    struct Node *p = head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d", &temp->data);
    temp->next = NULL;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;

    printf("The Node is Inserted!!!!");
}

// Insertion at Position
void insertatpos()
{
    int pos, i;
    int c = count();
    struct Node *p = head;
    printf("Enter the Position to insert Node:");
    scanf("%d", &pos);
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data:");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (pos > c || pos < 0)
    {
        printf("Invalid Position!!!!\n");
        return;
    }
    else
    {
        for (i = 0; i < pos; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    printf("THE NODE IS INSERTED!!!!\n");
}
// DEletion of Node
void deleteatbegin()
{
    struct Node *p = head;
    if (head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        head = head->next;
        free(p);
    }
    printf("The Node is deleted!!!");
}

// Delete at end
void deleteatend()
{
    struct Node *p = head, *prev;
    while (p->next != 0)
    {
        prev = p;
        p = p->next;
    }
    if (p == head)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    free(p);
    printf("The Node has been Deleted\n");
}

// Delete at pos
void deleteatpos()
{

    struct Node *p = head;
    int pos, i;
    printf("Enter the Position to be delete:");
    scanf("%d", &pos);

    if (pos == 0)
    {
        head = head->next;
        p->next = NULL;
        free(p);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        struct Node *del = p->next;
        p->next = p->next->next;
        del->next = NULL;
        free(del);
    }

    printf("The Given node is Deleted!!!\n");
}
// Reversing Of Linked List
void reverse()
{
    struct Node *p = NULL, *c = head, *n = NULL;
    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    printf("The Linked List is Reversed\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--------------------------------\n");
        printf("0.CREATE A SINGLY LINKED LIST:\n");
        printf("1.DISPLAY THE LIST:\n");
        printf("2.COUNT THE NO OF NODES:\n");
        printf("3.INSERT AT BEGIN\n");
        printf("4.INSERT AT END \n");
        printf("5.INSERT AT ANY POSITION\n");
        printf("6.DELETION AT BEGINING:\n");
        printf("7.DELITION AT END\n");
        printf("8.Deletion At Position\n");
        printf("9.REVERSE THE LINKED LIST\n");
        printf("\n---------------------------------\n");

        printf("Enter Your choice:");
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
            count();
            break;
        case 3:
            insertatbegin();
            break;
        case 4:
            insertend();
            break;

        case 5:
            insertatpos();
            break;

        case 6:
            deleteatbegin();
            break;

        case 7:
            deleteatend();
            break;

        case 8:
            deleteatpos();
            break;

        case 9:
            reverse();
            break;

        default:
            printf("No choice Entered!!!!!\n");
            break;
        }
    }

    return 0;
}