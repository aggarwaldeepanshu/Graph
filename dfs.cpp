
#include<iostream>
#include<list>
using namespace std;

class dfs
{
	private:
		int V;
		list <int> *adj;
		bool *visited;
	public:
		dfs(int v)
		{
			V=v;
			adj=new list<int>[v];
			visited=new bool[v];
		}
		void add_edge(int a,int b);
		void DFS();
		void DFS_VISIT(int v); 
};

void dfs::add_edge(int a,int b)
{
	adj[a].push_back(b);
}

void dfs::DFS_VISIT(int v)
{
	list <int>::iterator it;
	visited[v]=true;
	cout<<v<<" ";
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
			DFS_VISIT(*it);
	}
}

void dfs::DFS()
{
	int i;
	for(i=0;i<V;i++)
		visited[i]=false;
	for(i=0;i<V;i++)
	{
		if(!visited[i])
			DFS_VISIT(i);
	}
}

int main(void)
{
	dfs ob(4);
	ob.add_edge(0,1);
	ob.add_edge(0,2);
	ob.add_edge(1,2);
	ob.add_edge(2,0);
	ob.add_edge(2,3);
	ob.add_edge(3,3);
	cout<<"The required DFS Traversal"<<endl;
	ob.DFS();
}
