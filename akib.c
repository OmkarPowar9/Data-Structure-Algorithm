#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// creating head;
struct Node *head = NULL;

void create()
{
    struct Node *temp;
    // creating new Node
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Node data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp; // inserting at end of List
    }
}
// prints the entire LinkedList
void display()
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    printf("LinkedList: ");
    struct Node *ptr = head;
    while (ptr != NULL) // start from first Node
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
// to insert Node at start of LinkedList
void insert_begin()
{
    struct Node *temp;
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;


}
// to insert Node at given position
void insertAtPos()
{
    struct Node *temp;
    // creating a new Node
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Node data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL) // if list empty we return
    {
        head = temp;
        return;
    }
    else
    {
        struct Node *prev_ptr;
        struct Node *ptr = head;
        int pos;
        printf("Enter position: ");
        scanf("%d", &pos);
        for (int i = 0; i < pos; i++)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        // new Node pointing to Node in that pos
        temp->next = ptr;
        // prevptr pointing to new Node
        prev_ptr->next = temp;
    }
}

void deleteBegin()
{
    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete \n");
        return;
    }
    else
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        printf("Node Deleted \n");
    }
}

void deleteLast()
{

    if (head == NULL)
    {
        printf("Linked List is empty | Nothing to delete \n");
        return;
    }
    else if (head->next == NULL)
    {
        struct Node *ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else
    {

        struct Node *ptr = head;
        struct Node *prev_ptr = NULL;
        while (ptr->next != NULL)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
        printf("Node Deleted \n");
    }
}

void delete_pos()
{
    int pos;
    printf("Enter node position to delete: ");
    scanf("%d", &pos);
    struct Node *ptr = head;
    if (head == NULL) // we return if List is empty
    {
        printf("Linked List is empty \n");
        return;
    }
    else if (pos == 0)
    {
        ptr = head;
        head = ptr->next; // head pointing to second node
        free(ptr);        // deleting old first node
    }
    else
    {
        struct Node *prev_ptr;
        for (int i = 0; i < pos; i++)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next; // prev node pointing to pos+1 node
        free(ptr);                  // deleting node at pos
    }
}

void search()
{

    int data;
    int counter = 0;
    printf("enter a data to find : ");
    scanf("%d", &data);

    if (head == NULL)
    {
        printf("Linked list is NULL : \n");
        return;
    }
    else
    {
        struct Node *ptr = head;

        while (ptr->data != data && ptr->next != NULL)
        {
            counter += 1;
            ptr = ptr->next;
        }

        if (ptr->data == data)
        {
            printf("%d found at %d \n", data, counter);
        }
        else
        {
            printf("404\n");
        }
    }

    printf("LinkedList: ");
    struct Node *ptr = head;
    while (ptr != NULL) // start from first Node
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverse()
{
    if (head == NULL && head->next == NULL)
    {
        printf("head is null \n");
    }

    // prev element pointer
    struct Node *prev = head;

    // curr element pointer
    struct Node *curr = head->next;

    head->next = NULL;

    while (prev != NULL && curr != NULL)
    {
        struct Node *next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    
    printf("LinkedList: ");
    struct Node *ptr = prev;
    while (ptr != NULL) // start from first Node
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

}

int main()
{

    int choice;
    while (1)
    {
        printf("------------------------------ \n");
        printf("0. Create\n");
        printf("1. display\n");
        printf("2. Insert Node at position \n");
        printf("3. Delete Node at Begin \n");
        printf("4. Delete Node at end \n");
        printf("5. Detele Node at pos \n");
        printf("6. search element in LinkedList \n");
        printf("7. reverse Linkedlist  \n");
        printf("8.Insert At Begining");
        printf("9. to exit \n");
        printf("------------------------------ \n");

        printf("\n Enter your choice: ");
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
            insertAtPos();
            break;
        case 3:
            deleteBegin();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            delete_pos();
            break;
        case 6:
            search();
            break;
        case 7:
            reverse();
            break;
        case 8:
            insert_begin();
            break;
        case 9:
            printf("=========Exit========== \n");
            exit(0);
            break;
        default:
            printf("No choice found ! : \n");
            break;
        }
    }

    free(head);
    return 0;
}