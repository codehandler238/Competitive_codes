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
int special_char(char c)
{
	if(c>='a' && c<='z')
		return 0;
	
	if(c>='A' && c<='Z')
		return 0;
	
	return 1;
}
void swap(char *a,char *b)
{
	char tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void reverse(char* str)
{
	int l=strlen(str),i,j;

	i=0;
	j=l-1;

	while(i < j)
	{
		while(special_char(str[i]) && i<j)
			i++;

		while(special_char(str[j]) && j>i)
			j--;

		if(i<j)
		{
			swap(&str[i],&str[j]);
			i++;
			j--;
		}
	}
	cout<<str<<endl;
}
int main()
{
	int i,j,k,m,n,t;
	char str[100];
    scanf("%[^\n]s",str);
    reverse(str);
}