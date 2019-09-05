#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node* node;
node create()
{
    node temp;
    temp=(node)malloc(sizeof(struct node));
    temp->right=temp->left=NULL;
    return temp;
}
node insert(node head,int data)
{
    node temp;
    temp = create();
    temp->data = data;
    if(head == NULL) 
    {
        head = temp;
    }
    else if(data > (head->data))
    {
        head->right=insert(head->right,data);        
    }
    else if(data < (head->data)) 
    {
        head->left=insert(head->left,data);
    }
    return head;
}
node delete(node head)
{
    node temp,p;
    if(head==NULL) printf("The tree is empty\n");
}
void inorder(node head)
{
    if(head==NULL) return;
    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
}
void postorder(node head)
{
    if(head==NULL) return;
    printf("%d ",head->data);
    postorder(head->left);
    postorder(head->right);
}
void preorder(node head)
{
    if(head==NULL) return;
    preorder(head->left);
    preorder(head->right);
    printf("%d ",head->data);
}
int main()
{
    node head;
    head = insert(head,1);
    head = insert(head,2);
    inorder(head);
    printf("\n");
    postorder(head);
    printf("\n");
    preorder(head);
}