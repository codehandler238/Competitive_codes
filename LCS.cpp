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
int LCS(char str1[],char str2[],int l1,int l2)
{
	int i,j,k,dp[l1+1][l2+1];

	dp[0][0]=(str1[0]==str2[0])?1:0;

	f(i,0,l1)
	{
		f(j,0,l2)
		{
			if(i==0 && j==0)continue;

			else if(i==0)
			{
				dp[i][j]=(str1[i]==str2[j])?1:dp[i][j-1];
			}

			else if(j==0)
			{
				dp[i][j]=(str1[i]==str2[j])?1:dp[i-1][j];
			}

			else if(str1[i] == str2[j])
				dp[i][j]=1+dp[i-1][j-1];

			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[l1-1][l2-1];
}
int main()
{
	int i,j,k,m,n,t;
	char str1[100],str2[100];
	scanf("%s",str1);
	scanf(" %s",str2);

	int l1=strlen(str1),l2=strlen(str2);

	int l=LCS(str1,str2,l1,l2);
	cout<<"length of LCS is : "<<l<<endl;
}