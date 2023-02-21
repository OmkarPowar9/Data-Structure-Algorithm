#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push()
{
    int x;
    printf("Enter data:");
    scanf("%d", &x);

    if (top == N - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("UnderFlow\n");
    }
    else
    {
        item = stack[top];
        top--;

        printf("%d\n", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d \n", stack[i]);
    }
    printf("\n");
}

void isempty()
{
    if (top == -1)
    {
        printf("Stack is empty:Underflow State\n");
        return;
    }
    printf("Stack is not empty!!!!!\n");
}

void isfull()
{
    if (top == N - 1)
    {
        printf("Stack is Full:Overflow state\n");
        return;
    }
    printf("Stack is Not Full!!!!\n");
    return;
}

void main()
{
    int choice;

    while (1)
    {
        printf("------------------\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Isempty\n");
        printf("6.Isfull\n");

        printf("------------------\n");

        printf("Enter Your Choice:");
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
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            isempty();
            break;

        case 6:
            isfull();
            break;

        default:
            break;
        }
    }
}