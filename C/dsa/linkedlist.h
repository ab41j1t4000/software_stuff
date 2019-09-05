#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node* node;
node create()
{
    node temp;
    temp = (node)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}
node insert(node head,int value)
{
    node temp,p;
    temp = create();
    temp->data = value;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next!=NULL)
        {
            p=p->next;
        }
        p->next = temp;
    }
    return head;
}
node print(node head)
{
    node p;
    if(head == NULL) printf("The head is NULL\n");
    else {
        p = head;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p = p->next;
        }
    }
}
node delete(node head,int pos)
{
    node p,temp;
    if (head == NULL) printf("List is empty\n");
    else
    {
        p = head;
        for (int i = 0;i <pos-1;i++)
        {
            if(p!=NULL) p = p->next;
            else printf("Index out of range\n");
        }
        temp = p->next;
        p->next = temp->next;
        p=p->next;
        temp->next = NULL;
    }
    return head;
}