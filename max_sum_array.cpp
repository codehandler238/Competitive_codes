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
lli max_sum(lli arr[],lli n)
{
	lli i,j,k,dp[n+1],m;

	if(n==1)
		return arr[1];
	
	if(n==2)
		return max(arr[1],arr[2]);
	
	dp[1]=arr[1];
	dp[2]=max(arr[1],arr[2]);

	for(i=3;i<=n;i++)
	{
		m=-INF;
		for(j=1;j<=i-2;j++)
		{
			if(dp[j]>m)
				m=dp[j];
		}
		dp[i]=max(arr[i]+m,dp[i-1]);
	}
	m=-INF;
	f(i,1,n+1)
	{
		if(dp[i]>m)
			m=dp[i];
	}
	return m;
}
int main()
{
	lli ans,i,j,k,m,n,t,arr[105];
	slli(t);
	while(t--)
	{
		slli(n);
		f(i,1,n+1)
		slli(arr[i]);
		ans=max_sum(arr,n);
		cout<<ans<<endl;
	}
}