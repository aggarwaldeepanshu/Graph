#include<iostream>
#include<list>
#include<climits>
using namespace std;

int j=0,m=0;

class graph
{
	private:
		int V,E;
		pair<int,pair<int,int> > *p,*result;
		list<int> *temp;
		bool *arr;
		int *key;
	public:
		void set(int v,int e)
		{
			V=v;
			E=e;
			arr=new bool [V];
			key=new int [V];
			p=new pair<int,pair<int,int> > [E];
			result=new pair<int,pair<int,int> > [E];
			temp=new list<int> [V];
		}
		void add_edge(int,int,int);
		void prims();
		int find();
		void display()
		{
			cout<<"Weight  "<<"Source  "<<"Destination"<<endl;
			for(int i=0;i<m;i++)
				cout<<result[i].first<<"  "<<result[i].second.first<<"  "<<result[i].second.second<<endl;
		}
};

void graph::add_edge(int a,int b,int c)
{
	p[j++]=make_pair(a,make_pair(b,c));
	temp[b].push_back(c);
}
//to find minimum unused value from arr with minimum value
int graph::find()
{
	int i,min,val;
	min=INT_MAX;
	for(i=0;i<V;i++)
	{
		if(arr[i]==false&&key[i]<min)
		{
			min=key[i];
			val=i;
		}
	}
	return val;
}

void graph::prims()
{
	list<int>::iterator it;
	int i,k,l,h;
	for(i=0;i<V;i++)
	{
		arr[i]=false;
		key[i]=INT_MAX;
	}
	key[0]=0;

	for(i=0;i<V-1;i++)
	{
		k=find();
		arr[k]=true;
		//to check for the adjacent vertices to k vertex
		for(it=temp[k].begin();it!=temp[k].end();it++)
		{

			//to look for the index where k and *it vertices are stored in p array
			for(h=0;h<j;h++)
				if(p[h].second.first==k&&p[h].second.second==*it)
					l=h;

			//to find the minimum edge
			if(arr[*it]==false&&key[*it]>p[l].first)
			{
				key[*it]=p[l].first;
				result[m].first=p[l].first;
				result[m].second.first=k;
				result[m].second.second=*it;
				m++;
			}
		}
	}

}

int main(void)
{
	graph ob;
	ob.set(5,7);

	ob.add_edge(2,0,1);
	ob.add_edge(3,1,2);
	ob.add_edge(6,0,3);
	ob.add_edge(8,1,3);
	ob.add_edge(5,1,4);
	ob.add_edge(7,2,4);
	ob.add_edge(9,3,4);
	ob.prims();
	ob.display();
}
