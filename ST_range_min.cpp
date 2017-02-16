#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 100005
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define sn struct node
int arr[MAX],table[MAX][17];
int main()
{
	int i,q,j,k,m,n,t,l,r,ans;
	si(n);
	si(q);
	f(i,0,n)
	si(arr[i]);

	f(i,0,n)
	table[i][0]=arr[i];

	for(j=1;j<=17;j++)
	{
		for(i=0;i<=n-(1<<j);i++)
		{
			table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--)
	{ 
		si(l);
		si(r);
		l--;
		r--;
		ans=MOD;
		for(j=17;j>=0;j--)
		{
			if(l+(1<<j)-1<=r)
			{
				ans=min(ans,table[l][j]);
				l+=(1<<j);
			}
		}
		cout<<ans<<endl;
	}

}