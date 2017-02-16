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
	int src,des;
};
struct Set{
	int par,rank;
};
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
};
int find_par(struct Set subset[],int i)
{
	while(subset[i].par != i)
		i=subset[i].par;

	return i;
}
void check_cycle(sn graph[],struct Set subset[],int e)
{
	int i,j,k,xroot,yroot;
	f(i,1,e+1)
	{
		xroot=find_par(subset,graph[i].src);
		yroot=find_par(subset,graph[i].des);

		if(xroot == yroot)
			break;

		if(subset[xroot].rank < subset[yroot].rank)
			subset[xroot].par=yroot;


		else if(subset[xroot].rank > subset[yroot].rank)
			subset[yroot].par=xroot;

		else
		{
			subset[xroot].par=yroot;
			subset[yroot].rank+=1;
     	}
	}
	if(i == e+1)
		cout<<"no cycle is present"<<endl;
	else
		cout<<"cycle is present"<<endl;
}
int main()
{
	int i,j,k,m,n,t,v,e;
	cin>>v>>e;
	sn graph[e+1];
	struct Set subset[v+1];

	f(i,1,e+1)
	{
		cin>>graph[i].src>>graph[i].des;
	}
	f(i,1,v+1)
	{
		subset[i].par=i;
		subset[i].rank=0;
	}
	check_cycle(graph,subset,e);
}