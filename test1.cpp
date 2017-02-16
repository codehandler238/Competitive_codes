#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 1000005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
int graph[105][105],arr[5001][2],dis[105][105];
int dp[5001][101][3];
void floyd(int n)
{
	int i,j,k;
	f(i,1,n+1)
	{
		f(j,1,n+1)
		{
			dis[i][j]=graph[i][j];
		}
	}
	f(k,1,n+1)
	{
		f(i,1,n+1)
		{
			f(j,1,n+1)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
}
int fun(int noi,int index,int current,int k)
{
	if(index == k)
		return 0;
	
	int cost;
	
	if(dp[index][current][noi]!=-1)
		return dp[index][current][noi];

	if(noi == 0)
	{
		//cout<<"0 "<<endl;
		cost=dis[current][arr[index][0]]+fun(1,index,arr[index][0],k);
		//cout<<"0 "<<cost<<endl;
	}
	else if(noi == 1)
	{
		//cout<<"1 "<<endl;
		cost=dis[current][arr[index][1]]+fun(0,index+1,arr[index][1],k);

		if(index+1<k)
		cost=min(cost,dis[current][arr[index+1][0]]+fun(2,index,arr[index+1][0],k));
		//cout<<"1 "<<cost<<endl;
	}
	else
	{
		cost=dis[current][arr[index][1]]+fun(1,index+1,arr[index][1],k);
		//cout<<"2 "<<cost<<endl;
	}
	dp[index][current][noi]=cost;
	return cost;
}
int main()
{
	int i,j,k,c=1,m,n,t,ans,a,b,d;
	freopen("input.txt","r",stdin);
	si(t);
	while(t--)
	{
		si(n);
		si(m);
		si(k);
		f(i,1,n+1)
		{
			f(j,1,n+1)
			{
				if(i==j)
					graph[i][j]=0;
				else
					graph[i][j]=INF;
			}
		}

		f(i,0,m)
		{
			si(a);
			si(b);
			si(d);
			graph[a][b]=d;
			graph[b][a]=d;
		}
		f(i,0,k)
		{
			si(arr[i][0]);
			si(arr[i][1]);
		}
		floyd(n);
		/*f(i,1,n+1)
		{
			f(j,1,n+1)
			cout<<dis[i][j]<<" ";cout<<endl;
		}*/
		
		f(i,0,k+1)
		{
			f(j,0,n+1)
			{
				dp[i][j][0]=-1;
				dp[i][j][1]=-1;
				dp[i][j][2]=-1;
			}
		}

		ans=fun(0,0,1,k);
		if(ans>=INF)
			ans=-1;
		printf("%d\n",ans);
	}
}