#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct stack
{
   struct stack* next;
   int t;
   int num;
   char c;
}stack;
struct stack *top=NULL;
int top1=-1;
char s[50];
int prcedence(char x)
{
   switch(x)
   {
       case '%': return 4;
       case '*': return 3;
       case '/': return 3;
       case '+': return 2;
       case '-': return 2;
       case '(': return 1;
       default : return 0;
    }
}
void push(int data)
{
     struct stack*node=(struct stack*)malloc(sizeof(struct stack));
     node->num=data;
     node->next=NULL;
     node->t=0;
     if(top==NULL)
     {
        top=node;
     }
     else
     {
        node->next=top;
        top=node;
     }
}
void pushc(char data)
{
    s[++top1]=data;
}
void push1(char data)
{
    struct stack*node=(struct stack*)malloc(sizeof(struct stack));
    node->num=data;
    node->next=NULL;
    node->t=1;
    if(top==NULL)
    {
        top=node;
     }
    else
    {
        node->next=top;
        top=node;
    }
}
char pop()
{
    if(top1==-1)
    {
        return -1;
    }
    else
    { 
        return s[top1--];
     }
}
int main(void)
{
    char infix[50];
    int i,n;
    int count=-1;
    printf(" Infix expression\n");
    scanf("%[^\n]%*c",infix);
    n=strlen(infix)-1;
    for(i=n;i>=0;i--)
    {
      if(infix[i]==' ')
      continue;
      if(isdigit(infix[i]))
      {
         int x=(infix[i]-'0')+0;
         i--;
      if(isdigit(infix[i]))
      {
         x=(infix[i]-'0')*10+x;
         i--;
      if(isdigit(infix[i]))
      {
         x=(infix[i]-'0')*100+x;
         i--;
     if(isdigit(infix[i]))
     {
         x=(infix[i]-'0')*1000+x;
         push(x);
     }
     else
     {
         i++;
          push(x);
     }
     }
     else
     {
         i++;
         push(x);
      }
      }
     else
     {
         i++;
         push(x);
     }
     }
     else
     push1(infix[i]);
     }
    struct stack*temp=top;
    while(temp!=NULL)
    {
        char x;
        if(temp->num=='('||temp->num==')'||temp->num=='+'||temp->num=='-'||temp->num=='*'||temp->num=='/'||temp->num=='^'||temp->num=='%')
        {
            if(temp->num=='(')
             {
                 pushc(temp->num);
             }
             else if(temp->num==')')
            {
                 while((x=pop())!='(')
                 {
                      printf("%c ",x);
                 }
            }
           else
           {
                 while(prcedence(s[top1])>=prcedence(temp->num))
                 {
                     printf("%c ",pop());
                 }
                 pushc(temp->num);
            }
         }
        else if(temp->t)
        {
             printf("%c ",temp->num);
        }
       else
       {
           printf("%d ",temp->num);
       }
       temp=temp->next;
 }
while(top1!=-1)
{
    printf("%c ",pop());
}
return 0;
}
