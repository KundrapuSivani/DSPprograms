#include <stdio.h>
#include <stdlib.h>
int Q1[100], Q2[100];
int F1,F2,R1,R2;
int count = 0;
void create()
{
F1=F2=-1;
R1=R2=-1;
}
void enqueue1(int data)
{
R1=R1+1;
Q1[R1] = data;
}
int dequeue1()
{
return(Q1[R1--]);
}
void enqueue2(int data)
{
R2=R2+1;
Q2[R2] = data;
}
int dequeue2()
{
F2=F2+1;
return(Q2[F2]);
}
void push()
{
int data, i;
printf("Enter data into queue");
scanf("%d", &data);
enqueue1(data);
count++;
}
void pop()
{
int i;
for(i=0;i<count;i++)
{
enqueue2(dequeue1());
}
dequeue2();
count--;
for(i=0;i<count;i++)
{
enqueue1(dequeue2());
}
}
void display()
{
int i,j;
if(F1==-1)
{
F1=0;
}
if(F1!=-1)
{
j=F1;
}

printf("\n elements in Q are");
for(i=j;i<=R1;i++)
{
printf(" %d ", Q1[i]);
}
}
void main()
{
int i,n,m;
clrscr();
create();
printf("\n enter number of element in be pushed  into the Stack:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
push();
}
display();
printf("\n number of elements to be popped from the Stack:");
scanf("%d", &m);
for(i=0;i<m;i++)
{
pop();
}
display();
}
