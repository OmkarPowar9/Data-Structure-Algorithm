// circular Singly linked list Using tail as Pointer

#include <stdio.h>
#include <stdlib.h>

// structure to create Node
struct Node
{
    int data;
    struct Node *next;
};

// Here we are declaring Pointers gobaly
struct Node *temp, *tail;

void create()
{

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data in List: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (tail == NULL)
    {
        tail = temp; // self Pointing, 1st node and it is tail also
        tail->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    // tail->next=head;
    // only code to change in CLL rest all same in SLL
    //  p->next=head;
    printf("Node Created SuccessFully!!!!\n");
}
// insert at beginning
void insertbegin()
{

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data to be inseted: ");
    scanf("%d", &temp->data);
    if (tail == NULL)
    {
        tail = temp;
        temp->next = tail; // self Pointing, 1st node and it is tail also
        return;
    }

    temp->next = tail->next;
    tail->next = temp;
    printf("Node Inserted successfully!!!\n");
}

int countnodes()
{
    int count = 0;
    if (tail == NULL)
        return 0;
    else
    {
        struct Node *p = tail->next;
        while (p != tail)
        {
            p = p->next;
            count++;
        }
        count++;
        return count;
    }
}

// Display Function
void display()
{
    struct Node *p = tail->next;
    ;
    if (tail->next == NULL)
    {
        printf("The LINKED LIST IS EMPTY\n");
        return;
    }
    do
    {
        printf("%d\n", p->data);
        p = p->next;
    } while (p != tail);
    printf("%d\n", p->data);
}

// insert at End
void insertatend()
{

    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data to Inserted:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (tail == NULL)
    {
        tail = temp;
        tail->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    printf("Node Inserted successfully\n");
}
// Insertion At Position
void insertatpos()
{
    int pos;
    int c = countnodes();
    printf("Enter The Position to Insert:");
    scanf("%d", &pos);
    if (pos > c || pos < 0)
    {
        printf("Invalid pos\n");
        return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data to be Inserted:");
    scanf("%d", &temp->data);
    if (pos == 0)
    {
        if (tail == NULL)
        {
            tail = temp;
            temp->next = tail; // self Pointing, 1st node and it is tail also
            return;
        }
        else
        {
            temp->next = tail->next;
            tail->next = temp;
            return;
        }
    }
    struct Node *p = tail->next, *q = NULL;
    for (int i = 0; i < pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->next = p;
    if (pos == c)
    {
        tail = temp;
    }
    printf("The Node is inserted!!!\n");
}

// Deleting the First Node
void deleteatbegin()
{
    struct Node *p;
    p = tail->next;
    if (tail == NULL)
    {
        printf("The list is empty\n");

        return;
    }
    else if (tail->next == tail)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        tail->next = p->next;
        free(p);
    }
    printf("The Node is deleted!!!!!\n");
}

// Deleting AT End
void deleteatend()
{
    
    if (tail->next == NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct Node *p = tail->next;
    if (p->next == p)
    {
        tail = NULL;
        free(p);
        return;
    }
    while (p->next != tail)
        p = p->next;
    p->next = tail->next;
    printf("%d\n", tail->data);
    free(tail);
    tail = p;

    printf("The Node has been deleted!!!!\n");
}

//Deleting At Position
void deleteatpos()
{
    int pos;
    struct Node*p=tail->next,*q=NULL;
    printf("Enter the Position:");
    scanf("%d",&pos);
    if(tail==NULL)
    {
        printf("Lis tis empty\n");
        return;
    }
    int c=countnodes();
    if(pos<0 || pos>c)
    {

        tail->next=p->next;
        printf("%d\n",p->data);
        if(p->next==p)
        tail=NULL;
        free(p);
        return;
    }
    for(int i=0;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    if((pos+1)==c)
    tail=q;
    free(p);

    printf("The Given Node is Deleted!!!!!!\n");

}

//Searching 
void search()
{
    int data;
    int counter=0;
    printf("Enter Data to be searched:");
    scanf("%d",&data);

    if(tail==NULL)
    {
        printf("Linked list is NULL:\n");
        return;
    }
    else{
        struct Node *p=tail->next;
        while(p->data != data && p->next !=NULL)
        {
            counter +=1;
            p=p->next;
        }
        if(p->data == data)
        {
            printf("%d found at %d \n",data,counter);

        }
        else
        {
            printf("404\n");

        }

    }

    printf("Linked List: ");
    struct Node *p=tail->next;
    while(p !=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");


}
int main()
{
    int choice;

    while (1)
    {
        printf("\n------------------------------------\n");
        printf("0.Create a Circular Linked List!\n");
        printf("1.Display the Linked List!!\n");
        printf("2.INSERT AT BEGIN:\n");
        printf("3.INSERTION AT END:\n");
        printf("4.INSERTION AT ANY POSITION:\n");
        printf("5.DELETING AT BEGINNING:\n");
        printf("6.DELETION AT END\n");
        printf("7.DELETION AT ANY POSITION\n");
        printf("8.SEARCHING THE GIVEN NODE IN LIST(won't work)\n");
        printf("\n------------------------------------\n");

        printf("Enter the choice: ");
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
            insertbegin();
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
        
        case 8:
            search();
            break;

        default:
            printf("No choice Entered!!!!!");
            break;
        }
    }

    return 0;
}