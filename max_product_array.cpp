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
lli pos[MAX],neg[MAX];
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int cmp(lli a,lli b)
{
	if(a>b)
		return 1;
	else
		return 0;
}
lli max_product(lli p_size,lli n_size,lli k)
{
	lli i,j,m,n,t,current=1,a,b,p,count;
	if(k == (p_size+n_size))
	{
		f(i,0,n_size)
		current=(current*neg[i])%INF;

		f(i,0,p_size)
		current=(current*pos[i])%INF;

		return current;
	}
	sort(pos,pos+p_size,cmp);
	sort(neg,neg+n_size);

    if(p_size == 0)
    {
    	current=1;
    	if(k%2==0)
    	{
    		f(i,0,k)
    		current=(current*neg[i])%INF;
    	}
    	else
    	{
    		for(i=n_size-1;i>=n_size-k;i--)
    		{
    			current=(current*neg[i])%INF;
    		}
    	}
    	return current;
    }
	if(k==1)
	{
		a=-INF;
		b=-INF;

		if(p_size>0)
			a=pos[0];
		if(n_size>0)
			b=neg[n_size-1];

		return max(a,b);
	}
	if(k>p_size)
	{
		n=0;
		while(k>p_size && k>=2)
		{
			current=(current*neg[n]*neg[n+1])%INF;
			n+=2;
			k-=2;
		}
	}
	
	if(k == 0)
		return current;

    if(k==1)
    {
    	a=-INF;
		b=-INF;

		if(p_size>0)
			a=pos[0];
		if(n<n_size)
			b=neg[n_size-1];

		current=(current*max(a,b))%INF;
		return current;
    }
    p=0;
    n=0;
    count=0;
	while(1)
	{
		a=0;
		b=0;

		if(p<p_size-1)
			a=pos[p]*pos[p+1];

		if(n<n_size-1)
			b=neg[n]*neg[n+1];

		if(a>b)
		{
			current=(current*a)%INF;
			p+=2;
		}
		else
		{
			current=(current*b)%INF;
			n+=2;
		}
		count+=2;
		if(count==k || ((count+1)==k))
			break;
	}
	if(count!=k)
		current=(current*pos[p])%INF;
	return current;
}
int main()
{
	lli ans,i,j,k,m,n,t,p_size,n_size;
	slli(t);
	while(t--)
	{
		slli(n);
		slli(k);
        p_size=0;
        n_size=0;
		f(i,0,n)
		{
			slli(m);
			if(m>=0)
				pos[p_size++]=m;
			else
				neg[n_size++]=m;
		}
		ans=max_product(p_size,n_size,k);
		if(ans < 0)
			ans=(ans+INF)%INF;
        printf("%lld\n",ans);
	}
}