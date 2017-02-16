#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 100005
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
sn{
	int a[2];
	int b;
};
sn L[MAX];
int p[20][MAX];
bool cmp(sn r,sn s)
{
	if(r.a[0] == s.a[0])
	{
		if(r.a[1] < s.a[1])
			return 1;
		else
			return 0;
	}
	else
	{
		if(r.a[0] < s.a[0])
			return 1;
		else
			return 0;
	}
}
void suffix_array(int n,string str)//in nlog^2n
{
	int i,j,k,m,t,step=1,untill=1;

	f(i,0,n)
	p[0][i]=str[i]-'a';

	while(untill < n)
	{
		f(i,0,n)
		{
			L[i].a[0]=p[step-1][i];
			L[i].a[1]=i+untill<n?p[step-1][i+untill]:-1;
			L[i].b=i;
		}

		sort(L,L+n,cmp);

		f(i,0,n)
		{
			p[step][L[i].b]=i>0 && L[i-1].a[0]==L[i].a[0] && L[i-1].a[1]== L[i].a[1]?p[step][L[i-1].b]:i;
		}
		untill*=2;
		step++;
	}
	f(i,0,n)
	cout<<L[i].a[0]<<" "<<L[i].a[1]<<" "<<L[i].b<<endl;//b part of L is suffix array.
}
int calculate_LCP(int x,int y,int n)//indexes
{
	int ans=0,i,j,k=ceil(log2(n));
	
	if(x == y)
		return (n-x);

	for(i=k;i>=0 && x<n && y<n;i--)
	{
		if(p[i][x] == p[i][y])
		{
			ans+=1<<i;
			x+=1<<i;
			y+=1<<i;
		}
	}
	return ans;
}
int main()
{
	int i,j,k,m,n,t;
	string str;
	cin>>str;
	n=str.length();
	suffix_array(n,str);
	calculate_LCP(0,2,n);
}