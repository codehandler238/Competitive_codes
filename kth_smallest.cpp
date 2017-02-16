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
int get_pivot(int arr[],int low,int high)
{
	int i=-1,j,k,pivot=arr[high];
	for(j=0;j<high;j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[high],&arr[i+1]);

	return (i+1);
}
int kth_smallets(int arr[],int low,int high,int k)
{
	if(low <= high)
	{
		int index=get_pivot(arr,low,high);
		if(index == k)
			return arr[k];

		if(k < index)
			return kth_smallets(arr,low,index-1,k);

		else
			return kth_smallets(arr,index+1,high,k);
	}
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
    int arr[n+1];

    f(i,0,n)
    cin>>arr[i];
while(1){
    cin>>k;
    cout<<kth_smallets(arr,0,n-1,k-1)<<endl;}
}