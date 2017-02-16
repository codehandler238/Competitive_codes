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
int LIS(int arr[],int l)
{
	int i,j,k,dp[l+1];
	
	f(i,0,l)
	dp[i]=1;

	f(i,0,l)
	{
		f(j,0,i)
		{
			if(arr[j] < arr[i])
			{
				if(dp[i] <= dp[j])
					dp[i]=1+dp[j];
			}
		}
	}
	int Max=0;
	f(i,0,l)
	{
		if(dp[i]>Max)
			Max=dp[i];
	}
	return Max;
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int arr[n+1];
	f(i,0,n)
	cin>>arr[i];

	cout<<LIS(arr,n)<<endl;
}