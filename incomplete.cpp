#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 500005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
lli arr[MAX],Sum[MAX];
lli dp[1005][1005],prefix[1005][1005];
lli compute(lli p,lli q)
{
	lli i,j,sum=0;

	sum=Sum[q]-(p!=0?(Sum[p-1]):0);
	return sum;
}
lli fun(string str)
{
	lli tmp,i,j,k,m,n=str.length(),ans,current,sum,index;
	f(i,0,n)
	{
		arr[i]=str[i]-'0';
		Sum[i]=i!=0?arr[i]+Sum[i-1]:arr[i];
 	}

	f(i,0,n)
	{
		f(j,0,n){
		dp[i][j]=0;
		prefix[i][j]=0;
		}
	}
	f(j,0,n){
	dp[0][j]=1;
	prefix[0][j]=1;
	}

	for(i=1;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			current=compute(i,j);
			tmp=Sum[i-1]-current;
			index=upper_bound(Sum,Sum+n,tmp)-Sum;
			cout<<current<<" "<<tmp<<" "<<index<<" ";
			//if(Sum[index]==tmp)
			//	dp[i][j]=prefix[i-1]-(index!=0?prefix[index-1]:0);
			//else
			if(current>=Sum[i-1])
				dp[i][j]=prefix[i-1][i-1];
			else
			{cout<<"s";
				//if(index!=0 && Sum[index-1]==tmp)index--;
				if(current==tmp)
					dp[i][j]=prefix[i-1][i-1]-(prefix[index][i-1]);
				else	
					dp[i][j]=prefix[i-1][i-1]-(index+1<=i-1)?(prefix[index+1][i-1]):0;
			}
			cout<<dp[i][j]<<endl;
			/*for(k=i-1;k>=0;k--)
			{
				sum=compute(k,i-1);
				if(sum<=current)
					dp[i][j]+=dp[k][i-1];
				else
					break;
			}*/
			prefix[i][j]=dp[i][j]+prefix[i-1][j];
		}
	}
	ans=0;
	f(i,0,n)
	ans+=dp[i][n-1];

	return ans;
}
int main()
{
	lli i,j,k,m,n,t,ans,count=1;
	string str;
	while(1)
	{
		cin>>str;
		if(str=="bye")
			break;
		ans=fun(str);
		cout<<count<<". "<<ans<<endl;
		count++;
	}
}