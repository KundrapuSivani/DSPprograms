#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int v,n,adj[MAX][MAX],visited[MAX];
void DFStrav(int v);
int stack[MAX];
int top = -1;
void push(int v)
{
        if(top == (MAX-1))
        {
              printf("\nStack Overflow");
              return;
        }
        top=top+1;
        stack[top] = v;
}
 
int pop()
{
        int v;
        if(top==-1)
        {
              printf("\nStack Underflow");
              exit(1);
        }
        else
        {
              v=stack[top];
              top=top-1;
              return v;
        }
}
 
int isEmptyStack( )
{
      if(top==-1)
             return 1;
      else
           return 0;
}
 
int main()
{
   int i,j;
   printf("\n Enter number of nodes in the graph :");
   scanf( "%d",&n);
   printf("\n Enter the adjacency matrix:\n");
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
   printf("\n Enter the starting node of the graph :");
   scanf("%d",&v);
   printf("\nDFS traversal for the given graph:");
   DFStrav(v);  
   return 0;
}
void DFStrav(int v)
{
        int i;
        push(v);
        while(!isEmptyStack())
        {
                v = pop();
                if(!visited[v])
                {
                      printf("%d ",v);
                      visited[v]=1;
                }
                for(i=1;i<=n;i++)
                {
                      if(adj[v][i]==1 && !visited[i])
                             push(i);
                }
        }
}
