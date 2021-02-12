#include<stdio.h>
#include<conio.h>
#define MAX 30
int adj[MAX][MAX],queue[MAX],visited[MAX];
int front=0,rear=0,vertex,n;
void BFStrav(int vertex);
void main()
{
      int i,j,count=0;
      printf("\n Enter number of nodes in the graph:");
      scanf( "%d",&n);
      printf("\n Enter the adjacency matrix\n");
      for(i=1;i<=n;i++)
      {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&adj[i][j]);
            }
      }
      for(i=1;i<=n;i++)
      {
           visited[i]=0;
           queue[i]=0;
      }
      printf("\n Enter the starting vertex of the graph :");
      scanf("%d",&vertex);
      BFStrav(vertex);
      for(i=1; i <= n; i++)
      {
           if(visited[i])
           count++;
      }
      if(count==n)
      {
          printf("\n All nodes are reachable from starting vertex using BFS\n");
          for(i=1;i<=n;i++)
          {
                if(visited[i])
                    printf("%d \t",i);
          }
      }
      else
          printf("\n All nodes are not reachable ");
      
}
void BFStrav(int vertex) 
{
      int i,j;
      for(i= 1;i<= n;i++)
           if(adj[vertex][i]&&!visited[i])
           {
               queue[rear] = i;
               rear++;
           }
      if(front<=rear) 
      {
           j=queue[front];
           visited[j] = 1;
           BFStrav(queue[front++]);
      }
}
