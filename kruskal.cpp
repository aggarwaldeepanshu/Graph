#include<iostream>
#include<algorithm>
using namespace std;
int j=0;
struct mst{
	int parent;
	int rank;
};

class graph
{
	private:
		int V,E,W;
		pair<int,pair<int,int> > *p,*result;
		struct mst *arr;

	public:
		void set(int v,int e)
		{
			V=v;
			E=e;
			p=new pair<int,pair<int,int> >[E];
			result=new pair<int,pair<int,int> >[V];
			arr=new struct mst [V];
		}
		void add_edge(int,int,int);
		int find(int );
		void combine(int,int);
		void kruskal();
};

void graph::add_edge(int w,int a,int b)
{
	p[j++]=make_pair(w,make_pair(a,b));
}

int graph::find(int a)
{
	if(arr[a].parent==-1)
		return a;
	else
		return find(arr[a].parent);
}

void graph::combine(int m,int n)
{
	int a=find(m);
	int b=find(n);
	if(arr[a].rank<arr[b].rank)
		arr[a].parent=b;
	else if(arr[a].rank>arr[b].rank)
		arr[b].parent=a;
	else
	{
		arr[a].parent=b;
		arr[b].rank++;
	}
}

void graph::kruskal()
{
	int i,x,y,q=0;
	sort(p,p+E);
	for(i=0;i<V;i++)
	{
		arr[i].parent=-1;
		arr[i].rank=0;
	}
	i=0;
	while(q<V-1)
	{
		x=find(p[i].second.first);
		y=find(p[i].second.second);
		if(x!=y)
		{
			result[q++]=p[i];
			combine(p[i].second.first,p[i].second.second);
		}
		i++;
	}

	cout<<"The required edges are"<<endl;
	cout<<"Weight"<<"  "<<"Source"<<"  "<<"Destination"<<endl;
	for(i=0;i<q;i++)
		cout<<result[i].first<<"  "<<result[i].second.first<<"  "<<result[i].second.second<<endl;
}

int main(void)
{
	graph ob;
	ob.set(4,5);
	ob.add_edge(10,0,1);
	ob.add_edge(6,0,2);
	ob.add_edge(5,0,3);
	ob.add_edge(15,1,3);
	ob.add_edge(4,2,3);
	ob.kruskal();
}
