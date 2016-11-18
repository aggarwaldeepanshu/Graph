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

struct bfs{
    int d;
    int occ;
    int p;
};
int id[max];
struct bfs arr[max];
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
//function to add node in adjacent list of source vertex in undirected graph
void add(struct Graph *graph,int src,int dest)
{
    struct adjacency_list *ptr=node(graph,dest);
    ptr->next=graph->array[id[src]].start;
    graph->array[id[src]].start=ptr;
    struct adjacency_list *ptr1=node(graph,src);
    ptr1->next=graph->array[id[dest]].start;
    graph->array[id[dest]].start=ptr1;
}
int front=-1,rear=-1;
int queue[max];
void enqueue(int s)
{
   
    if(rear==-1)
    {
        rear=0;
    front=0;
        queue[rear]=s;
}
   
    else
    {
        rear+=1;
        queue[rear]=s;
    }
}

int dequeue()
{
    int v;
    v=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    
    else{
        front+=1;
    }
    return v;
}
int empty()
{
    if(rear==-1)
        return 1;
    else
        return 0;
}

void BFS(struct Graph *g,int s, struct bfs arr[])
{
    
    int i,u,j,z,m;
    for(i=0;i<g->r;i++)
    {
        arr[i].occ=0;
        arr[i].p=INT_MIN;
        arr[i].d=INT_MAX;
    }
    j=id[s];
    printf("%d\t",s);
    arr[j].occ=1;
    arr[j].d=0;
    arr[j].p=0;
    enqueue(s);
    i=1;
    while(!empty())
    {
        u=dequeue();
        j=id[u];
        struct adjacency_list *ptr=g->array[j].start;
        while(ptr!=NULL)
        {
            z=ptr->dest;
            m=id[z];
            if(arr[m].occ==0)
            {
                printf("%d\t",z);
                arr[m].occ=1;
                //arr[m].d=arr[u].d+1;
                arr[m].d=i;
                arr[m].p=u;
            enqueue(ptr->dest);
            }
            ptr=ptr->next;
        }
        i+=1;
    }
}
//function to print shortest path
void print_path(struct Graph *g,int s,int v,struct bfs arr[])
{
    if(v==s)
    {
        printf("%d\t",s);
        return;
    }
    else
        print_path(g,s,arr[id[v]].p,arr);
    printf("%d\t",v);
}
int main(void)
{
    int i,v,e,a,b,s,val;
    v=6;
    struct Graph *graph=create_graph(v);
    
    struct bfs arr[graph->r];
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
    printf("Enter the value across which you want to search the graph\n");
    scanf("%d",&s);
    BFS(graph,s,arr);
    printf("Enter the values b|w whom you want to find shortest distance\n");
    scanf("%d %d",&a,&b);
    val=arr[id[b]].d-arr[id[a]].d;
    printf("\nShortest distance between %d and %d is\n",a,b);
    printf("%d\n",val);
    printf("The Shortest Path is\n");
    print_path(graph,a,b,arr);
}