/*COT2 spoj*/
#include <bits/stdc++.h>
using namespace std;
#define lli int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 100000000007
#define MAX 200005
#define MAX1 200005
#define PI 3.14159265
#define LN 19
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
sn{
	int L,R,L1,index;
}brr[MAX1+5];

struct node1{
	int start,end,level,par;
}data[MAX];
map<lli,lli>HASH;
vector<int>graph[MAX];
lli cur_time,weight[MAX],Time[MAX],block,final[MAX];
lli Map1[MAX],Map2[MAX],Level[MAX],dp[LN][MAX];

bool cmp(sn s1,sn s2)
{
	if(s1.L/block != s2.L/block)
		return (s1.L/block < s2.L/block);

	return (s1.R < s2.R);
}

void DFS(lli src,lli prv)
{
	lli i;

	vector<lli>::iterator it;
	
	data[src].start=++cur_time;

	for(i=1;i<LN;i++)
		dp[i][src]=dp[i-1][dp[i-1][src]];
	
	Time[cur_time]=src;

	for(it=graph[src].begin();it!=graph[src].end();it++)
	{
		if(*it != prv)
		{
			dp[0][*it]=src;
			Level[*it]=Level[src]+1;
			DFS(*it,src);
		}
	}

	data[src].end=++cur_time;
	Time[cur_time]=src;
}

lli get_lca(lli u,lli v)
{
    lli i,k,j;
    
    if(Level[u] > Level[v])
		swap(u,v);

    lli lg;
	
	for(lg=0;(1<<lg)<=Level[v];lg++);
		lg--;

	for(i=lg;i>=0;i--)
	{
		if(Level[v]-(1<<i) >= Level[u])
			v=dp[i][v];
	}

    if(u == v)
        return u;
    
	for(i=lg;i>=0;i--)
	{
			if(dp[i][u]!=-1 && dp[i][u] != dp[i][v])
			{
				u=dp[i][u];
				v=dp[i][v];
			}
	}

    return dp[0][v];
}
void add(lli current,lli &count)
{
	Map1[current]++;
	Map2[weight[current]]++;

	if(Map1[current] == 2)
	{
		Map2[weight[current]]-=2;
		if(Map2[weight[current]] == 0)
			count--;
	}
	else if(Map2[weight[current]] == 1)
		count++;

	//cout<<"in add"<<current<<" "<<count<<endl;
}

void del(lli current,lli &count)
{
	Map1[current]--;

	if(Map1[current] == 1){
		Map2[weight[current]]++;

	if(Map2[weight[current]] == 1)
		count++;
	return;
	}
	Map2[weight[current]]--;
	if(Map2[weight[current]] == 0)
		count--;
}
void Fun1(lli n,lli q)
{
	lli i,j,k,m,L,R,curL,curR,cursum,count=0,ans,cur;
		//cout<<"after sorting\n";

////	for(i=0;i<q;i++)
		//cout<<brr[i].L<<" "<<brr[i].R<<endl;
	curL=0;
	curR=0;
	cursum=0;
	map<lli,lli>Map;

	f(i,0,q)
	{//cout<<"brr[i].L1 "<<brr[i].L1<<endl;
		L=brr[i].L;
		R=brr[i].R;

		while(curL < L)
		{
			del(Time[curL],count);
			curL++;
		}

		while(curL > L)
		{
			add(Time[curL-1],count);
			curL--;
		}

		while(curR <= R)
		{
			add(Time[curR],count);
			curR++;
		}

		while(curR > R+1)
		{
			del(Time[curR-1],count);
			curR--;
		}
	
		if(brr[i].L1 != -1)
		{
			//cout<<weight[brr[i].L1]<<endl;
				if(Map2[weight[brr[i].L1]] == 0){
				ans=(count+1);//cout<<brr[i].L1<<"added\n";
				}
				else
					ans=count;
		}
		else
			ans=count;

		final[brr[i].index]=ans;
		//cout<<"L R count"<<L<<" "<<R<<" "<<ans<<endl;
	}
	
	f(i,0,q)
	printf("%d\n",final[i]);
}
void Fun(lli n,lli q)
{
	lli i,j,k,m,t,L,R;

	block=sqrt(n);
	//cout<<"start end\n";
	f(i,0,q)
	{
		L=brr[i].L;
		R=brr[i].R;
		
		//cout<<data[L].start<<" "<<data[L].end<<endl;
		//cout<<data[R].start<<" "<<data[R].end<<endl;

		if(Level[R] < Level[L])
			swap(L,R);

		m=get_lca(R,L);//cout<<"baap "<<m<<endl;

		if(m == L)
		{
			brr[i].L=data[L].start;
			brr[i].R=data[R].start;
			brr[i].L1=-1;
		}

		else
		{
			if(data[L].end < data[R].start)
			{
			brr[i].L=data[L].end;
			brr[i].R=data[R].start;
			}
			else
			{
				brr[i].L=data[R].end;
				brr[i].R=data[L].start;
			}
			brr[i].L1=m;
		}

	}

	sort(brr,brr+q,cmp);

	Fun1(n,q);

}
int main()
{
	lli i,j,k,m,n,t,q,u,v,l,r,ans,no;
	
	while(scanf("%d %d",&n,&q) != EOF)
	{
	no=0;

	f(i,1,n+1)
	{
		si(weight[i]);

		if(HASH.find(weight[i]) == HASH.end())
			HASH[weight[i]]=++no;
		weight[i]=HASH[weight[i]];
	}

	f(i,0,n-1)
	{
		si(u);

		si(v);

		graph[u].pb(v);
		graph[v].pb(u);
	}

	cur_time=0;

	Level[1]=0;

	memset(Map1,0,sizeof(Map1));
	memset(Map2,0,sizeof(Map2));
	memset(dp,-1,sizeof(dp));

	dp[0][1]=1;
	DFS(1,-1);

	f(i,0,q)
	{
		si(u);
		si(v);

		brr[i].L=u;
		brr[i].R=v;
		brr[i].index=i;
	}

	Fun(n,q);
	
	f(i,0,MAX)
	graph[i].clear();

	}
}