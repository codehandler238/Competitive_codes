#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 100005
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define sn struct node
int st[4*MAX],lazy[4*MAX];
void produce(int index,int low,int high)
{
	if(low == high)
	{
		st[index]=0;
		return;
	}

	int mid=(low+high)/2;
	produce(2*index,low,mid);
	produce(2*index+1,mid+1,high);

	st[index]=st[2*index]+st[2*index+1];
}
void update(int index,int low,int high,int qs,int qt)
{
	int count;
	if(lazy[index] == 1)
	{
		count=high-low+1;
		st[index]=count-st[index];
		if(low != high)
		{
			lazy[2*index]=(lazy[2*index]+1)%2;
			lazy[2*index+1]=(lazy[2*index+1]+1)%2;
		}
		lazy[index]=0;
	}
	if(qt<low || qs>high)
		return;

	if(qs<=low && qt>=high)
	{
		count=high-low+1;
		st[index]=count-st[index];
		if(low != high)
		{
			lazy[2*index]=(lazy[2*index]+1)%2;
			lazy[2*index+1]=(lazy[2*index+1]+1)%2;
		}
		return;
	}
	int mid=(low+high)/2;
	update(2*index,low,mid,qs,qt);
	update(2*index+1,mid+1,high,qs,qt);
	st[index]=st[2*index]+st[2*index+1];
}
int query(int index,int low,int high,int qs,int qt)
{
	int count;

	if(qs>high || qt<low)
		return 0;

	if(lazy[index]==1)
	{
		count=high-low+1;
		st[index]=count-st[index];
		if(low != high)
		{
			lazy[2*index]=(lazy[2*index]+1)%2;
			lazy[2*index+1]=(lazy[2*index+1]+1)%2;
		}
		lazy[index]=0;
	}
	if(qs<=low && qt>=high)
		return st[index];

	int mid=(low+high)/2,left,right;
	left=query(2*index,low,mid,qs,qt);
	right=query(2*index+1,mid+1,high,qs,qt);
	return (left+right);
}
int main()
{
	int i,j,k,m,n,t,ans,l,h;
	si(n);
	si(m);
	produce(1,1,n);
	while(m--)
	{
		si(k);
		if(k == 0)
		{
			//update
			si(l);
			si(h);
			l++;
			h++;
			update(1,1,n,l,h);
		}
		else
		{
			si(l);
			si(h);
			l++;
			h++;
			ans=query(1,1,n,l,h);
			cout<<ans<<endl;
		}
	}
}
/*
in update return condtion must occur AFTER lazy condition is checked but in query first return condtion is checked.
In update st=fun(left,right) is done but in query only thing is returned.
*/