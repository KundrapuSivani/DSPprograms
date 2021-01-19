#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next, *prev;
};
int getmax(struct  Node* head)
{
   int max;
   struct Node *a = head, *b = NULL;
   max=a->data;
   while(a->next!=b)
   {
  if(a->data>max)
   {
   max=a->data;
    }
    a=a->next;
    }
   return max;
}

void push(struct Node** headref, int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->prev = NULL;
    node->next = *headref;
    if (*headref != NULL)
	(*headref)->prev = node;
    *headref = node;
}

void printlist(struct Node* head)
{
    while(head != NULL)
    {
	printf("%d  ", head->data);
	head = head->next;
    }
}
void Radixsort(struct  Node* head,int N)
{
   for(int i=1,j=1;j<=N;i=i*10,j++)
	{
	struct Node *a;
	struct Node *b;
	a=head->next;
	while(a!=NULL)
	{
		int k=a->data;
		int p=a->data/i;
		p=p%10;
		b=a->prev;
		int c=b->data/i;
		c=c%10;
		while(b!=NULL && c>p)
		{
			(b->next)->data=b->data;
			b=b->prev;
			if(b!=NULL)
			{
			c=b->data/i;
			c=c%10;
			}
		}
		if(b!=NULL) (b->next)->data=k;
		else head->data=k;
		a=a->next;
	}
    }

}
int main(void)
{
    int i, n, a[30],N=0,l,c=0;
    struct Node *head = NULL;
    struct Node *start;
    scanf ("%d", &n);
    if(n<=0)
    {
    
        printf("INVALID INPUT");
    }
    else
    {
    for (i = 0; i < n; i++)
	scanf ("%d", &a[i]);
	for(i=0;i<n;i++)
	{
	    if(a[i]<0)
	    c=c+1;
	}
	if(c>0)
	{
	    printf("INVALID INPUT");
	}
	else
	{
    for (i = 0; i < n; i++)
	push(&head, a[i]);
    start=head;
    l= getmax (start);
    while(l> 0)
    {
      N++;
      l/= 10;
    }
    Radixsort(head,N);
    printlist(head);
    }
    }
    return 0;
}
