//Traversal through graph using DFS
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define max 100

struct Graph{
    int r;
    struct adjacency *array;
};

struct adjacency{
    struct adjacency_list *start;
};

struct adjacency_list{
    int dest;
    struct adjacency_list *next;
};

struct dfs{
    int occ;
    int p;
};
int id[max];
struct dfs arr[max];
struct Graph *create_graph(int v)
{
    int i,x;
    struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
    graph->r=v;
    graph->array=(struct adjacency*)malloc(v*sizeof(struct adjacency));
    printf("Enter the values\n");
    for(i=0;i<v;i++)
    {
        scanf("%d",&x);
        id[x]=i;
        graph->array[i].start=NULL;
    }
    return graph;
}
//function to create a node
struct adjacency_list *node(struct Graph *graph,int dest)
{
    struct adjacency_list *ptr=(struct adjacency_list*)malloc(sizeof(struct adjacency_list));
    ptr->dest=dest;
    ptr->next=NULL;
    return ptr;
}
//function to add node in adjacent list of source vertex in directed graph
void add(struct Graph *graph,int src,int dest)
{
    struct adjacency_list *ptr=node(graph,dest);
    ptr->next=graph->array[id[src]].start;
    graph->array[id[src]].start=ptr;
}

void DFS_VISIT(struct Graph *g,int u,struct dfs arr[]);
int count=1;
void DFS(struct Graph *g, struct dfs arr[])
{
    
    int i,j,v;
    for(i=0;i<g->r;i++)
    {
        arr[i].occ=0;
        arr[i].p=0;
    }
    printf("Enter the node for DFS Search\n");
    while(count<g->r)
    {
        scanf("%d",&v);
        printf("The DFS traversal is\n");
        j=id[v];
        if(arr[j].occ==0)
            DFS_VISIT(g,v,arr);
    }
}

void DFS_VISIT(struct Graph *g,int u,struct dfs arr[])
{
    int j,m,z;
    printf("%d\t",u);
    j=id[u];
    arr[j].occ=1;
    struct adjacency_list *ptr=g->array[j].start;
    while(ptr!=NULL)
    {
        z=ptr->dest;
        m=id[z];
        if(arr[m].occ==0)
        {
            count++;
            arr[m].p=u;
            DFS_VISIT(g,z,arr);
            
        }
        ptr=ptr->next;
    }
    
}

int main(void)
{
    int i,v,e,a,b;
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    struct Graph *graph=create_graph(v);
    
    struct dfs arr[graph->r];
   
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    printf("Enter the value of source and destination vertices which you want to connect\n");
    /*eg for 7 edges and input 2,4,6,8,10,12 the pair of vertices can be
     (2,4),(2,6),(4,6),(6,8),(6,10),(8,10),(12,10)*/
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&a,&b);
        add(graph,a,b);
    }
    DFS(graph,arr);
}