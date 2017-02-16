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
void merge(int arr[],int low1,int high1,int low2,int high2)
{
	int size=high1-low1+high2-low2+2;
	int tmp[size+1],i,j,k;

	i=low1;
	j=low2;
	k=0;

	while(i<=high1 && j<=high2)
	{
		if(arr[i] <= arr[j])//here due to = it is stable sort otherwise it will be unstable.
			tmp[k++]=arr[i++];

		else
			tmp[k++]=arr[j++];
	}
	while(i<=high1)
		tmp[k++]=arr[i++];

	while(j<=high2)
		tmp[k++]=arr[j++];

    j=low1;

	for(i=0;i<k;i++)
		arr[j++]=tmp[i];
}
void merge_sort(int arr[],int low,int high)
{
	if(low>=high)
		return;

	int mid=(low+high)/2;

	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,high);
	merge(arr,low,mid,mid+1,high);
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
    int arr[n+1];

    f(i,0,n)
    cin>>arr[i];

    merge_sort(arr,0,n-1);
    
    f(i,0,n)
    cout<<arr[i]<<" ";
    cout<<endl;
}