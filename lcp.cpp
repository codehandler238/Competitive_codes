#include <bits/stdc++.h>
using namespace std;
#define lli int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 100009
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
lli dp[5005][5005],arr[5005],lcp[5005][5005],prefix[5005][5005];
bool fun(lli p,lli q,lli r,lli s)
{
	bool v1,v2;
	if(p+lcp[p][r]>q)
		return false;
	else
	{
		if(arr[p+lcp[p][r]]<arr[r+lcp[p][r]])
			return true;
		else
			return false;
	} 
}
int main()
{
	lli i,j,k,m,n,t,sum,sum1;
	string str;
	cin>>n;
	cin>>str;

	f(i,0,n)
	lcp[i][i]=INF;

	f(i,0,n)
	arr[i]=str[i]-'0';

	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>i;j--)
		{
			if(arr[i]!=arr[j])
				lcp[i][j]=0;
			else
			{
				if(j==n-1)
					lcp[i][j]=INF;
				else
					lcp[i][j]=1+lcp[i+1][j+1];
			}
		}
	}

	f(i,1,n)
	{
		f(j,0,n){
		dp[i][j]=0;
		prefix[i][j]=0;
	    }
	}

	f(i,0,n){
	dp[0][i]=1;
    prefix[0][i]=1;
    }

	f(i,1,n)
	{
		f(j,i,n)
		{
			sum=0;

			if(i>j || arr[i]==0){
				prefix[i][j]=(dp[i][j]+prefix[i-1][j]);
				if(prefix[i][j]>=INF)
					prefix[i][j]-=INF;
				continue;
			}
			
			if(2*i-j-1>=0)
			{
				if(fun(2*i-j-1,i-1,i,j))
					sum=(dp[2*i-j-1][i-1]);
				if(sum>=INF)
					sum-=INF;
			}
			
			if(2*i-j<0)
				m=0;
			else
				m=2*i-j;

			sum1=(sum+prefix[i-1][i-1]-(m>0?prefix[m-1][i-1]:0));
			
			if(sum1<0)
				sum1+=INF;

			if(sum1>=INF)
				sum1-=INF;
		
			dp[i][j]=sum1;
		    
		    prefix[i][j]=(dp[i][j]+prefix[i-1][j]);
		    if(prefix[i][j]>=INF)
		    	prefix[i][j]-=INF;
		}
	}
	sum=0;

	f(i,0,n){
	sum=(sum+dp[i][n-1]);
	if(sum>=INF)
		sum-=INF;
	}

	cout<<sum<<endl;
}