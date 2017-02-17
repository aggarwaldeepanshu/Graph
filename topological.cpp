#include<iostream>
#include<list>
#include<stack>
using namespace std;

class topological
{
	private:
		int V;
		list <int> *adj;
		bool *visited;
                stack <int> s;
	public:
		topological(int v)
		{
			V=v;
			adj=new list<int>[v];
			visited=new bool[v];
		}
		void add_edge(int a,int b);
		void topological_sort();
		void TS_VISIT(int v); 
};

void topological::add_edge(int a,int b)
{
	adj[a].push_back(b);
}

void topological::TS_VISIT(int v)
{
	list <int>::iterator it;
	visited[v]=true;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
			TS_VISIT(*it);
	}
        s.push(v);
}

void topological::topological_sort()
{
	int i;
	for(i=0;i<V;i++)
		visited[i]=false;
	for(i=0;i<V;i++)
	{
		if(!visited[i])
			TS_VISIT(i);
	}
        while(!s.empty())
        {
              cout<<s.top()<<" ";
              s.pop();
        }
}

int main(void)
{
	topological ob(6);
	ob.add_edge(5,2);
	ob.add_edge(5,0);
	ob.add_edge(4,0);
	ob.add_edge(4,1);
	ob.add_edge(2,3);
	ob.add_edge(3,1);
	cout<<"The required Topological Order"<<endl;
	ob.topological_sort();
}
