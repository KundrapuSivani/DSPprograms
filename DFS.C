#include<stdio.h>
#include<conio.h>
int adj[30][30],visited[30];
int m,n;
void DFStrav(int m);
void main()
{
int i,j;
printf("\n enter number of nodes in the graph :");
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
}
printf("\n enter the starting node of the graph");
scanf("%d",&m);
printf("DFS traversal for the given graph:");
DFStrav(m);    
}
void DFStrav(int m)
{
int i;
printf("\n%d",m);
visited[m]=1;
for(i=1;i<=n;i++)
{
if(adj[m][i]==1&&!visited[i])
DFStrav(i);
}
}
