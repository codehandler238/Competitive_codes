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
void dijkstra_util(std::vector<sn> graph[],int dis[],int src,int v)
{
	int visited[v+1],spt[v+1],size=1,cur,Min_vertex,Min_value,i,par[v+1];

    vector<sn>::iterator it;
	
	f(i,1,v+1)
	{
		visited[i]=0;
		dis[i]=INF;
	}

	dis[src]=0;
	par[src]=src;
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
					if(dis[it->vertex] > (dis[cur]+it->weight))
					{
						dis[it->vertex] = dis[cur]+it->weight;
						par[it->vertex]=cur;
					}
				}
			}

		 f(i,1,v+1)
		 {
		 	if(visited[i] == 0 && dis[i]<Min_value){
		 		Min_value=dis[i];
		 		Min_vertex=i;
		 	}
		 }

		spt[size++]=Min_vertex;
		visited[Min_vertex]=1;
	}
	f(i,1,v+1)
	{
		if(par[i]!=i)
			cout<<i<<" "<<par[i]<<endl;
	}
}
void dijkstra(vector<sn>graph[],int v)
{
	int dis[v+1],i,src=1;
	dijkstra_util(graph,dis,src,v);
	f(i,1,v+1)
	cout<<dis[i]<<" ";
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

	dijkstra(graph,v);//O(V^2)
}