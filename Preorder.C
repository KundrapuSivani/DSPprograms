#include<stdio.h>
int postIndex = 0; 
int top=-1; 
int search(int in[], int data,int n) 
{ 
    int i = 0; 
    for (i = 0; i < n; i++) 
        if (in[i] == data) 
            return i; 
    return i; 
} 
void push(int stack[], int x, int n)
{
     if(top>n)
    {
        printf("\nSTACK overflow");
        
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\nerror");
    }
    else
    {
        top--;
    }
}

void fillPreorder(int in[], int post[], int inStrt, 
            int inEnd, int s[],int n) 
{ 
    int val = post[postIndex];
    int inIndex = search(in, val, n);
    if(inStrt>inEnd)
    return;
    postIndex--;
    fillPreorder(in, post, inIndex + 1, inEnd, s, n); 
    fillPreorder(in, post, inStrt, inIndex - 1, s, n); 
    push(s, val,n); 
} 
void print(int in[], int post[],int n) 
{ 
    int len = n,s[100];
    postIndex = len - 1;
    fillPreorder(in, post, 0, len - 1, s, n);
    while (top!=-1)
    {
	printf("%d ",s[top]);
	pop();
    }
}

int main()
{
    int inorder[100],i,postorder[100],n;
    scanf("%d", &n);
    for(i=0; i<n;i++)
    {
	scanf("%d",&inorder[i]);
    }
	for(i=0; i<n;i++)
	{
	    scanf("%d",&postorder[i]);
	}
	print(inorder, postorder,n);   
return 0;
}
