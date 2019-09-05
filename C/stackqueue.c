#include<stdio.h>
#include "stacknqueue.h"
struct cd
{
    int id;
    int year;
    char moviename[100];
};
struct dvd
{
    int id;
    int year;
    char moviename[100];
};
void bubble_sort(struct dvd s[],int n)
{
    for (int i = 0; i< n ; i++)
    {
        for (int j = i; j< n-i-1;j++)
        {
            if (s[j].year > s[j+1].year)
            {
                int temp = s[j].year;
                s[j].year = s[j+1].year;
                s[j+1].year = temp;
            }
        }
    }
}
int main()
{
    struct stack s;
    s.top == -1;
    s.MAX_SIZE = 100;
    char a[100];
    printf("Enter the expression to check: ");
    scanf("%s",&a);
    balance_paranthesis(&s,a);
    printf("%d",s.top);
    struct cd c[3];
    struct dvd d[3];
    printf("Enter the cd details:-\n");
    for (int i = 0 ;i < 3; i++)
    {
        printf("CD #%d id: ",i);
        scanf("%d",&c[i].id);
        printf("CD #%d Year: ",i);
        scanf("%d",&c[i].year);
        printf("CD #%d name: ",i);
        scanf("%s",&c[i].moviename);
    }
    for (int i = 0 ;i < 3; i++)
    {
        printf("DVD #%d id: ",i);
        scanf("%d",&d[i].id);
        printf("DVD #%d Year: ",i);
        scanf("%d",&d[i].year);
        printf("DVD #%d name: ",i);
        scanf("%s",&d[i].moviename);
    }
    struct queue Q1;
    for (int i = 0; i < 3; i++)
    {
        if (c[i].year == 2015) enqueue(&Q1,c[i].year);
    }
    /* bubble_sort(d,3);
    struct stack S1;
    for (int i = 0;i<3;i++)
    {
        push(&S1,d[i].year);
    }
    struct queue Q2;
    for (int i = 0;i<3;i++)
    {
        if (S1.value[i] == 2018)
        {
            int temp[100];
            int count = 0;
            for (int j = 0;j<=i;j++)
            {
                temp[j] = pop(&S1);
                count++;
            }
            enqueue(&Q2,temp[count]);
            for (int k = 0;k < count-1;k++)
            {
                push(&S1,temp[count -1 -k -1]);
            }

        }
    }*/
}