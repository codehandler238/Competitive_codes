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
void compress(char str[])
{
	int i=0,j,k,m,n,l,benifit=0,count;
	char cur,tmp,new_str[100];
	l=strlen(str);

	while(i<l)
	{
		cur=str[i];
		count=0;
		while(str[i] == cur && i<l)
		{
			i++;
			count++;
		}
		benifit+=(count-2);
	}
	if(benifit<0)
		cout<<"no need to compress"<<endl;

	else
	{
		i=0;
		j=0;
		while(j<l)
		{
			cur=str[j];
			count=0;
			while(str[j] == cur && j<l)
			{
				j++;
				count++;
			}

			new_str[i]=cur;
			new_str[i+1]=count+'0';
			i+=2;
		}
		for(j=0;j<i;j++)
			cout<<new_str[j];

		cout<<endl;
	}
}
int main()
{
	int i,j,k,m,n,t;
	char str[100];
	cin>>str;
	compress(str);
}