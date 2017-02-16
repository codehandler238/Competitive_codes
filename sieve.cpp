#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int arr[MAX],brr[MAX];
void sieve()
{
	int index=0,i,j,k,m,n,t,l;

	for(i=0;i<MAX;i++)
		arr[i]=i+2;

	for(i=0;i<MAX;i++)
	{
		if(arr[i]!=0)
		{
			m=1;
			while(m*arr[i]+i<=MAX-2)
			{
				arr[m*arr[i]+i]=0;
				m++;
			}
		}
	}
	for(i=0;i<MAX;i++)
	{
		if(arr[i]!=0)
			brr[index++]=arr[i];
	}
}
int main()
{
	int i,j,k,m,n;
	sieve();
	for(i=0;i<10;i++)
		cout<<brr[i]<<" ";
	cout<<endl;
}
