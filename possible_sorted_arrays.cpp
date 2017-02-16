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
void print(vector<int>v)
{
	int i,j;
	f(i,0,v.size())
	cout<<v[i]<<" ";
	cout<<endl;
}
int get_index(int arr[],int size,int n)
{
	int i,j,k;
	f(i,0,size)
	{
		if(arr[i]>=n)
			return i;
	}
	return i;
}
void possible_sorted_arrays(int A[],int A_size,int B[],int B_size,int i,int flag,vector<int>&v)
{
	int j,index;
	if(flag == 0)
	{
		for(j=i;j<A_size;j++)
		{
			v.pb(A[j]);
			index=get_index(B,B_size,A[j]);
			possible_sorted_arrays(A,A_size,B,B_size,index,(flag+1)%2,v);
			v.pop_back();
		}
	}
	else
	{
	    for(j=i;j<B_size;j++)
		{
			v.pb(B[j]);
			print(v);
			index=get_index(A,A_size,B[j]);
			possible_sorted_arrays(A,A_size,B,B_size,index,(flag+1)%2,v);
			v.pop_back();
		}	
	}	
}
int main()
{
	int i,j,k,m,n,t;
	vector<int>v;
	cin>>n;
	int A[n];
	f(i,0,n)
	cin>>A[i];

    cin>>m;
    int B[m];
	f(i,0,m)
	cin>>B[i];

	possible_sorted_arrays(A,n,B,m,0,0,v);
}