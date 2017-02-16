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
int fun(int arr[][100],int i,int j,int n,int m,int dp[][100])
{
	int a=1,b=1,c=1,d=1;
    
    if(dp[i][j] != 0)
    	return dp[i][j];

	if(i+1 < n)
	{
		if(arr[i+1][j] - arr[i][j] == -1)
			a=1+fun(arr,i+1,j,n,m,dp);
	}
	if(j+1 < n)
	{
		if(arr[i][j+1] - arr[i][j] == -1)
			b=1+fun(arr,i,j+1,n,m,dp);
	}
	if(i-1 >= 0)
	{
		if(arr[i-1][j] - arr[i][j] == -1)
			c=1+fun(arr,i-1,j,n,m,dp);
	}
	if(j-1 >= 0)
	{
		if(arr[i][j-1] - arr[i][j] == -1)
			d=1+fun(arr,i,j-1,n,m,dp);
	}
	dp[i][j] = max(max(a,b),max(c,d));

	return dp[i][j];
}
int get_max(int arr[][100],int n,int m)
{
	int i,j,k,Max=0,dp[n+1][100];
	
	f(i,0,n)
	f(j,0,m)
	dp[i][j]=0;

	f(i,0,n)
	{
		f(j,0,m)
		{
			if(dp[i][j] == 0)
			Max=max(Max,fun(arr,i,j,n,m,dp));
		}
	}

	return Max;
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n>>m;
	int arr[n+1][100];
	f(i,0,n)
	{
		f(j,0,m)
		cin>>arr[i][j];
	}
	cout<<get_max(arr,n,m)<<endl;
}