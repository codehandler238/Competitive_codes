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
lli arr[MAX],visited[MAX];
vector<lli>graph[MAX],D[MAX];
map<lli,lli>d,par;
void mark_depth(lli index,lli flag)
{
	d[index]=flag;
	visited[index]=1;
	vector<lli>::iterator it;
	for(it=graph[index].begin();it!=graph[index].end();it++)
	{
		if(visited[*it] == 0)
		{
			par[*it]=index;
		    mark_depth(*it,flag+1);
	    }
	}
}
bool is_parent(lli child,lli pa)
{
	if(pa == 1)
		return true;

	if(child == pa)
		return true;

	if(d[child] <= d[pa])
		return false;

	while(par[child]!=child)
	{
		if(par[child] == pa)
			return true;
		child=par[child];
		
		if(d[child] < d[pa])
			return false;
	}

    return false;
}
int main()
{
	lli q,i,j,k,m,n,t,a,b,u,l,count;
	slli(t);
	while(t--)
	{
		slli(n);
		slli(q);
		
		f(i,1,n+1){
		slli(arr[i]);
		visited[i]=0;
	    }

        par[1]=1;
		f(i,0,n-1)
		{
			slli(a);
			slli(b);
			graph[a].pb(b);
			graph[b].pb(a);
		}
		mark_depth(1,1);
		f(i,1,n+1)
		{
			D[d[i]].pb(i);
		}
		vector<lli>::iterator it;
		while(q--)
		{
			slli(u);
			slli(l);
			count=0;
			for(it=D[l].begin();it!=D[l].end();it++)
			{
				if(is_parent(*it,u))
					count+=arr[*it];
			}
			printf("%lld\n",count);
		}
		par.clear();
		d.clear();
		f(i,0,n+1)
		{
			graph[i].clear();
			D[i].clear();
		}
	}
}