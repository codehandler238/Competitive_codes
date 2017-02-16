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
	int i,j,k,m,n,t,l,r,ans,g;
	si(n);
	f(i,0,n)
	si(arr[i]);

	f(i,0,n)
	table[i][0]=arr[i];

	for(j=1;j<=17;j++)
	{
		for(i=0;i<=n-(1<<j);i++)
		{
			table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);
		}
	}

	//main function.
	ans=0;
	for(l=0;l<n;l++)
	{
		r=l;
		g=0;
		for(i=17;i>=0;i--)
		{
			if(r+(1<<i)-1 >= n)
				continue;

			if(__gcd(g,table[r][i]) > 1)
			{
				g=__gcd(g,table[r][i]);
				r+=(1<<i);
			}
		}
		ans+=(n-r);
	}
	cout<<ans<<endl;
}
