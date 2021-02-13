#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int v,n,visited[MAX];
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
 void DFS(int a[n][n],int v)
{
    int flag=0;
    push(v);
    while(top!=-1 )
    {
        v=pop();

        if(visited[v]==0)
        {
           visited[v]=1;
           printf("node %d is visited\n",v);

           for(int i=0;i<n;i++)
          {

              if(a[i][v]==1||a[v][i]==1)

                  push(i);
          }

        }
     }
}


 
int main()
{
   int i,j;
    int a[9][9] = {   {0,1,0,1,0,0,0,0,1},
                      {1,0,0,0,0,0,0,1,0},
                      {0,0,0,1,0,1,0,1,0},
                      {1,0,1,0,1,0,0,0,0},
                      {0,0,0,1,0,0,0,0,1},
                      {0,0,1,0,0,0,1,0,0},
                      {0,0,0,0,0,1,0,0,0},
                      {0,1,1,0,0,0,0,0,0},
                      {1,0,0,0,1,0,0,0,0}}; 
   printf("\n Enter number of nodes in the graph :");
   scanf( "%d",&n);
  
   for(i=0;i<n;i++)
   {
      visited[i]=0;
   }
   printf("\n Enter the starting node of the graph :");
   scanf("%d",&v);
   printf("\nDFS traversal for the given graph:");
   DFS(a,v);  
   return 0;
}


