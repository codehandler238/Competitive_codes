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
	int src,des,weight;
};
struct Set{
	int rank,par;
};
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int cmp(sn a,sn b)
{
	if(a.weight < b.weight)
		return 1;
	else
		return 0;
}
int find_par(int i,struct Set parent[])
{
	while(i != parent[i].par)
		i=parent[i].par;

	return i;
}
void kruskal(sn graph[],int v,int e)
{
	int i,j,k,p,q,x,y,size=0;
	Set parent[v];
	sort(graph,graph+e,cmp);

	f(i,0,v)
	{
		parent[i].par=i;
		parent[i].rank=0;
	}

	sn mst[v];

	f(i,0,e)
	{
		p=graph[i].src;
		q=graph[i].des;

		x=find_par(p,parent);
		y=find_par(q,parent);

		if(x!=y)
		{
			if(parent[x].rank < parent[y].rank)
			{
				parent[x].par=y;
			}
			else if(parent[x].rank > parent[y].rank)
			{
				parent[y].par=x;
			}
			else
			{
				parent[x].par=y;
				parent[y].rank++;
			}
			mst[size].src=p;
			mst[size].des=q;
			mst[size].weight=graph[i].weight;
			size++;
		}
	}
	f(i,0,size)
	cout<<mst[i].src<<" "<<mst[i].des<<endl;
}
int main()
{
	int i,j,k,m,n,t,v,e;
	cin>>v>>e;
	sn graph[e];

	f(i,0,e)
	{
		cin>>graph[i].src>>graph[i].des>>graph[i].weight;
	}
	kruskal(graph,v,e);
}