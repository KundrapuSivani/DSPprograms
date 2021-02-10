#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front = NULL,*rear = NULL;
int enque(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
     newnode -> next = NULL;
     if(front == NULL)
     {
        front = newnode;
        rear = newnode;
     }
     else
     {
         rear -> next = newnode;
         rear = newnode;
     }
}
void deque()
{
    if(front == NULL)
    printf("\nQ underflow");
    else
    {
        struct node *temp = front;
        front = front -> next;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
    }
}
void display()
{
     if(front == NULL)
     printf("\nQ is underflow");
     else
     {
         struct node *temp = front;
         while(temp->next != NULL)
         {
             printf("\n%d element in Q",temp->data);
             temp = temp -> next;
             printf("\n%d element in Q",temp->data);
         }
     }
}
int main()
{
     int i,n,a;
     printf("enter the number of elements in the Q ");
     scanf("%d",&n);
     printf("enter %d elemnts into the Q\n",n);
     for(i=0;i<n;i++)
     {
         scanf("%d",&a);
         enque(a);
     }
     display();
     deque();
     return 0;
}
