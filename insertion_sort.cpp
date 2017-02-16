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
void inserton_sort(int arr[],int low,int high)
{
	int i,j,k,n=high+1,key;
	f(i,1,n)
	{
		k=i-1;
		key=arr[i];
		while(k>=0 && arr[k] > key)
		{
			arr[k+1]=arr[k];
			k--;
		}
		arr[k+1]=key;
	}
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
    int arr[n+1];

    f(i,0,n)
    cin>>arr[i];

    inserton_sort(arr,0,n-1);
    f(i,0,n)
    cout<<arr[i]<<" ";
    cout<<endl;
}