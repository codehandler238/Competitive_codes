/*https://www.codechef.com/problems/TOURISTS*/
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
int in[MAX],out[MAX],visited[MAX];
map<int,pair<int,int> >Map;
map<pair<int,int>,int>Index;
vector<int>graph[MAX];
void DFS(int src)
{
    visited[src]=1;
    vector<int>::iterator it;

    for(it=graph[src].begin();it!=graph[src].end();it++)
    {
        if(visited[*it] == 0)
        {
            DFS(*it);
        }
    }
}
bool is_connected(int src,int n)
{
    int i,j,k;

    f(i,1,n+1)
    visited[i]=0;

    DFS(1);

    f(i,1,n+1)
    {
        if(visited[i] == 0)
            return false;
    }
    return true;
}
bool check(int n)
{
	int i,j,k;

	f(i,1,n+1)
	{
		if((in[i]+out[i])%2 !=0 || (in[i] == 0 && out[i] == 0))
			return false;
	}

	if(!is_connected(1,n))
		return false;

	return true;
}
void dfs(int src)
{	
	int m,u,v,i;

	vector<int>::iterator it,it1;
	for(it=graph[src].begin();it!=graph[src].end();it++)
	{
		m=*it;

        if(Index.find(mp(src,m)) != Index.end()){
		i=Index[mp(src,m)];
        Index.erase(mp(src,m));
        }

        else{
            i=Index[mp(m,src)];
            Index.erase(mp(m,src));
        }

		Map[i]=mp(src,m);

		it1=find(graph[src].begin(),graph[src].end(),m);
		graph[src].erase(it1);

		it1=find(graph[m].begin(),graph[m].end(),src);
		graph[m].erase(it1);

		dfs(m);
		if(graph[src].size( )== 0)
			return;
		
	}
}
int main()
{
	int i,j,k,m,n,t,e,v,u;
	map<int,pair<int,int> >::iterator it;

	si(n);
	si(e);

	f(i,1,n+1)
	{
		in[i]=0;
		out[i]=0;
		visited[i]=0;
	}

	f(i,0,e)
	{
		si(u);
		si(v);

		graph[u].pb(v);
		graph[v].pb(u);
		Index[mp(u,v)]=i;
		out[u]++;
		in[v]++;
	}

	if(!check(n))
	cout<<"NO\n";

	else
	  {
	  dfs(1);
	  cout<<"YES\n";
	  for(it=Map.begin();it!=Map.end();it++)
	  cout<<it->second.first<<" "<<it->second.second<<endl;
	  }
} 
