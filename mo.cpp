#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 100005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
vector<pair<lli,lli> >qu;
lli arr[MAX],block;
bool cmp(pair<lli,lli>p1,pair<lli,lli>p2)
{
	if(p1.first/block != p2.first/block)
		return (p1.first/block < p2.first/block);

	else
		return (p1.second < p2.second);
}

lli process(lli n,lli q)
{
	lli i,j,k,m,curL,curR,cursum,L,R;
	
	block=sqrt(n);

	sort(qu.begin(),qu.end(),cmp);

	curL=0;
	curR=0;
	cursum=0;

	f(i,0,q)
	{
		L=qu[i].first;
		R=qu[i].second;

		while(curL < L)
		{
			cursum-=arr[curL];
			curL++;
		}

		while(curL > L)
		{
			cursum+=arr[curL-1];
			curL--;
		}

		while(curR <= R)
		{
			cursum+=arr[curR];
			curR++;
		}

		while(curR > R+1)
		{
			cursum-=arr[curR-1];
			curR--;
		}

	}
	return cursum;
}

int main()
{
	lli i,j,k,m,n,t,q,l,r;
	slli(n);

	f(i,0,n)
	slli(arr[i]);

	slli(q);
	f(i,0,q)
	{
		slli(l);
		slli(r);
		qu.pb(mp(l,r));
	}

	process(n,q);
}