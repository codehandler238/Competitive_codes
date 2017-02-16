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
int distance_cover(int dis)
{
	int dp[dis+1],i;

	dp[0]=1;
	dp[1]=1;
	dp[2]=2;

	for(i=3;i<=dis;i++)
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];

	return dp[dis];
}
int main()
{
	int i,j,k,m,n,t;	

	cin>>m;
	cout<<"no. of ways are "<<distance_cover(m)<<endl;
}