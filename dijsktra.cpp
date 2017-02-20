//Dijsktra's Algorithm using adjacency matrix

#include<iostream>
#include<climits>
using namespace std;
class dijsktra
{
	private:
		int V;
		int *distance,*parent;
		bool *arr;
		int **graph;

	public:
		void set(int v)
		{
			V=v;
			distance=new int[V];
			parent=new int[V];
			arr=new bool[V];
			graph=new int*[V];
			for(int i=0;i<V;i++)
				graph[i]=new int[V];
		}
		void get()
		{
			int i,j;
			cout<<"Enter the values of graph"<<endl;
			for(i=0;i<V;i++)
				for(j=0;j<V;j++)
					cin>>graph[i][j];
		}
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

void dijsktra::recurse(int s,int v)
{
	if(v==s)
		cout<<s<<" ";
	else
		recurse(s,parent[v]);
	cout<<v<<" ";
}

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
		for(i=0;i<V;i++)
		{
			if(arr[i]==false && graph[k][i] && distance[i]>(distance[k]+graph[k][i]))
			{
				distance[i]=distance[k]+graph[k][i];
				parent[i]=k;
			}
		}
	}
}

int main(void)
{
	dijsktra ob;
	ob.set(5);
	ob.get();
	ob.shortest_path();
	ob.display(0,4);
}
