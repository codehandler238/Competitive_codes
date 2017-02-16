#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 100005
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
int arr[MAX],tmp[MAX],ans[MAX];
void counting_sort(int n,int range)//Normal count_sort
{
	int i,j,k,pos;
	f(i,0,range+1)
	tmp[i]=0;

	f(i,0,n)
	tmp[arr[i]]++;

	f(i,1,range+1)
	tmp[i]+=tmp[i-1];

	f(i,0,n)
	{
		pos=tmp[arr[i]];
		ans[pos-1]=arr[i];
		tmp[arr[i]]--;
	}
	f(i,0,n)
	cout<<ans[i]<<" ";
	cout<<endl;
}
void count_sort(int n,int exp)
{
	int i,j,k,m,pos;
	f(i,0,10)
	tmp[i]=0;

	f(i,0,n)
	tmp[(arr[i]/exp)%10]++;

	f(i,1,10)
	tmp[i]+=tmp[i-1];

	for(i=n-1;i>=0;i--)
	{
		pos=tmp[(arr[i]/exp)%10];
		ans[pos-1]=arr[i];
		tmp[(arr[i]/exp)%10]--;
	}
	f(i,0,n)
	arr[i]=ans[i];
}
void radix_sort(int n)
{
	int i,j,k,m,Max=arr[0],exp;
	f(i,1,n)
	{
		if(arr[i] > Max)
			Max=arr[i];
	}
	for(exp=1;Max/exp>0;exp*=10)
		count_sort(n,exp);

	f(i,0,n)
	cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t,range;
	si(n);
	//si(range);
	f(i,0,n)
	si(arr[i]);

	//counting_sort(n,range);
	radix_sort(n);
}