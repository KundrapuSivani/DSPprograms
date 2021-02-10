#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *ptr;
}*top=NULL;
struct  node *top;
void push(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if(top=NULL)
    {
        newnode->ptr = NULL;
    }
    else
    {   
        newnode->ptr=top;
    }
    top = newnode;
}
int pop()
{
    if(top==NULL)
    {
       printf("\n stack underflow");
    }
    else
    {
        struct node *newnode=top;
        printf("\n popped element%d ",newnode->data);
        top=newnode->ptr;
        free(newnode);
    }
}
void display()
{
    if(top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
         struct node *newnode=top;
         while(newnode->ptr!=NULL)
         {
            printf("%d\n", newnode->data);
            newnode=newnode->ptr;
         }
     }
}
int main()
{
    int n,i,a;
     printf("enter the number of elements in the stack ");
     scanf("%d",&n);
     printf("enter %d elemnts into the stack\n",n);
     for(i=0;i<n;i++)
     {
         scanf("%d",&a);
         push(a);
     }
     display();
     pop();
     return 0;
}
