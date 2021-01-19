#include<stdio.h>
#include<conio.h>
int adj[30][30],que[30],visited[30];
int front=0,rear=0,m,n;
void BFStrav(int m);
void main()
{
int i,j,c=0;
printf("\n enter number of nodes in the graph:");
scanf( "%d",&n);
printf("\n enter the adjacency matrix\n");
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
que[i]=0;
}
printf("\n enter the starting node of the graph");
scanf("%d",&m);
BFStrav(m);
for(i=1; i <= n; i++)
{
if(visited[i])
c++;
}
if(c==n)
{
printf("\n all nodes are reachable from starting vertex using BFS :\n");
for(i=1;i<=n;i++)
{
if(visited[i])
printf("%d \t",i);
}
}
else 
{
printf("\n all nodes are not reachable and BFS is not possible");
}
}
void BFStrav(int m) 
{
int i,k;
for(i= 1;i<= n;i++)
if(adj[m][i]&&!visited[i])
{
que[rear] = i;
rear++;
}
if(front<=rear) 
{
k=que[front];    
visited[k] = 1;
BFStrav(que[front++]);
}
}
