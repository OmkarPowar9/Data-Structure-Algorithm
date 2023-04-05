#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit
#define max 6
typedef struct node
{
    char info;
    struct node *left, *right;

}NODE;
typedef struct tree
{
    NODE *root;
}TREE;
typedef struct stack
{
    NODE *s[max];
    int top;
}STACK;
void initTree(TREE *pt)
{
    pt->root = NULL;
}
void initStack(STACK *ps)
{
    ps->top = -1;
}
int push(STACK *ps, NODE *e)
{
    if (ps->top == max - 1)
        return 0;
    ps->top++;
    ps->s[ps->top] = e;
    return 1;
}
NODE* pop(STACK *ps)
{
    NODE *t = ps->s[ps->top];
    ps->top--;
    return t;
}

float eval(NODE *r)
{
    float res;
    switch (r->info)
    {
    case '+':
        res = eval(r->left) + eval(r->right);
        break;
    case '-':
        res = eval(r->left) - eval(r->right);
        break;
    case '*':
        res = eval(r->left) * eval(r->right);
        break;
    case '/':
        res = eval(r->left) / eval(r->right);
        break;
    default:
        return r->info - '0';
    }
    return res;
}
float eval_tree(TREE *pt)
{
    return eval(pt->root);
}
int main()
{
    char postfix[max];
    int i = 0;
    STACK sobj;
    TREE tobj;
    NODE *temp;
    initStack(&sobj);
    initTree(&tobj);
    printf("Enter the postfix expression");
    scanf("%s", postfix);
    while (postfix[i] != '\0')
    {
        temp = malloc(sizeof(NODE));
        temp->info = postfix[i];
        temp->left = NULL;
        temp->right = NULL;
        if (isdigit(postfix[i]))
            push(&sobj, temp);
        else
        {
            temp->right = pop(&sobj);
            temp->left = pop(&sobj);
            push(&sobj, temp);
        }
        i++;
    }
    tobj.root = pop(&sobj);
    printf("%f", eval_tree(&tobj));
    return 0;
}
