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
	map<string,int>mp;
	cin>>n;
	char c;

	f(i,0,n)
	{
		cin>>str;
		mp[str]=i;
	}
	map<string,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	string tmp;
	cin>>tmp;

	it=mp.find(tmp);
	cout<<it->second<<" "<<mp[tmp]<<endl;
	
	it=mp.lower_bound(tmp);
	cout<<it->first<<endl;
	it=mp.upper_bound(tmp);
	cout<<it->first<<endl;
}