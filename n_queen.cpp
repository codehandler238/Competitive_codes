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
bool valid(int arr[][100],int row,int col,int n)
{
	int i,j,k;
	if(row == 1)
		return true;

	for(i=row-1;i>=1;i--)
	{
		if(arr[i][col] == 1)
			return false;
	}

	i=row-1;
	j=col-1;

	while(i>=1 && j>=1)
	{
		if(arr[i][j] == 1)
			return false;

		i--;
		j--;
	}

	i=row-1;
	j=col+1;

	while(i>=1 && j<=n)
	{
		if(arr[i][j] == 1)
			return false;

		i--;
		j++;
	}
	return true;
}
bool n_queen(int arr[][100],int n,int row)
{
	int i,j,k;
	bool result;
	
	if(row > n)
		return true;

	f(i,1,n+1)
	{
		if(valid(arr,row,i,n))
		{
			arr[row][i]=1;
			result=n_queen(arr,n,row+1);
			if(!result)
				arr[row][i]=0;
			else
				return true;
		}
	}

	return false;
}
int main()
{
	int i,j,k,m,n,t;
	cin>>n;
	int arr[n+1][100];
	f(i,1,n+1)
	f(j,1,n+1)
	arr[i][j]=0;

	n_queen(arr,n,1);

	f(i,1,n+1)
	{
		f(j,1,n+1)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}