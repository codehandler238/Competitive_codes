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
int Min(int a,int b,int c)
{
	return min(min(a,b),c);
}
int edit_distance(char str1[],char str2[],int l1,int l2,int i1,int i2)
{

	if(i1==l1 && i2==l2)
		return 0;

	if(str1[i1] == str2[i2])
		return edit_distance(str1,str2,l1,l2,i1+1,i2+1);

	if(i1!=l1 && i2!=l2)
	{
		return 1+Min(edit_distance(str1,str2,l1,l2,i1,i2+1),edit_distance(str1,str2,l1,l2,i1+1,i2),edit_distance(str1,str2,l1,l2,i1+1,i2+1));
	}
	else if(i1==l1)
	{
		return 1+edit_distance(str1,str2,l1,l2,i1,i2+1);
	}
	else return 1+edit_distance(str1,str2,l1,l2,i1+1,i2);
}
int edit_distance(char str1[],char str2[],int l1,int l2)
{
	int i,j,k,dp[l1+1][l2+1];

	f(i,0,l1+1)
	{
		f(j,0,l2+1)
		{
			if(i==0 && j==0)
				dp[i][j]=0;

			else if(str1[i-1]==str2[j-1])
				dp[i][j]=dp[i-1][j-1];

			else if(i==0)
				dp[i][j]=1+dp[i][j-1];
		
			else if(j==0)
				dp[i][j]=1+dp[i-1][j];

			else
				dp[i][j]=1+Min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	}
	return dp[l1][l2];
}
int main()
{
	int i,j,k,m,n,t;
	char str1[100],str2[100];
	scanf("%s",str1);
	scanf(" %s",str2);

	int l1=strlen(str1),l2=strlen(str2);
	cout<<edit_distance(str1,str2,l1,l2)<<endl;
}