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
int find_triplet(int arr[],int n,int sum)
{
	if(n<=2)
		return 0;

	int i,j,k,ans=0;

	f(i,0,n-2)
	{
		j=i+1;
		k=n-1;

		while(j<k)
		{
			if((arr[i]+arr[j]+arr[k])>=sum)
				k--;

			else
			{
				ans+=(k-j);
				j++;
			}
		}
	}

	return ans;
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int arr[n];

	f(i,0,n)
	cin>>arr[i];

	cin>>m;

	cout<<find_triplet(arr,n,m)<<endl;
}