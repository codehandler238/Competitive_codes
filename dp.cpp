#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 100005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
lli prime[MAX],p[MAX];
lli GCDW(lli a,lli b,lli &x,lli &y)
{
	if(!a)
	{
		x=0;
		y=1;
		return b;
	}
	lli d=GCDW(b%a,a,y,x);

	x-=(b/a)*y;
	return d;
}
lli RevMod(lli a,lli m)
{
	lli x=0,y=0;
	GCDW(a,m,x,y);


	if(x<0)
		x+=MOD;
	
	x=x%MOD;

	return x;
}
lli power(lli a,lli b)
{
	if(b==0 || a==1)
		return 1;

	lli s=power(a,b/2);

	if(b%2==0)
	{
		return (s*s)%MOD;
	}
	else
	{
		return (((a*s)%MOD)*s)%MOD;
	}
}
int main()
{
	lli i,j,k,m,n,t,tmp,ans,num,den,count,sum;
	slli(t);
	while(t--)
	{
		slli(n);
		f(i,0,n)
		slli(prime[i]);

		f(i,0,n)
		slli(p[i]);

		num=1;
		den=1;

		f(i,0,n)
		{
			num=(num*power(prime[i],p[i]))%MOD;
			den=(den*prime[i])%MOD;
		}
		
		count=(num*RevMod(den,MOD))%MOD;
		sum=0;

		tmp=((count*(count+1))/2)%MOD;

		sum=(den*tmp)%MOD;
		
		printf("%lld\n",sum);
	}
}