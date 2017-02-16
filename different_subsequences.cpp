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
void different_subsequences(char *str)
{
	int i,j,k,l=strlen(str);
	int sum[l+1],last[27],dp[l+1];
	
	f(i,0,27)
	last[i]=0;

    dp[0]=0;
    sum[0]=1;

	f(i,1,l+1)
	{		
		if((last[str[i-1]-'a']-1)>=0)
		dp[i]=sum[i-1]-sum[last[str[i-1]-'a']-1];
	
	else
		dp[i]=sum[i-1];

		sum[i]=sum[i-1]+dp[i];
		last[str[i-1]-'a']=i;

	}
	cout<<sum[l]<<endl;
}
int main()
{
	int i,j,k,m,n,t;
	char str[100];
	scanf(" %s",str);
	different_subsequences(str);
}