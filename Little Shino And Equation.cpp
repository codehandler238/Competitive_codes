/*https://www.hackerearth.com/challenge/competitive/february-clash-17/algorithm/little-shino-and-equation/*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 100000000007
#define MAX 1000005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
lli GCD(lli a,lli b,lli &x,lli &y)
{
	if(!a)
	{
		x=0;
		y=1;
		return b;
	}
	lli d=GCD(b%a,a,y,x);

	x-=(b/a)*y;

	return d;
}
lli RevMod(lli a,lli b,lli &x,lli &y)
{
	lli d=GCD(a,b,x,y);

	return d;
}
lli fun(lli x,lli y,lli a,lli b,lli m,lli r)
{
    lli tmp,ans;
    tmp=abs(x-(b/m)*r)+abs(y+(a/m)*r);
    //cout<<r<<" "<<tmp<<endl;
    return tmp;
}
int main()
{
	lli i,j,k,m,n,t,a,b,mid,d,x,y,ans,tmp,r,low,high,L,H,tmp1,tmp2;

	slli(a);
	slli(b);
	slli(d);

	x=0;
	y=0;
	m=RevMod(a,b,x,y);

	if(d%m != 0)
		printf("-1\n");

	else
	{
		x=0;
		y=0;
		RevMod(a,b,x,y);
		n=d/m;
		x*=n;
		y*=n;
		ans=MOD;
		low=-y/(a/m);
		high=x/(b/m);
        L=-1000000000;
        H=1000000000;

        int count=0;
	
        while(1)
        {
            //cout<<"L H "<<L<<" "<<H<<endl;
            mid=(L+H)/2;

            tmp=fun(x,y,a,b,m,mid);
            tmp1=fun(x,y,a,b,m,mid-1);
            tmp2=fun(x,y,a,b,m,mid+1);

            if(tmp1>=tmp && tmp2>=tmp)
            {
                ans=tmp;
                break;
            }
            else if(tmp1>tmp && tmp2<tmp)
            {
                L=mid+1;
            }
            else
                H=mid-1;
        }
        

		printf("%lld\n",ans);
	}
}
