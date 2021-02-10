#include<stdio.h>
#include<stdlib.h>
struct node 
{
  
int vertex;
   
struct node *next;
 
};

struct node *createNode (int v);

struct Graph 
{
  
int numVertices;
   
int *visited;
   
struct node **adjLists;
 
};

void DFS (struct Graph *graph, int vertex) 
{
  
  struct node *adjList = graph->adjLists[vertex];
  
  struct node *temp = adjList;
  
  graph->visited[vertex] = 1;
  
  printf ("%d\t", vertex);
  
  while (temp != NULL)
    
    {
      
         int connectedVertex = temp->vertex;
      
         if (graph->visited[connectedVertex] == 0)
	
	   {
	  
                DFS (graph, connectedVertex);
	
           }
      
       temp = temp->next;
    
    }

}


struct node *createNode (int v) 
{
  
     struct node *newNode = malloc (sizeof (struct node));
  
     newNode->vertex = v;
  
     newNode->next = NULL;
  
     return newNode;

}


struct Graph *createGraph (int vertices) 
{
  
     struct Graph *graph = malloc (sizeof (struct Graph));
  
     graph->numVertices = vertices;
  
     graph->adjLists = malloc (vertices * sizeof (struct node *));
  
     graph->visited = malloc (vertices * sizeof (int));
  
     int i;
  
     for (i = 1; i <= vertices; i++)
    
     {
      
         graph->adjLists[i] = NULL;
      
         graph->visited[i] = 0;
    
     }
  
     return graph;

}


void addEdge (struct Graph *graph, int src, int dest) 
{
  
       struct node *newNode = createNode (dest);
  
       newNode->next = graph->adjLists[src];
  
       graph->adjLists[src] = newNode;
  
 
       newNode = createNode (src);
  
       newNode->next = graph->adjLists[dest];
  
       graph->adjLists[dest] = newNode;

} 

void printGraph (struct Graph *graph) 
{
  
   int v;
  
   for (v = 1; v <= graph->numVertices; v++)
    
    {
      
        struct node *temp = graph->adjLists[v];
      
        printf ("\n Adjacency list of vertex %d\n", v);
      
        while (temp)
	
	      {
	  
           printf ("%d->", temp->vertex);
	  
           temp = temp->next;
	
        }
      
       printf ("\n");
    
    }

}


void Connected (struct Graph *graph, int vertices) 
{
  
    int i, c = 1;
  
    printf (" The first component of the graph \n");
  
    DFS (graph, 1);
  
    for (i = 1; i <= vertices; i++)
    
      {
      
          if (graph->visited[i] != 1)
	
	          {
	  
               DFS (graph, i);
	  
               c++;
	
            }
    
       }
  
    printf ("\n");
  
    printf (" The number of components present in the graph :%d \n", c);

}


 
int main (int argc, char *argv[]) 
{
  
   int a[20], nodes, edges, i = 0;
  
   if (argc != 2)
    
    {
      
        printf (" usage %s is provided ,filename is not provided\n", argv[0]);
    
     }
  
   else
    
    {
      
        FILE * file = fopen (argv[1], "r");
      
        if (file == 0)
	
	 {
	  
              printf ("could not open file\n");
	
         }
      
        else
	
	 {
	  
             int x;
	  
              while ((x = fgetc (file)) != EOF)
	    
	        {
	      
                    printf ("%c", x);
	      
                    if (x != ' ' && x != '\n')
		
		      {
		  
                            a[i++] = x - '0';
		
                      }
	    
                }
	  
             fclose (file);
	
         }
    
     }
  
    nodes = a[0];
  
    edges = a[1];
  
     printf (" \nThe number of nodes in the given graph %d\n", nodes);
  
     printf (" \nThe number of edges in the given graph %d", edges);
  
     struct Graph *graph = createGraph (nodes);
  
     for (i = 2; i < 2 * edges + 2; i++)
    
       {
      
           addEdge (graph, a[i], a[i + 1]);
      
           i = i + 1;
    
       }
  
     printGraph (graph);
  
     Connected (graph, nodes);
  
     return 0;

}


