// Implementation of Queue using Arrays
#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("OverFlow!!!!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("The Element is added in queue\n");
    }
    else
    {
        rear++;
        queue[rear] = x;
        printf("The Element is added in queue\n");
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("UnderFlow!!!!\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("The Element gone be deleted is:%d\n", queue[front]);
        front++;
    }
    // printf("The Element gone be deleted\n");
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("The Queue is empty!!!!\n");
    }
    else
    {
        printf("The Queue Elements are:\n");
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d|", queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!!!!\n");
    }
    else
    {
        printf("%d\n", queue[front]);
    }
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("---------------------\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Peak\n");
        printf("---------------------\n");

        printf("Enter Your Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data to Insert:");
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