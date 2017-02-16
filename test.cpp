#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 100000000007
#define MAX 200005
#define MAX1 200005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
sn{
	lli L,R,L1,index;
}brr[2*MAX1+5];

struct node1{
	lli start,end,level,par;
}data[MAX];

vector<vector<lli> >graph(MAX);
lli cur_time,weight[MAX],Time[MAX],block,final[MAX];
lli Map1[MAX],Map2[MAX];

bool cmp(sn s1,sn s2)
{
	if(s1.L/block != s2.L/block)
		return (s1.L/block < s2.L/block);

	return (s1.R < s2.R);
}

void DFS(lli src,lli prv)
{
	vector<lli>::iterator it;

	data[src].start=++cur_time;
	Time[cur_time]=src;

	for(it=graph[src].begin();it!=graph[src].end();it++)
	{
		if(*it != prv)
		{
			data[*it].par=src;
			data[*it].level=data[src].level+1;
			DFS(*it,src);
		}
	}

	data[src].end=++cur_time;
	Time[cur_time]=src;
}

lli get_lca(lli u,lli v)
{
	if(u == v)
		return u;

	if(data[u].start > data[v].start)
		swap(u,v);

	if(data[v].start > data[u].start && data[v].end < data[u].end)
		return u;

	while(1)
	{
		if(data[v].start > data[u].start && data[v].end < data[u].end)
			return u;

		u=data[u].par;
	}
}

void remove1(lli &curL,lli &L,lli &count)
{
	lli current;

	while(curL < L)
	{
		current=Time[curL];

		Map1[current]--;
		Map2[weight[current]]--;

		if(Map2[weight[current]] == 0)
			count--;

		curL++;
	}
}

void add1(lli &curL,lli &L,lli &count)
{
	lli current;

	while(curL > L)
	{
		current=Time[curL-1];
		Map1[current]++;
		Map2[weight[current]]++;

		if(Map2[weight[current]] == 1)
			count++;

		if(Map1[current] == 2){
			count--;
		}
		curL--;
	}
}

void add2(lli &curR,lli &R,lli &count)
{
	lli current;

	while(curR <= R)
	{
		current=Time[curR];
		Map1[current]++;
		Map2[weight[current]]++;

		if(Map2[weight[current]] == 1)
			count++;

		if(Map1[current] == 2)
			count--;

		curR++;
	}
}
void remove2(lli &curR,lli &R,lli &count)
{
	lli current;

	while(curR > R+1)
	{
		current=Time[curR-1];

		Map1[current]--;
		Map2[weight[current]]--;

		if(Map2[weight[current]] == 0)
			count--;

		curR--;
	}
}
void Fun1(lli n,lli q)
{
	lli i,j,k,m,L,R,curL,curR,cursum,count=0,ans,cur;

	curL=0;
	curR=0;
	cursum=0;
	map<lli,lli>Map;

	f(i,0,q)
	{
		L=brr[i].L;
		R=brr[i].R;

		//while(curL < L)
		//{
		remove1(curL,L,count);
		//cursum-=Time[curL];
		/*cur=Time[curL];
		  Map[weight[cur]]--;
		  if(Map[weight[cur]] == 0)
		  count--;
		  curL++;*/
		//}

		//while(curL > L)
		//{
		add1(curL,L,count);
		//cursum+=Time[curL-1];
		//cur=Time[curL-1];
		//Map[weight[cur]]++;
		//if(Map[weight[cur]] == 1)
		//  count++;
		//else if(Map[Time[curL-1]] == 2)
		//      count--;
		//  curL--;
		//}

		//while(curR <= R)
		//{
		add2(curR,R,count);
		//cursum+=Time[curR];
		//  Map[Time[curR]]++;
		//  if(Map[Time[curR]] == 1)
		//      count++;
		//  else if(Map[Time[curR]] == 2)
		//      count--;
		//  curR++;
		//}

		//while(curR> R+1)
		//{
		remove2(curR,R,count);
		//cursum-=Time[curR-1];
		//  Map[Time[curR-1]]--;
		//  if(Map[Time[curR-1]] == 0)
		///     count--;
		//  curR--;
		//}

		//lca is excluded now.
		if(brr[i].L1 != -1)
		{
			if(Map2[brr[i].L1] == 0)
				ans=(count+1);
		}
		else
			ans=count;

		final[brr[i].index]=ans;
		//cout<<"L R count"<<L<<" "<<R<<" "<<ans<<endl;
	}

	f(i,0,q)
		printf("%lld\n",final[i]);
}
void Fun(lli n,lli q)
{
	lli i,j,k,m,t,L,R;

	block=sqrt(n);

	f(i,0,q)
	{
		L=brr[i].L;
		R=brr[i].R;

		if(data[R].start < data[L].start)
			swap(L,R);

		m=get_lca(L,R);

		if(m == L || m == R)
		{
			brr[i].L=data[L].start;
			brr[i].R=data[R].start;
			brr[i].L1=-1;
		}

		else
		{
			brr[i].L=data[L].end;
			brr[i].R=data[R].start;

			brr[i].L1=data[m].start;
		}

	}

	//cout<<"ranges\n";
	//f(i,0,q)
	//cout<<brr[i].L<<" "<<brr[i].R<<" "<<brr[i].L1<<endl;

	sort(brr,brr+q,cmp);

	Fun1(n,q);

}
int main()
{
	lli i,j,k,m,n,t,q,u,v,l,r,ans;

	slli(n);
	slli(q);

	f(i,0,n)
		slli(weight[i]);

	f(i,0,n-1)
	{
		slli(u);

		slli(v);

		u--;
		v--;

		graph[u].pb(v);
		graph[v].pb(u);
	}

	cur_time=0;

	DFS(0,-1);

	//f(i,0,n)
	//cout<<i<<" "<<data[i].start<<" "<<data[i].end<<endl;

	//si(q);

	f(i,0,q)
	{
		slli(u);
		slli(v);

		u--;
		v--;

		brr[i].L=u;
		brr[i].R=v;
		brr[i].index=i;
	}

	Fun(n,q);
}
