#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define slli(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
int arr[MAX],st[2*MAX+5];
void build(int index,int low,int high)
{
	if(low == high)
	{
		st[index]=arr[low];
		return;
	}
	int mid=(low+high)/2;

	build(2*index,low,mid);
	build(2*index+1,mid+1,high);

	st[index]=st[2*index]+st[2*index+1];
}
int query(int index,int low,int high,int qs,int qt)
{
	if(qs<=low && qt>=high)
		return st[index];

	if(qt<low || qs>high)
		return 0;

	int mid=(low+high)/2;

	return (query(2*index,low,mid,qs,qt)+query(2*index+1,mid+1,high,qs,qt));
}
void update(int index,int low,int high,int I,int V)
{
	if(I<low || I>high)
		return;

	if(low == high && low == I)
	{
		arr[low]=V;
		st[index]=V;
		return;
	}
	int mid=(low+high)/2;

	update(2*index,low,mid,I,V);
	update(2*index+1,mid+1,high,I,V);

	st[index]=st[2*index]+st[2*index+1];
}
int main()
{
	int v,ans,a,b,i,j,k,m,n,t,q;
	si(n);
	for(i=1;i<=n;i++)
		si(arr[i]);
	
	build(1,1,n);

	cin>>q;
	while(q--)
	{
		cin>>t;
		if(t==0)
		{
			cin>>a>>b;
			ans=query(1,1,n,a,b);
			cout<<ans<<endl;
		}
		else
		{
			cin>>a>>v;
			update(1,1,n,a,v);
		}
	}
}
