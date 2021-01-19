#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char stack[100];
int top = -1;
void push(char x)
{
stack[++top] = x;
}
char pop()
{
if(top == -1)
return -1;
else
return stack[top--];
}
int priority(char x)
{
if(x == '(')
return 0;
if(x=='+'||x=='-')
return 1;
if(x=='*'||x =='/')
return 2;
return 0;
}
int main()
{
char input[100];
char *n, m;
printf("Enter the infix expression : ");
scanf("%s",input);
printf("\n");
n = input;
while(*n!='\0')
{
if(isalnum(*n))
printf("%c ",*n);
else if(*n=='(')
push(*n);
else if(*n==')')
{
while((m=pop())!='(')
printf("%c ", m);
}
else
{
while(priority(stack[top])>=priority(*n))
printf("%c ",pop());
push(*n);
}
n++;
}
while(top!=-1)
{
printf("%c ",pop());
}
return 0;
}
