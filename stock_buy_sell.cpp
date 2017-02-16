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
int max_profit(int price[],int state,int i,int dp[][2],int n)
{
	if(i == n)
		return 0;
    
    if(dp[i][state] != 0)
    	return dp[i][state];

    int a;

	if(state == 0)
		a=max(max_profit(price,1,i+1,dp,n)-price[i],max_profit(price,0,i+1,dp,n));

	else
		a=max(max_profit(price,0,i+1,dp,n)+price[i],max_profit(price,1,i+1,dp,n));

    dp[i][state]=a;
	
	return a;
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int price[n],dp[n+1][2];

	f(i,0,n)
	{
		dp[i][0]=0;
		dp[i][1]=0;
	    cin>>price[i];
    }

	cout<<max_profit(price,0,0,dp,n)<<endl;
}