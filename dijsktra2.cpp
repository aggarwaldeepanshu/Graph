//Dijkstra's Algorithm using Adjacency List

#include<iostream>
#include<list>
#include<climits>
using namespace std;

class dijsktra
{
	private:
		int V,E;
		int *distance,*parent;
		bool *arr;
		list < pair<int,int> > *adj;

	public:
		void set(int v,int e)
		{
			V=v;
                        E=e;
			distance=new int[V];
			parent=new int[V];
			arr=new bool[V];
                        adj=new list< pair<int,int> >[E];
		}

                void add_edge(int,int,int);
		void shortest_path();
		int find();
                void recurse(int,int);
		void display(int s,int v)
		{
			cout<<"The shortest path between "<<s<<" and "<<v<<" is:"<<endl;
			recurse(s,v);
			cout<<endl<<"The shortest distance is: "<<distance[v];
		}

};

void dijsktra::add_edge(int a,int b,int c)
{
       adj[a].push_back(make_pair(c,b));
       adj[b].push_back(make_pair(c,a));
}
//to print shortest path
void dijsktra::recurse(int s,int v)
{
	if(v==s)
		cout<<s<<" ";
	else
		recurse(s,parent[v]);
	cout<<v<<" ";
}
//to find minimum of the non used keys
int dijsktra::find()
{
	int i,min,val;
	min=INT_MAX;
	for(i=0;i<V;i++)
	{
		if(arr[i]==false&&distance[i]<min)
		{
			min=distance[i];
			val=i;
		}
	}
	return val;
}

void dijsktra::shortest_path()
{
	int k,i,j;
        list< pair<int,int> >::iterator it;
	for(i=0;i<V;i++)
	{
		distance[i]=INT_MAX;
		arr[i]=false;
		parent[i]=-1;
	}
	distance[0]=0;
	for(j=0;j<V-1;j++)
	{
		k=find();
		arr[k]=true;
                //look for adjacent vertices to k vertex
                for(it=adj[k].begin();it!=adj[k].end();it++)
                {
                       //update minimum distance of adjacent vertex to k from source vertex
                       if(arr[(*it).second]==false&& distance[(*it).second]>(distance[k]+(*it).first))
                       {
                               distance[(*it).second]=distance[k]+(*it).first;
                               parent[(*it).second]=k;
                       }
                }
	}
}

int main(void)
{
	dijsktra ob;
	ob.set(9,14);
	ob.add_edge(0,1,4);
	ob.add_edge(0,7,8);
	ob.add_edge(1,2,8);
	ob.add_edge(1,7,11);
	ob.add_edge(2,3,7);
	ob.add_edge(2,8,2);
	ob.add_edge(2,5,4);
	ob.add_edge(3,4,9);
	ob.add_edge(3,5,14);
	ob.add_edge(4,5,10);
	ob.add_edge(5,6,2);
	ob.add_edge(6,7,1);
	ob.add_edge(6,8,6);
	ob.add_edge(7,8,7);
	ob.shortest_path();
	ob.display(0,4);
}
