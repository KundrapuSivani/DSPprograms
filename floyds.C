#include<stdio.h>
#include<stdlib.h>
#define n 6
#define INF 9999
void display (int adjmat[n][n])
{
  int i, j;
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
	{
	    if (adjmat[i][j] == INF)
	          printf ("%4s", "INF");
	    else
	         printf ("%4d", adjmat[i][j]);
	 }
      printf ("\n");
    }
}

void floyd (int matrix[n][n])
{
  int adjmat[n][n], i, j, k;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      adjmat[i][j] = matrix[i][j];
  for (k = 1; k <= n; k++)
   {
      for (i = 1; i <= n; i++)
	 for (j = 1; j <= n; j++)
	     if (adjmat[i][k] + adjmat[k][j] < adjmat[i][j])
		 adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
      printf ("Adjacency matrix%d\n", k);
      display (adjmat);
   }
  printf("\n The shortest paths between the nodes using floyd warshallare:\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
     {
	 if (i != j)
	    printf ("\n<%d,%d>=%d", i, j, adjmat[i][j]);
     }
}

int main ()
{
  int i, j, adj[n][n];
  printf ("The number of nodes in teh graph are %d\n", n);
  printf ("Enter the adjacency matrix\n");
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
       {
	   scanf ("%d", &adj[i][j]);
       }
      printf ("\n");
    }
  floyd (adj);
  return 0;
}
