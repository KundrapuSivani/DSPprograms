#include<stdio.h>
#include<stdlib.h>
#define MAX 30
#define waiting 2
int adj[MAX][MAX],visited[MAX],n;
void BFStrav(int v);
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
 
int main()
{
   int i,j,v;
   printf("\n Enter number of nodes in the graph :");
   scanf( "%d",&n);
   printf("\n Enter the adjacency matrix:\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
          scanf("%d",&adj[i][j]);
      }
   }
   for(i=0;i<n;i++)
   {
      visited[i]=0;
   }
   printf("\n Enter the starting node of the graph :");
   scanf("%d",&v);
   printf("\nBFS traversal for the given graph:");
   BFStrav(v);  
   return 0;
}
 
void BFStrav(int v)
{
	int i;
	
	insert_queue(v);
	visited[v] = waiting;
	
	while(!isEmpty_queue())
	{
		v = delete_queue( );
		printf("%d ",v);
		visited[v] = 1;
		
		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && visited[i] ==0) 
			{
				insert_queue(i);
				visited[i] = waiting;
			}
		}
	}
	printf("\n");
}
 
void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow");
		exit(1);
	}
	
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
