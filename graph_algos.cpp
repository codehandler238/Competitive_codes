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
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void DFS(vector<int>graph[],int visited[],int src)
{
	visited[src]=1;

	cout<<src<<" ";

	vector<int>::iterator it;

	for(it=graph[src].begin();it!=graph[src].end();it++)
	{
		if(visited[*it] == 0)
			DFS(graph,visited,*it);
	}
}
void BFS(vector<int>graph[],int visited[],int src)
{
	int tmp;
	queue<int>qu;
	vector<int>::iterator it;
	visited[src]=1;
	qu.push(src);

	while(!qu.empty())
	{
		tmp=qu.front();
		qu.pop();
		cout<<tmp<<" ";

		for(it=graph[tmp].begin();it!=graph[tmp].end();it++)
		{
			if(visited[*it]==0){
				visited[*it]=1;
				qu.push(*it);
			}
		}
	}
}
bool check_cycle_util(std::vector<int> graph[],int src,int visited[],int recstack[])
{
    	bool a;
		visited[src]=1;
		recstack[src]=1;

		vector<int>::iterator it;

		for(it=graph[src].begin();it!=graph[src].end();it++)
		{
			if(visited[*it]==0)
				a=check_cycle_util(graph,*it,visited,recstack);

			if(recstack[*it]==1)
				return true;

			if(a)
				return a;
		}
	
	recstack[src]=0;
	return false;
}
void check_cycle(std::vector<int> graph[],int v,int e,int visited[])
{
	int recstack[v+1],i;
	f(i,1,v+1)
	recstack[i]=0;

	f(i,1,v+1)
	{
		if(visited[i]==0)
		{
			if(check_cycle_util(graph,i,visited,recstack))
				break;
		}
	}
	if(i==v+1)
		cout<<"No cycle is present"<<endl;
	else
		cout<<"cycle is present"<<endl;
}
int main()
{
	int i,j,k,m,n,t,v,e,v1,v2,src;
	cin>>v>>e;
	int visited[v+1];

	f(i,1,v+1)
	visited[i]=0;

	std::vector<int> graph[v+1];

	f(i,0,e)
	{
		cin>>v1>>v2;
		graph[v1].pb(v2);
		//graph[v2].pb(v1);
	}
	//cout<<"Enter source vertex : "<<endl;
	//cin>>src;

	//BFS(graph,visited,src);//only those verteces are visited which are reachable from source vertex.
      check_cycle(graph,v,e,visited);
}