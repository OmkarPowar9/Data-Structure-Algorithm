// Singly Linked List
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

        default:
            printf("No choice Entered!!!!!\n");
            break;
        }
    }

    return 0;
}