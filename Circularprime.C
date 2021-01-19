#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int isprime(int num);
int main()
{
    int digit=0,i=0,rem=0,sum=0,temp,n,length=0;
    scanf("%d",&n);
    if(n<=0)
    {
    printf("-1");
    }
    else
    {
     temp=n;
     while(temp)
     {
         
         temp=temp/10;
         length++;
         
     }
     while(i<length)
     {
         rem=n%10;
         n=n/10;
         n=pow(10,length-1)*rem+n;
         digit=isprime(n);
         sum=sum+digit;
         i=i+1;
     }
     if(sum==length)
     printf("1");
     else
     printf("0");
    }
}
int isprime(int num)
{
    int c=0,i;
    for(i=1;i<num+1;i++)
    {
        if(num%i==0)
        {
            c=c+1;
        }
    }
    if(c==2)
    {
        return 1;
        
    }
    else
    {
        return 0;
    }
}
