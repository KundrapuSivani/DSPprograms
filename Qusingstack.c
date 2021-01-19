#include <stdio.h>
#include <stdlib.h>
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
void create()
{
top1 = top2 = -1;
}
void push1(int data)
{
st1[++top1] = data;
}
int pop1()
{    
return(st1[top1--]);
}
void push2(int data)
{
st2[++top2] = data;
}
int pop2()
{   
return(st2[top2--]);
}
void enqueue()
{
int data, i;
printf("Enter data into queue");
scanf("%d", &data);
push1(data);
count++;
}
void dequeue()
{
int i;
for(i=0;i<=count;i++)
{
push2(pop1());
}
pop2();
count--;
for(i=0;i<=count;i++)
{
push1(pop2());
}
}
void display()
{
int i;
printf("\n elements in Q are");
for(i=0;i<=top1;i++)
{
printf(" %d ", st1[i]);
}
}
void main()
{
int i,n,m;
clrscr();
printf("\n enter number of element in be enqueued into the Q:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
enqueue();
}
display();
printf("\n number of elements to be dequeued from the Q:");
scanf("%d", &m);
for(i=0;i<m;i++)
{
dequeue();
}
display();
}
