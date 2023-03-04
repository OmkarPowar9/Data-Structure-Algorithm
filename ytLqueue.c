// Implemetation of queue in Linked list with dynamic allocation
// First in first out(FIFO)
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("The Node is inserted in queue!!\n");
}

void display()
{
    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty!!!\n");
    }
    else
    {
        temp = front;
        printf("The Queue Elements are:");
        while (temp != NULL)
        {
            printf("%d|", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty!!!!");
    }
    else
    {
        printf("The Element gone be deleted:%d", front->data);
        front = front->next;
        free(temp);
    }
    printf("\n");
}

void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d", front->data);
    }
    printf("\n");
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("------------------\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Peek\n");
        printf("------------------\n");

        printf("Enter the choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter The Data:");
            scanf("%d", &item);
            enqueue(item);

            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        default:
            break;
        }
    }
}