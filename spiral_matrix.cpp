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
void spiral(int matrix[][100],int n,int m)
{
	int flag=0,i,j,top=0,left=0,right=m-1,bottom=n-1;

	while(left<=right && top<=bottom)
	{
		if(flag == 0)
		{
			for(i=left;i<=right;i++)
				cout<<matrix[top][i]<<" ";
		    top++;
		    flag=1;
		}
	    else if(flag == 1)
		{
			for(i=top;i<=bottom;i++)
				cout<<matrix[i][right]<<" ";
		    right--;
		    flag=2;
		}
		else if(flag == 2)
		{
			for(i=right;i>=left;i--)
				cout<<matrix[bottom][i]<<" ";
		    bottom--;
		    flag=3;
		}
		else if(flag == 3)
		{
			for(i=bottom;i>=top;i--)
				cout<<matrix[i][left]<<" ";
		    left++;
		    flag=0;
		}
	}
}
int main()
{
	int i,j,k,m,n;
	cin>>n>>m;
	int matrix[n][100];

	f(i,0,n)
	f(j,0,m)
	cin>>matrix[i][j];

	spiral(matrix,n,m);
}