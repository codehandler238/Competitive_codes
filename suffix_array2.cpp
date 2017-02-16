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
	lli a[2];
	lli b;
}L[MAX];
lli p[20][MAX];
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
void suffix_array(string str)
{
	lli i,j,k,m,n,t,l,step=1,untill=1;
	l=str.length();
	f(i,0,l)
	p[0][i]=str[i]-0;

	while(untill < l)
	{
		f(i,0,l)
		{
			L[i].a[0]=p[step-1][i];
			L[i].a[1]=i+untill<l?p[step-1][i+untill]:-1;
			L[i].b=i;
		}

		sort(L,L+l,cmp);

		f(i,0,l)
		{
			p[step][L[i].b]=i>0 && L[i-1].a[0]==L[i].a[0] && L[i-1].a[1]==L[i].a[1]?p[step][L[i-1].b]:i;
		}
		step++;
		untill*=2;
	}
	//f(i,0,l)
	//cout<<L[i].b<<" ";
}
lli LCP(lli x,lli y,lli l)
{
	lli i,j,k,ans=0;
	k=ceil(log2(l));

	for(i=k;i>=0&&x<l&&y<l;i--)
	{
		if(p[i][x] == p[i][y])
		{
			x+=(1<<i);
			y+=(1<<i);
			ans+=(1<<i);
		}
	}
	
	return ans;
}
lli calculate_substrings(string str)
{
	lli i,j,k,m,n,l,ans;
	l=str.length();
	ans=l-L[0].b;
	f(i,0,l-1)
	{
		ans+=(l-L[i+1].b-LCP(L[i].b,L[i+1].b,l));
	}
	return ans;
}
int main()
{
	lli i,j,k,m,n,t,l;
	string str;
	slli(t);
	while(t--)
	{
		cin>>str;
		l=str.length();
		f(i,0,l)
		{
			L[i].a[0]=0;
			L[i].a[1]=0;
			L[i].b=0;
			f(j,0,20)
			p[j][i]=0;
		}
		suffix_array(str);
		m=calculate_substrings(str);
		printf("%lld\n",m);
	}
}