// Stack implemation using Linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node *temp, *top = NULL;

void push()
{
    int x;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data:");
    scanf("%d", &temp->data);
    if (top == NULL)
    {
        //temp->data=x;
        temp->link = NULL;
        top = temp;
    }
    else
    {
        //temp->data=x;
        temp->link = top;
        top = temp;
    }

    printf("The Element inserted in stack\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("The Stack Underflow!!!!!\n");
        return;
    }
    else
    {
        struct Node *q = top;
        top = top->link;
        printf("%d\n", q->data);
        free(q);
    }
    printf("The Element Poped in stack\n");
}

void display()
{
    struct Node *q = top;
    if (top == NULL)
    {
        printf("The Stack Underflow\n");
        return;
    }
    else
    {
        printf("The Stack Elements are:\n");
        while(q != NULL)
        {
            printf("%d \n",q->data);
            q= q->link;
        }
    }
    
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n------------------\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("\n------------------\n");

        printf("Enter Your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    }
}