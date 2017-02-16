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
void zigzag(int arr[],int n)
{
	int i,j,k,flag=0;
	f(i,0,n-1)
	{
		if(flag == 0)
		{
			if(arr[i] > arr[i+1])
				swap(&arr[i],&arr[i+1]);
			flag=1;
		}
		else
		{
			if(arr[i+1] > arr[i])
				swap(&arr[i],&arr[i+1]);
			flag=0;
		}
	}
	f(i,0,n)
	cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int arr[n];
	f(i,0,n)
	cin>>arr[i];
	zigzag(arr,n);
}