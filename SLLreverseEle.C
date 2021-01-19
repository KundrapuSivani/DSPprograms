#include <stdio.h>
#include <malloc.h>
struct node
{
int data;
struct node *next;
};
typedef struct node snode;
snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;
snode* create_node(int);
void addfirst();
void addlast();
void delete();
void search();
void revdisplay(snode *);
void display();
int main()
{
int i,n;
clrscr();
printf("Enter number of elemtents to be added:");
scanf("%d",&n);
addfirst();
for(i=1;i<n;i++)
addlast();
display();
printf("Enter number of elemtents to be deleted:");
scanf("%d",&n);
for(i=1;i<n;i++)
delete();
printf(" Dispaly nodes");
display();
printf("Display nodes in reverse\n");
revdisplay(first);
search();
return 0;
}
snode* createNode(int val)
{
newnode = (snode *)malloc(sizeof(snode));
if(newnode==NULL)
{
printf("\nMemory was not allocated");
return 0;
}
else
{
newnode->data = val;
newnode->next = NULL;
return newnode;
}
}
void addfirst()
{
int val;
printf("\nEnter the value for the node:");
scanf("%d", &val);
newnode = createNode(val);
if(first==last&&first==NULL)
{
first=last = newnode;
first->next = NULL;
last->next = NULL;
}
else
{
temp = first;
first = newnode;
first->next = temp;
}
}
void addlast()
{
int val;
printf("\nEnter the value for the Node:");
scanf("%d", &val);
newnode=createNode(val);
if (first==last&&last==NULL)
{
first = last = newnode;
first->next = NULL;
last->next = NULL;
}
else
{
last->next = newnode;
last = newnode;
last->next = NULL;
}
}
void delete()
{
int pos, cnt = 0, i;
if(first==NULL)
{
printf(":No node to delete\n");
}
else
{
printf("\nEnter the position of value to be deleted:");
scanf(" %d", &pos);
ptr =first;
if(pos==1)
{
first=ptr->next;
printf("\nElement deleted\n");
}
else
{
while(ptr != NULL)
{
ptr=ptr->next;
cnt=cnt+1;
}
if(pos>0&&pos<= cnt)
{
ptr = first;
for (i = 1;i < pos;i++)
{
prev = ptr;
ptr = ptr->next;
}
prev->next = ptr->next;
}
else
{
printf("Position is out of range");
}
free(ptr);
printf("\nElement deleted");
}
}
}
void search()
{
int flag=0, key, pos = 0;
if(first == NULL)
{
printf(":No nodes in the list\n");
}
else
{
printf("\nEnter the value to search");
scanf("%d", &key);
for(ptr = first;ptr != NULL;ptr = ptr->next)
{
pos= pos+1;
if(ptr->data== key)
{
flag = 1;
break;
}
}
if(flag == 1)
{
printf("\nElement %d found at %d position\n", key, pos);
}
else
{
printf("\nElement %d not found in list\n", key);
}
}
}
void display()
{
if(first==NULL)
{
printf(":No nodes in the list to display\n");
}
else
{
for(ptr=first;ptr!=NULL;ptr=ptr->next)
{
printf(" \nThe elements in list is:");
printf("%d\t", ptr->data);
}
}
}
void revdisplay(snode *ptr)
{
int val;
if(ptr==NULL)
{
printf(":No nodes to display\n");
}
else
{
if(ptr!= NULL)
{
val=ptr->data;
revdisplay(ptr->next);
printf("%d\t", val);        
}
}
}
