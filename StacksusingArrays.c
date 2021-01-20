#include<stdio.h>
#include<conio.h>
int main()
{
     int stack[20],top=-1,n,i,data;
     printf("enter the number of elements in the stack ");
     scanf("%d",&n);
     void push()
     {
        if(top>=n-1)
        {
            printf("\nstack is overflow");
        }
        else
        {
            printf(" \n stack elements ");
            scanf("%d",&data);
            top=top+1;
            stack[top]=data;
        }
     }
     void pop()
     {
        if(top<=-1)
        {
             printf("\n stack underflow");
        }
       else
       {
            printf("\n element popped from the stack  is %d",stack[top]);
            top=top-1;
        }
     }
     void display()
     {
        if(top>=0)
        {
            printf("\n the elements in stack are ");
            for(i=0; i<top; i++)
            printf("\t%d",stack[i]);
        }
        else
        {
           printf("\nthe stack is empty");
        }
     }
     printf("\n enter the elements into the stack");
     for(i=0;i<=n;i++)
     {
         push();
     }
     display();
     pop();
     pop();
     printf("\n after pop operation stack elements are");
     display();
}
