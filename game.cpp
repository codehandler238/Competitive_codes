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
int game(int arr[],int i,int j,int dp[][100])
{
	if(i == j)
		return arr[i];

	if(j == i+1)
		return max(arr[i],arr[j]);

	if(dp[i][j] != 0)
		return dp[i][j];

	int a,b;

	a=arr[i]+min(game(arr,i+2,j,dp),game(arr,i+1,j-1,dp));
	b=arr[j]+min(game(arr,i,j-2,dp),game(arr,i+1,j-1,dp));

	dp[i][j]=max(a,b);

	return dp[i][j];
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int arr[n],dp[n][100];

	f(i,0,n)
	f(j,0,n)
	dp[i][j]=0;

	f(i,0,n)
	cin>>arr[i];

	cout<<game(arr,0,n-1,dp)<<endl;
}