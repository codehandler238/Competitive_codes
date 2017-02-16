#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 100005
#define pb(a) push_back(a)
#define sn struct node
sn{
	int vertex,weight;
};
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void prims_util(std::vector<sn> graph[],int v,int par[])
{
	int src,visited[v+1],spt[v+1],key[v+1],size=1,cur,Min_vertex,Min_value,i;

    vector<sn>::iterator it;
	
	f(i,1,v+1)
	{
		visited[i]=0;
		key[i]=INF;
	}
    src=1;
	par[src]=-1;
	visited[src]=1;
	spt[size++]=src;

	while(size <= v)
	{	
			cur=spt[size-1];
            Min_value=INF;

			for(it=graph[cur].begin();it!=graph[cur].end();it++)
			{
				if(visited[it->vertex] == 0)
				{
					if(key[it->vertex] > it->weight)
					{
						key[it->vertex]=it->weight;
						par[it->vertex]=cur;
					}
				}
			}

		 f(i,1,v+1)
		 {
		 	if(visited[i] == 0 && key[i]<Min_value){
		 		Min_value=key[i];
		 		Min_vertex=i;
		 	}
		 }
cout<<"Min "<<Min_vertex<<endl;
		spt[size++]=Min_vertex;
		visited[Min_vertex]=1;
	}
}
void prims(vector<sn>graph[],int v)
{
	int par[v+1],i,src=1;
	prims_util(graph,v,par);
	f(i,1,v+1)
	cout<<i<<par[i]<<" ";
	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t,v,e,w,v1,v2;
	sn tmp;
	cin>>v>>e;

	std::vector<sn> graph[v+1];

	f(i,0,e)
	{
		cin>>v1>>v2>>w;
		tmp.vertex=v2;
		tmp.weight=w;
		graph[v1].pb(tmp);
		tmp.vertex=v1;
		graph[v2].pb(tmp);
	}

	prims(graph,v);//O(V^2)
}