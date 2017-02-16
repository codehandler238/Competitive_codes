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
int subset_sum(int arr[],int n,int v)
{
	int dp[n+1][v+1],i,j;

	f(i,0,n+1)
	dp[i][0]=1;

	f(i,1,v+1)
	dp[0][i]=0;

	f(i,1,n+1)
	{
		f(j,1,v+1)
		{
			dp[i][j]=dp[i-1][j];

			if(j-arr[i-1] >= 0)
				dp[i][j] |= dp[i-1][j-arr[i-1]];
		}
	}
	return dp[n][v];
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int arr[n];
	f(i,0,n)
	cin>>arr[i];
    
    cin>>m;

	cout<<subset_sum(arr,n,m)<<endl;
}