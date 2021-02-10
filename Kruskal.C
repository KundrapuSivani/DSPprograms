#include<stdio.h>
#include<conio.h>
#define MAX 20
typedef struct edge
{
int u, v, w;
} edge;
typedef struct edgelist
{
edge data[MAX];
int n;
} edgelist;
edgelist elist;
int G[MAX][MAX], n, e;
edgelist spanlist;
void sort()
{
  int i, j;
  edge temp;
  for(i = 1; i < elist.n; i++)
    for(j = 0; j < elist.n - 1; j++)
      if(elist.data[j].w > elist.data[j + 1].w)
	    {
	       temp = elist.data[j];
	       elist.data[j] = elist.data[j + 1];
	       elist.data[j + 1] = temp;
	    }
}
int find(int belongs[], int vertexno)
{
  return (belongs[vertexno]);
}
void union1(int belongs[], int c1, int c2)
{
  int i;
  for(i = 0; i < n; i++)
    if(belongs[i] == c2)
      belongs[i] = c1;
}
void kruskal()
{
  int belongs[MAX], i, j, n1, n2, cost = 0;
  elist.n = 0;
  for(i = 1; i < n; i++)
    for(j = 0; j < i; j++)
     {
	    if (G[i][j] != 0)
	     {
	          elist.data[elist.n].u = i;
	          elist.data[elist.n].v = j;
	          elist.data[elist.n].w = G[i][j];
	          elist.n++;
	     }
     }
      
  sort();
  for(i = 0; i < n; i++)
    belongs[i] = i;
  spanlist.n = 0;
  for(i = 0; i < elist.n; i++)
  {
      n1 = find (belongs, elist.data[i].u);
      n2 = find (belongs, elist.data[i].v);
      if(n1 != n2)
	    {
	        spanlist.data[spanlist.n] = elist.data[i];
	        spanlist.n = spanlist.n + 1;
	        union1 (belongs, n1, n2);
	    }
  }
  printf("\nEdges in minimum spanning tree are ");

  for(i = 0; i < spanlist.n; i++)
   {
      printf("\nedge<%d,%d>\t%d", spanlist.data[i].u, spanlist.data[i].v,
	      spanlist.data[i].w);
      cost = cost + spanlist.data[i].w;
    }
  printf("\ncost of the minimum spanning tree=%d", cost);
}
void main()
{
  int i, j, u, v, w, total_cost;
  printf("\nEnter number of vertices:");
  scanf("%d", &n);
  printf("\n Enter number of edges in the graph:");
  scanf("%d", &e);
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      G[i][j] = 0;
  for(i = 0; i < e; i++)
   {
      printf("\n Enter vertices of edge%d : ", i + 1);
      scanf("%d%d", &u, &v);
      printf("\n Enter weight:");
      scanf("%d", &w);
      G[u][v] = w;
       
   }
  kruskal();
 }
