#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 100000000007
#define MAX 200005
#define MAX1 200005
#define PI 3.14159265
#define LN 19
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
vector<vector<lli> >graph(MAX);
lli Level[MAX],dp[19][MAX];
void DFS(lli src,lli prv)
{
	lli i;

	vector<lli>::iterator it;

	for(i=1;i<LN;i++)
		dp[i][src]=dp[i-1][dp[i-1][src]];

	for(it=graph[src].begin();it!=graph[src].end();it++)
	{
		if(*it != prv)
		{
			dp[0][*it]=src;
			Level[*it]=Level[src]+1;
			DFS(*it,src);
		}
	}

}
lli get_lca(lli u,lli v)
{
    lli i,k,j;
    
    cout<<"u v "<<u<<" "<<v<<endl;
    if(Level[u] > Level[v])
		swap(u,v);

    lli lg;
	
	for(lg=0;(1<<lg)<=Level[v];lg++);
		lg--;

	for(i=lg;i>=0;i--)
	{
		if(Level[v]-(1<<i) >= Level[u])
			v=dp[i][v];
	}
	cout<<"u v "<<u<<" "<<v<<endl;
    if(u == v)
        return u;
    
	for(i=lg;i>=0;i--)
	{
			if(dp[i][u]!=-1 && dp[i][u] != dp[i][v])
			{
				u=dp[i][u];
				v=dp[i][v];
			}
	}
	cout<<"u v "<<u<<" "<<v<<endl;
    return dp[0][v];
}
int main()
{
	lli i,j,k,m,n,t,u,v,q;

	slli(n);

	f(i,0,n-1)
	{
		slli(u);
		slli(v);

		graph[u].pb(v);
		graph[v].pb(u);
	}

	Level[1]=0;
	dp[0][1]=1;
	DFS(1,-1);

	cout<<"Enter queries\n";
	while(1)
	{
		slli(u);
		slli(v);

		cout<<get_lca(u,v);
	}
}