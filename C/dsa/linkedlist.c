#include<stdio.h>
#include "linkedlist.h"
int main()
{
    node head;
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,4);
    print(head);
    printf("\n");
    head = delete(head,1);
    print(head);
}