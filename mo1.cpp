/*number of different elements in a given range DQUERY SPOJ*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 30005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
#define PP pair<pair<int,int>,int>
set<int>Set;
vector< PP >v;
int mp1[1000005],mp[1000005];
int arr[MAX],block;

bool cmp(PP p1,PP p2)
{
	if(p1.first.first/block != p2.first.first/block)
		return (p1.first.first/block < p2.first.first/block);

	return (p1.first.second < p2.first.second);
}

void process(int n,int q)
{
	int index,i,j,k,m,ans,curL,curR,cursum,L,R;

	block=sqrt(n);

	sort(v.begin(),v.end(),cmp);

	curL=0;
	curR=0;
	cursum=0;
	ans=0;

	f(i,0,q)
	{
		L=v[i].first.first;
		R=v[i].first.second;
		index=v[i].second;

		while(curL < L)
		{
			mp1[arr[curL]]--;
			if(!mp1[arr[curL]])
				ans--;
			curL++;
		}

		while(curL > L)
		{
			if(mp1[arr[curL-1]]==0)
				ans++;
			mp1[arr[curL-1]]++;
			curL--;
		}

		while(curR <= R)
		{
			if(mp1[arr[curR]]==0)
				ans++;
			mp1[arr[curR]]++;
			curR++;
		}

		while(curR > R+1)
		{
			mp1[arr[curR-1]]--;
			if(!mp1[arr[curR-1]])
				ans--;
			curR--;
		}

		mp[index]=ans;
	}
}
int main()
{
	int i,j,k,m,n,t,q,l,r;
	
	f(i,0,1000005)
	mp1[i]=0;

	si(n);

	f(i,0,n)
	si(arr[i]);

	si(q);
	f(i,0,q)
	{
		si(l);
		si(r);
		l--;
		r--;
		v.pb(mp(mp(l,r),i));
	}
	process(n,q);

	f(i,0,q)
	printf("%d\n",mp[i]);
}