#include <stdio.h>
void main()
{
    int i, j,num, temp, n, a[20];
    printf("Enter the value of n \n");
    scanf("%d", &n);
    printf("Enter the numbers \n");
    for(i = 0;i < n;++i)
    scanf("%d", &a[i]);
    for(i =0;i< n;++i)
    {
        for(j =i+1;j< n;++j)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
     }
     printf("The numbers arranged in ascending order are given below \n");
     for (i = 0; i < n; ++i)
     printf("%d\n", a[i]);
     printf("Enter a element");
     scanf("%d",&num);
     for(i=0;i<n;++i)
     {
        if(a[i]==num)
        {
           printf("The occurence of number %d is at %d\n",num,i);
        }
     }
}
