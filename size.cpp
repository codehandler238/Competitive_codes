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
void shift(int index,int l,char *str)
{
	char a,b,tmp;
	int i,j;

	a=str[index];
	b=str[index+1];

	for(i=index+2;i<l;i++)
	{
		tmp=str[i];
		str[i]=a;
		a=b;
		b=tmp;
	}
}
void fun(char *str,int l)
{
	int i,j,k;
	f(i,0,l)
	{
		if(str[i] == ' ')
		{
			l=l+2;
			shift(i+1,l,str);
			str[i]='%';
			str[i+1]='2';
			str[i+2]='0';
		}
	}
	f(i,0,l)
	cout<<str[i];

	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t,l;
	char str[100];
	scanf("%[^\n]s",str);
	cout<<str<<endl;
	cin>>l;
	fun(str,l);

}