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
void next_bigger(int n)
{
	int tmp,size=0,i,j;
	tmp=n;
	while(tmp!=0)
	{
		tmp=tmp/10;
		size++;
	}
	int arr[size];

	tmp=n;
	i=size-1;
	while(tmp!=0)
	{
		arr[i]=tmp%10;
		tmp=tmp/10;
		i--;
	}
	
	for(i=size-1;i>=0;i--)
	{
		for(j=size-1;j>i;j--)
		{
			if(arr[j] > arr[i])
			{
				swap(&arr[i],&arr[j]);
				sort(arr+i+1,arr+size);
			    break;	
			}
		}
		if(j!=i)
			break;
	}
	if(i==-1)
		cout<<"not possible"<<endl;
	else
	{
	f(i,0,size)
	cout<<arr[i];
	cout<<endl;
}
}
int main()
{
	int i,j,k,m,n,t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	next_bigger(n);
}
}