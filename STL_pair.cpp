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
int main()
{
	int i,j,k,m,n,t;
	string str;
	pair<string,int>p;
	map< pair<string,int>,int >mp;
	map< pair<string,int>,int >::iterator it;
	cin>>n;
	f(i,0,n)
	{
		cin>>str;
		cin>>m;
		p.first=str;
		p.second=m;
		mp[p]=i;
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<(it->first).first<<" "<<(it->first).second<<" "<<it->second<<endl;
	}
}