//Bellman Ford Algorithm

#include<iostream>
#include<list>
#include<climits>
using namespace std;

class bellman_ford
{
	private:
		int V,E;
                bool cycle;
		int *distance,*parent;
		list < pair<int,int> > *adj;

	public:
		void set(int v,int e)
		{
                        cycle=false;
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
                        if(cycle==true)
                          cout<<"There is negative weight cycle"<<endl;
                        else
                        {
			cout<<"The shortest path between "<<s<<" and "<<v<<" is:"<<endl;
			recurse(s,v);
			cout<<endl<<"The shortest distance is: "<<distance[v];
                        }
		}

};

void bellman_ford::add_edge(int a,int b,int c)
{
       adj[a].push_back(make_pair(c,b));
}
//to print shortest path
void bellman_ford::recurse(int s,int v)
{
	if(v==s)
		cout<<s<<" ";
	else
		recurse(s,parent[v]);
	cout<<v<<" ";
}

void bellman_ford::shortest_path()
{
	int k,i,j;
        list< pair<int,int> >::iterator it;
	for(i=0;i<V;i++)
	{
		distance[i]=INT_MAX;
		parent[i]=-1;
	}
	distance[0]=0;
	for(i=0;i<V-1;i++)
	{
             for(j=0;j<V;j++)
                //look for adjacent vertices to j vertex
                for(it=adj[j].begin();it!=adj[j].end();it++)
                {
                       //update minimum distance of adjacent vertex to j from source vertex
                       if(distance[j]!=INT_MAX && distance[(*it).second]>(distance[j]+(*it).first))
                       {
                               distance[(*it).second]=distance[j]+(*it).first;
                               parent[(*it).second]=j;
                       }
                }
	}
          //to check for negative weight cycle
         for(j=0;j<V;j++)
             for(it=adj[j].begin();it!=adj[j].end();it++)
             {
                  if(distance[j]!=INT_MAX && distance[(*it).second]>(distance[j]+(*it).first))
                  {
                         cycle=true;
                         break;
                  }
             }
}

int main(void)
{
	bellman_ford ob;
	ob.set(5,8);
	ob.add_edge(0,1,-1);
	ob.add_edge(0,2,4);
	ob.add_edge(1,2,3);
	ob.add_edge(1,3,2);
	ob.add_edge(1,4,2);
	ob.add_edge(3,2,5);
	ob.add_edge(3,1,1);
        ob.add_edge(4,3,-3);
	ob.shortest_path();
	ob.display(0,4);
}
