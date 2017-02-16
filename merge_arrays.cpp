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
void arrange(int brr[],int l2)
{
	int i,cur;
	cur=brr[0];

	f(i,1,l2)
	{
		if(brr[i] < cur)
			brr[i-1]=brr[i];

		else
		{
			brr[i-1]=cur;
			return;
		}
	}
	brr[i-1]=cur;
}
void merge(int arr[],int l1,int brr[],int l2)
{
	int i=0,j=0;
    while(i < l1)
        	while(i<l1 && arr[i]<=brr[j])
    		i++;

    	swap(&arr[i],&brr[j]);

    	arrange(brr,l2);

    	i++;
    }
    f(i,0,l1)
    cout<<arr[i]<<" ";
    cout<<endl;

    f(i,0,l2)
    cout<<brr[i]<<" ";
    cout<<endl;
}
int main()
{
	int i,j,k,m,n,t,l1,l2;
	cin>>l1;
	int arr[l1+1];

	f(i,0,l1)
	cin>>arr[i];

	cin>>l2;
	int brr[l2+1];

	f(i,0,l2)
	cin>>brr[i];

	merge(arr,l1,brr,l2);
}