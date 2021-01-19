#include<stdio.h>
int main()
{
    int i,j,k,temp,n,a[30];
    printf("enter number of input");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<(n-1);i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[k]>a[j])
            k=j;
        }
        if(k!=i)
        {
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
