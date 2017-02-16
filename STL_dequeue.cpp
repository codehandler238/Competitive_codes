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
void fun(int arr[],int w,int n)
{
	int i,j,k,m,t;
	deque<int>dq;
	dq.clear();

	f(i,0,w)
	{
		if(dq.empty())
			dq.push_back(i);
		else
		{
            while(!dq.empty() && arr[i]>arr[dq.back()])
			dq.pop_back();

		    dq.push_back(i);
	    }
	}
	
	f(i,w,n)
	{
		cout<<arr[dq.front()]<<" ";

		while(dq.front() <= (i-w))
			dq.pop_front();

		while(!dq.empty() && arr[i]>arr[dq.back()])
			dq.pop_back();

		dq.push_back(i);
	}
	while(!dq.empty())
	{
		cout<<arr[dq.front()];
		dq.pop_front();
	}
	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int arr[n];

	f(i,0,n)
	cin>>arr[i];

	scanf("%d",&m);

	fun(arr,m,n);
}