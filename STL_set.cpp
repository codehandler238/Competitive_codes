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
void print(set<int>s)
{
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main()//Set have data in sorted order.
{
	int i,j,k,m,n,t;
	set<int>s;
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		s.insert(m);
	}
	set<int>::iterator it;
	print(s);

	it=s.lower_bound(3);
	cout<<*it<<endl;

	it=s.upper_bound(3);
	cout<<*it<<endl;

	it=s.begin();
	advance(it,3);

	s.erase(it);

	print(s);
	
	it=s.find(5);
	cout<<*it<<endl;
}