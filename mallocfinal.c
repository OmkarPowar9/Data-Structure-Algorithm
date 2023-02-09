#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct llist
{
    NODE *head;
} LLIST;

void initList(LLIST *);
void insertFront(LLIST *, int);
void insertLast(LLIST *, int);
void insertAtPos(LLIST *, int, int);
void display(LLIST *);
void destroyList(LLIST *);
void deleteFront(LLIST *);
void deleteLast(LLIST *);
void deleteAtpos(LLIST *,int);
void search(LLIST *,int);
void deletealt(LLIST *,int);
// sll-singly linked list

void initList(LLIST *sll)
{
    sll->head = NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->next = NULL;
    return temp;
}

void insertFront(LLIST *sll, int ele)
{
    NODE *temp = getNode(ele);
    temp->next = sll->head;
    sll->head = temp;
}
void insertLast(LLIST *sll, int ele)
{
    NODE *temp = getNode(ele);
    if (sll->head == NULL)
    {
        sll->head = temp;
        return;
    }
    NODE *p = sll->head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
}
int countnodes(LLIST *sll)
{
    int count = 0;
    if (sll->head == NULL)
        return 0;
    NODE *p = sll->head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void insertAtPos(LLIST *sll, int ele, int pos)
{
    // int n=countnodes(sll);
    NODE *temp = getNode(ele);
    if (pos == 0)
    {
        temp->next = sll->head;
        sll->head = temp;
        return;
    }
    NODE *p = sll->head, *q = NULL;
    for (int i = 1; i < pos; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->next = p;
}
void display(LLIST *sll)
{
    if (sll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE *p = sll->head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}
void destroyList(LLIST *sll)
{
    NODE *p = sll->head;
    while (p != NULL)
    {
        NODE *q = p;
        printf("%d\n", p->data);
        p = p->next;
        free(q);
    }
    sll->head = NULL;
}
void deleteFront(LLIST *sll)
{
    NODE *p = sll->head;
    sll->head = p->next;
    printf("%d\n", p->data);
    free(p);
}
void deleteLast(LLIST *sll)
{
    NODE *p = sll->head;
    if(sll->head == NULL)
    return NULL;
    
    if(sll->head == NULL){
        free(sll->head);

    }
    
    while(p->next->next !=NULL)
    p=p->next;

    free(p->next);
}
void deleteAtpos(LLIST *sll, int pos)
{
    NODE *p = sll->head, *q = NULL;
    int i;
    if (pos == 0)
    {
        sll->head = p->next;
        printf("%d",p->data);
        free(p);
        return;
    }

   else
    {  
        for(i=0;i < pos; i++)
        printf("");



    }
}
void search(LLIST *sll,int key)
{
    NODE *p = sll->head;
    int pos=0;
    while(p->data!=key && p->next!=NULL)
    {
        p=p->next;
        pos ++;

    }
    if(p->data==key)
    {
        printf("The element is found at %d",pos);
    }
    else
     printf("the element is not found");

    
}
void reverseList(LLIST *sll)
{ 
    NODE *p = sll->head;
    if(sll->head == NULL && sll->head ->next == NULL)
    {
        printf("*head is NULL \n");
    }
    //prev element pointer
    struct NODE *prev =sll->head;

    //curr element pointer
    struct NODE *curr =sll->head->next;
    sll->head =NULL;

    while(prev !=NULL && curr !=NULL)
    {
        struct NODE *next = curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    printf("LinkedList:");
    struct NODE *ptr = prev;
    while(ptr !=NULL)//start from first node
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");




}
/**void deleteAlt(LLIST * sll)
NODE *p=NULL,
{
    p=c;
    c=c->next;
    p->next=c->next;
    free(c);
    c=p->next;

}**/
int main()
{
    LLIST lobj;
    initList(&lobj);
    int choice, ele, pos,key;

    do
    {
        printf("1.Insert Front\n 2. Insert Last\n 3.Insert at pos\n 4.display\n 5.destroy\n 6.DeleteFront\n");
        printf("enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter an integer\n");
            scanf("%d", &ele);
            insertFront(&lobj, ele);
            break;
        case 2:
            printf("enter an integer\n");
            scanf("%d", &ele);
            insertLast(&lobj, ele);
            break;
        case 3:
            printf("enter an integer\n");
            scanf("%d", &ele);
            printf("enter the pos:");
            scanf("%d", &pos);
            insertAtPos(&lobj, ele, pos);
            break;
        case 4:
            display(&lobj);
            break;
        case 5:
            destroyList(&lobj);
            break;
        case 6:
            deleteFront(&lobj);
            break;
        case 7:
            deleteLast(&lobj);
            break;
        case 8:
            printf("enter pos:");
            scanf("%d", &pos);
            deleteAtpos(&lobj, pos);
            break;
        case 9:
            printf("enter the Key to searched :");
            scanf("%d", &key);
            search(&lobj,key);
            break;
        }
    } while (choice);
    /// destroyList(&lobj);
    return 0;
}