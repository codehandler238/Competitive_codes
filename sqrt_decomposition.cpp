#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 100005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
#define M 1000
int arr[MAX],block[M];
int bsize;
void preprcess(int n)
{
	int i,j,k,index=0;
	bsize=sqrt(n);
	f(i,0,n)
	{
		if(i!=0 && i%bsize == 0){
			index++;
		}
		block[index]+=arr[i];
	}
}
void update(int n,int index,int v)
{
	int b=index/bsize;
	block[b]=block[b]-arr[index]+v;
	arr[index]=v;
}
int query(int l,int r,int n)
{
	int i,j,k,sum=0;

	while(l!=0 && l%bsize != 0 && l<r)
	{
		sum+=(arr[l]);
		l++;
	}

	while((l+bsize)<=r)
	{
		sum+=(block[l/bsize]);
		l+=bsize;
	}

	while(l<=r)
	{
		sum+=arr[l];
		l++;
	}

	return sum;

}
int main()
{
	int i,j,k,m,n,t,q,l,r,ans,v,index;
	si(n);
	f(i,0,n)
	si(arr[i]);

	preprcess(n);

	si(q);
	while(q--)
	{
		si(m);
		if(m == 0)//query
		{
			si(l);
			si(r);
			ans=query(l,r,n);
			cout<<ans<<endl;
		}
		else
		{
			si(index);
			si(v);
			update(n,index,v);
		}
	}
}