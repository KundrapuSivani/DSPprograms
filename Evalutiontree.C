#include<stdio.h>
#include<math.h>
int top;
int a[100];
void push(int item)
{
   a[++top]=item;
}
int pop()
{
   int p=a[top--];
   return p;
}
int get_integer(char ch)
{
    switch(ch)
    {
        case '+':return -1;break;
        case '-':return -2;break;
        case '*':return -3;break;
        case '/':return -4;break;
        case '^':return -5;break;
        case '(':return -6;break;
        case ')':return -7;break;
    }
}
char get_char(int a)
{
     switch(a)
     {
         case -1:return '+';break;
         case -2:return '-';break;
         case -3:return '*';break;
         case -4:return '/';break;
         case -5:return '^';break;
         case -6:return '(';break;
         case -7:return ')';break;
     }
}
int string_to_int_array(char s[],int exp[],int len)
{
    int i,j=0;
    for(i=0;i<len;i++)
   {
         if(s[i]>='0' && s[i]<='9')
         {
            int count=0,start=i,end=i;
            while(s[i]>='0' && s[i]<='9')
           {
              count++;
              i++;
           }
           i--;
          end=i;
          int sum=0;
          char a='0';
          for(int p=start;p<=end;p++)
          {
              sum=sum+((int)s[p]-(int)a)*pow(10,--count);
          }
          exp[j++]=sum;
       }
       else exp[j++]=get_integer(s[i]);
    }
   return j;
}
int precedence(char c)
{
     if(c=='^') return 4;
    else if(c=='*'||c=='/') return 3;
    else if(c=='+'||c=='-') return 2;
    else return 1;
}
int reverse_prefix(int *exp,int exp_len,int *rev_prefix)
{
    int i,j=0;
    int x;
    for(i=exp_len-1;i>=0;i--)
    {
       if(exp[i]>0)
          rev_prefix[j++]=exp[i];
       else if(get_char(exp[i])==')')
          push(exp[i]);
       else if(get_char(exp[i])=='(')
       {
          while(get_char(a[top])!=')')
         {
             rev_prefix[j++]=pop();
         }
         x=pop();
       }
       else
       {
           if(precedence(get_char(exp[i]))>precedence(get_char(a[top])))
               push(exp[i]);
          else
          {
              while(precedence(get_char(exp[i]))<=precedence(get_char(a[top]))) rev_prefix[j++]=pop();
              push(exp[i]);
          }
       }
   }
while(top!=-1)
   rev_prefix[j++]=pop();
return j;
}
void evaluation(int q)
{
    if(q>0)
       push(q);
    else
    {
       int x=pop();
       int y=pop();
       int result;
       switch(get_char(q))
       {
            case '+':result=x+y;push(result);break;
            case '-':result=x-y;push(result);break;
            case '*':result=x*y;push(result);break;
            case '/':result=x/y;push(result);break;
            case '^':result=pow(x,y);push(result);break;
        }
     }
}
int main()
{
    char s[1000];
    scanf("%s",s);
    int i;
    for(i=0;s[i]!='\0';i++)
    {
          if(!(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='('||s[i]==')'||(s[i]>='0'&&s[i]<='9')))
          {
                printf("Invalid");
                return 0;
          }
    }
    top=-1;
    int str_len=0;
    for(i=0;s[i]!='\0';i++) 
    str_len++;
    int exp[str_len];
    int exp_len=string_to_int_array(s,exp,str_len);
    int rev_prefix[exp_len];
    int len=reverse_prefix(exp,exp_len,rev_prefix);
    int prefix[len];
    for(i=0;i<len;i++)
    {
       prefix[len-1-i]=rev_prefix[i];
    }
   for(i=len-1;i>=0;i--)
       evaluation(prefix[i]);
   printf("%d",pop());
   return 0;
}
