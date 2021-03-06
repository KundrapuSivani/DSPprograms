#include<stdio.h>
#include<stdlib.h>
 
typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
}node;
 
node *create();
void insert(node *,node *);
int height(node *);
 
int main()
{
	int n,i=0;
	node *root=NULL,*temp;
	scanf("%d",&n);
	if(n==0)
	{
	printf("0");
	}
	else
	{
	do
	{
	     temp=create();
	     if(root==NULL)
	     root=temp;
	     else
	     insert(root,temp);
	     i++;
	}while(i<n);
	printf("%d",height(root));
	return 0;
	}
}
 
node *create()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	return temp;
}
 
void insert(node *root,node *temp)
{
	if(temp->data<root->data)
	{
		if(root->left!=NULL)
			insert(root->left,temp);
		else
			root->left=temp;
	}
	
	if(temp->data>root->data)
	{
		if(root->right!=NULL)
			insert(root->right,temp);
		else
			root->right=temp;
	}
}
 
int height(node* root)
{
    int max;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        
        int leftsubtree=height(root->left);
        int rightsubtree=height(root->right);
        if(leftsubtree>rightsubtree)
        {
            max=leftsubtree+1;
            return max;
        }
        else
        {
            max=rightsubtree+1;
            return max;
        }
    }
}
