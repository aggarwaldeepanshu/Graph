#include<iostream>
#include<list>
#include<stack>
using namespace std;

class scc
{
	private:
		int V;
		list <int> *adj;
		bool *visited;
                stack <int> s;
	public:
		scc(int v)
		{
			V=v;
			adj=new list<int>[v];
			visited=new bool[v];
		}
		void add_edge(int a,int b);
		void connected_components();
		void scc_visit(int v);
                scc reverse();
                void print_scc(scc ,int v); 
};

scc scc::reverse()
{
       int i;
       scc g(V);
       list<int>::iterator it;
       for(i=0;i<V;i++)
       {
          for(it=adj[i].begin();it!=adj[i].end();it++)
           {
               g.adj[*it].push_back(i);
           }
       }
  return g;
}

void scc::add_edge(int a,int b)
{
	adj[a].push_back(b);
}

void scc::print_scc(scc g,int v)
{
       list<int>::iterator it;
       visited[v]=true;
       cout<<v<<" ";
       for(it=g.adj[v].begin();it!=g.adj[v].end();it++)
       {
              if(!visited[*it])
                      print_scc(g,*it);
       }
}

void scc::scc_visit(int v)
{
	list <int>::iterator it;
	visited[v]=true;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
			scc_visit(*it);
	}
        s.push(v);
}

void scc::connected_components()
{
	int i,j;
	for(i=0;i<V;i++)
		visited[i]=false;
	for(i=0;i<V;i++)
	{
		if(!visited[i])
			scc_visit(i);
	}
        scc g=reverse();
        for(i=0;i<V;i++)
                visited[i]=false;
         while(!s.empty())
         {
                i=s.top();
                s.pop();
                if(!visited[i])
                        print_scc(g,i);
                cout<<endl;
         }
}

int main(void)
{
	scc ob(5);
	ob.add_edge(1,0);
	ob.add_edge(0,2);
	ob.add_edge(2,1);
	ob.add_edge(0,3);
	ob.add_edge(3,4);
	cout<<"The Strongly Connected Components are:"<<endl;
	ob.connected_components();
}
