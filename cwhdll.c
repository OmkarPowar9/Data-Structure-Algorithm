// DOUBLY LINKED LIST
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
    struct Node *prev;
    struct Node *next;
};

struct Node *head, *temp, *tail;

void create()
{
    head = NULL;
    struct Node *p;
    // int choice = 1;
    temp = (struct Node *)malloc(sizeof(struct Node));
    // while(choice)
    // {
    printf("Enter the data in the Linked List:");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    if (head == 0)
    {
        head = p = tail = temp;
    }
    else
    {
        p->next = temp;
        p->prev = temp;
        p = temp;
        // tail->next = temp;
        // temp->prev = tail;
        // tail = temp;
    }

    //  printf("Do YOU WANT TO CONTINUE:");
    //  scanf("%d",&choice);
    //  }
}

void display()
{

    if (head == NULL)
    {
        printf("The LINKED LIST IS EMPTY\n");
        return;
    }
    struct Node *p = head;
    printf("The LINKED LIST IS:\n");
    while (p != NULL)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
    printf("\n");
}
// counting Num of Nodes for inserting at position
int getcount()
{
    int count = 0;
    struct Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    return count;
}

// InsertatBegining
void insertatbegin()
{

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The Data to be Inserted:");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    head->prev = temp;
    temp->next = head;
    head = temp;

    // tail=tail->next;
}

// Insertatend
void insertatend()
{
    struct Node *p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The Data to be Inserted:");
    scanf("%d", &temp->data);
    if (head == NULL)
    {
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        head = p;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
        temp->next = NULL;
    }
    printf("The Node is inserted!!!!");

    // Not Working!!!!!!!!!!!!
}

// InsertatPosition
void insertatpos()
{
    int pos, i;

    printf("Enter the position:");
    scanf("%d", &pos);

    if (pos == 0)
    {
        insertatbegin();
    }
    else
    {
        struct Node *p = head;
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter The Data to be Inserted:");
        scanf("%d", &temp->data);
        temp->prev = NULL;
        temp->next = NULL;

        for (i = 0; i < pos; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("Can't Insert\n");
                return;
            }
        }
        temp->next = p->next;
        temp->prev = p;
        p->next = temp;
        p->next->prev = temp;
        printf("Node has been Inserted:\n");
    }
    // tail=tail++;
}

// DELETION PROCESS
// DELETION AT BEGINING
void deleteatbegin()
{
    struct Node *p;
    if (head == NULL)
    {
        printf("The list is Empty!!!!\n");
        return;
    }

    else
    {
        p = head;
        head = head->next;
        head->prev = NULL;
        free(p);
    }
    printf("The Node is Deleted!!!\n");
}
// DELETION AT ENDNODE
void deleteatend()
{
    struct Node *p;
    if (head == NULL)
    {
        printf("The List is Empty!!!\n");
        return;
    }
    // else if (head->next == NULL)
    // {
    //     head = NULL;
    //     free(head);
    //     printf("The Node is Deleted!!!!\n");
    // }
    else
    {
        p = head;
        if (p->next != NULL)
        {
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
        printf("The Node is BEEN Deleted!!!\n");
    }
}

// DELEITION OF NODE AT GIVEN POSITION
void deleteatpos()
{
    struct Node *p;

    int pos, i;

    printf("Enter the Position:");
    scanf("%d", &pos);
    p = head;
    if (pos == 0)
    {
        deleteatbegin();
        return;
    }

    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("The Node is Deleted!!!!\n");
    }

    else
    {
        for (i = 0; i < pos; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                deleteatend();
                return;
            }
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);

        printf("The Node has been deleted!!!!!!\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n------------------------------------\n");
        printf("0.Create an Doubly Linked List!!\n");
        printf("1.Display the Linked List!!\n");
        printf("2.INSERT AT BEGIN:\n");
        printf("3.Insert AT END(wont work):\n");
        printf("4.Get NUM of Nodes in LIst:\n");
        printf("5.Insert At any Position:\n");
        printf("6.Delete At Beginning\n");
        printf("7.Delete At End\n");
        printf("8.Delete At Any Position:\n");
        printf("------------------------------------\n");

        printf("Enter the choice:");
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
            printf("count of NUM of Nodes:%d\n", getcount());
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

        default:
            printf("NO choice Entered:");
            break;
        }
    }

    return 0;
}