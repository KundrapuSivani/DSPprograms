#include<stdio.h>
#include<conio.h>
int main()
{
int que[20],f=0,R=0,n,i,data;
printf("enter the number of elements in the queue ");
scanf("%d",&n);
void enque()
{
if(R>n-1)
{
printf("\nQ is overflow");
}
else
{
printf(" \n Q elements ");
scanf("%d",&data);
que[R]=data;
R=R+1;
}
}
void deque()
{
if(f==R)
{
printf("\n Q is empty");
}
else
{
printf("\n element dequeued from the Q  is %d",que[f]);
f=f+1;
}
}
void display()
{
if(f>=-1)
{
printf("\n the elements in Q are ");
for(i=f; i<R; i++)
printf("\t%d",que[i]);
}
else
{
printf("\nthe Q is empty");
}
}
printf("\nenter the elements into the Q");
for(i=0;i<=n;i++)
{
enque();
}
display();
deque();
deque();
printf("\nafter dequeue operation Q elements are");
display();
}
