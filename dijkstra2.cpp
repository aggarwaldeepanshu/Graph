//Dijkstra Algorithm using Set

#include<iostream>
#include<list>
#include<set>
#include<climits>
using namespace std;

class dijsktra
{
	private:
		int V,E;
		int *distance,*parent;
		list < pair<int,int> > *adj;
 

	public:
		void set_value(int v,int e)
		{
			V=v;
                        E=e;
			distance=new int[V];
			parent=new int[V];
                        adj=new list< pair<int,int> >[E];
		}

                void add_edge(int,int,int);
		void shortest_path();
                void recurse(int,int);
		void display(int s,int v)
		{
			cout<<"The shortest path between "<<s<<" and "<<v<<" is:"<<endl;
			recurse(s,v);
			cout<<endl<<"The shortest distance is: "<<distance[v];
		}

};

void dijsktra::add_edge(int u,int v,int w)
{
       adj[u].push_back(make_pair(w,v));
       adj[v].push_back(make_pair(w,u));
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


void dijsktra::shortest_path()
{
        set< pair<int, int> > dij;
	int k,i,j,v,w;
        dij.insert(make_pair(0,0));
        list< pair<int,int> >::iterator it;
	for(i=0;i<V;i++)
	{
		distance[i]=INT_MAX;
		parent[i]=-1;
	}
	distance[0]=0;
        pair <int,int> pr;
	while(!dij.empty())
	{
		pr=*(dij.begin());
                dij.erase(dij.begin());
                k=pr.second;
                //look for adjacent vertices to k vertex
                for(it=adj[k].begin();it!=adj[k].end();it++)
                {
                       v=(*it).second;
                       w=(*it).first;
                       //update minimum distance of adjacent vertex to k from source vertex
                       if(distance[v]>(distance[k]+w))
                       {
                              if(distance[v]!=INT_MAX)
                                      dij.erase(dij.find(make_pair(distance[v],v)));
                             
                               distance[v]=distance[k]+w;
                               parent[v]=k;
                               dij.insert(make_pair(distance[v],v));
                       }
                }
	}
}

int main(void)
{
	dijsktra ob;
	ob.set_value(9,14);
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
