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
int min_partition(int arr[],int l)
{
	int i,j,s=0,k,diff;

	f(i,0,l)
	s+=arr[i];

	bool dp[l+1][s+1];

	f(i,0,l+1)
	dp[i][0]=true;

	f(i,1,s+1)
	dp[0][i]=false;

	f(i,1,l+1)
	{
		f(j,1,s+1)
		{
			dp[i][j]=dp[i-1][j];

			if(j>=arr[i-1])
				dp[i][j]=dp[i][j]|dp[i-1][j-arr[i-1]];
		}
	}

	for(j=s/2;j>=0;j--)
	{
		if(dp[l][j])
		{
			diff=s-2*j;
			break;
		}
	}

	return diff;
}
int main()
{
	 int i,j,k,m,n,t;
	 cin>>n;
	 int arr[n];
	 f(i,0,n)
	 cin>>arr[i];
	 cout<<min_partition(arr,n)<<endl;
}