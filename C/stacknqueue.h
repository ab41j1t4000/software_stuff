#include <stdio.h>
#include<stdbool.h>
struct stack{
int value[100];
int top; 
int MAX_SIZE;
};
bool isempty(struct stack *s)
{
    if(s->top == -1) return true;
    else return false;
}
bool isfull(struct stack *s)
{
    if (s->top == s->MAX_SIZE-1) return true;
    else return false;
}
int pop(struct stack *s)
{
    if (isempty(s))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("%d\n",s->value[s->top]);
        s->top--;
        return s->value[s->top+1];
    }
}
void push(struct stack *s,int x)
{
    if(isfull(s))
    {
        printf("Max overflow\n");
    }
    else
    {
        s->top+=1;
        s->value[s->top] = x;
    }
}
void display(struct stack *s)
{
     if (isempty(s))
    {
        printf("No elements present\n");
    }
    else
    {
        for (int i = 0;i<=s->top;i++)
        {
            printf("%d ",s->value[i]);
        }
    }
    
}
struct queue
{
    int value[100];
    int front;
    int rear;
    int MAX_SIZE;
};
void enqueue(struct queue *q,int data)
{
    if (q->rear == q->MAX_SIZE-1) printf("Queue is full\n");
    else
    {
        q->rear++;
        q->value[q->rear] == data;
    }
}
void dequeue(struct queue *q)
{
    if (q->front == q->rear) printf("Queue is empty\n");
    else
    {
        q->rear--;
        for (int i = 0;i<q->rear;i++)
        {
            q->value[i] = q->value[i+1];
        }
    }
}
void balance_paranthesis(struct stack *s,char expression[])
{
    for (int i = 0;expression[i]!='\0';i++)
    {
        if (expression[i]=='(') push(s,1);
        else if (expression[i] == ')') pop(s);
    }
    if (s->top == 0) printf("The expression is valid\n");
    else printf("The expression is invalid\n");
    printf("%d",s->top);
}