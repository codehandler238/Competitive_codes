/*https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/mancunian-and-multiplicative-queries-1/*/
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
sn{
	int l,r;
}arr[MAX];
int A[MAX],func[MAX],freq[1000001],block=555,RM[1000001];
inline int input()
{
        int n = 0;
        int ch = getchar_unlocked();
        while (ch < '0' || ch > '9') ch = getchar_unlocked();
        while (ch >= '0' && ch <= '9') {
                n = (n << 3) + (n << 1) + (ch - '0');
                ch = getchar_unlocked();
        }
        return n;

}
bool cmp(sn s1,sn s2)
{
	if(s1.l/block != s2.l/block)
		return (s1.l/block < s2.l/block);

	return (s1.r < s2.r);
}
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
lli RevMod(lli a,lli b)
{
	lli x=0,y=0;
	GCDW(a,b,x,y);
	x%=b;
	if(x<0)
		x+=b;

	return x;
}
lli power(lli a,lli b)
{
	if(a == 1 || b == 0)
		return 1;

	lli s;
	s=power(a,b/2);

	if(b%2 == 0)
		return (s*s)%MOD;
	else
		return (((a*s)%MOD)*s)%MOD;
}
void preprocess(int n ,int c,int q)
{
	int i,j,k,m,temp,curL,curR,L,R,cursum=0;
	lli tmp,ans=1;

	tmp=power(func[0],c);

	//block=sqrt(n);

	sort(arr,arr+q,cmp);
	
	curL=0;
	curR=0;

	f(i,0,q)
	{
		L=arr[i].l;
		R=arr[i].r;

		while(curL < L)
		{
			cursum-=A[curL];
			
			if(freq[A[curL]]>=0)
			tmp=(tmp*RevMod(func[freq[A[curL]]],MOD))%MOD;
			freq[A[curL]]--;
			
			if(freq[A[curL]]>=0)
			tmp=(tmp*func[freq[A[curL]]])%MOD;
			curL++;
		}

		while(curL > L)
		{
			cursum+=A[curL-1];
			
			if(freq[A[curL-1]]>=0)
			tmp=(tmp*RevMod(func[freq[A[curL-1]]],MOD))%MOD;
			freq[A[curL-1]]++;
			
			if(freq[A[curL-1]]>=0)
			tmp=(tmp*func[freq[A[curL-1]]])%MOD;
			curL--;
		}

		while(curR <= R)
		{//if(i==2)cout<<"r "<<curR<<" "<<freq[A[curR]]<<endl;
			cursum+=A[curR];
			
			if(freq[A[curR]]>=0)
			tmp=(tmp*RevMod(func[freq[A[curR]]],MOD))%MOD;
			freq[A[curR]]++;
			
			//cout<<freq[A[curR]]<<endl;
			if(freq[A[curR]]>=0)
			tmp=(tmp*func[freq[A[curR]]])%MOD;
			curR++;
		}

		while(curR > R+1)
		{
			cursum-=A[curR-1];
			
			if(freq[A[curR-1]] >= 0)
			tmp=(tmp*RevMod(func[freq[A[curR-1]]],MOD))%MOD;
			freq[A[curR-1]]--;
			
			if(freq[A[curR-1]] >= 0)
			tmp=(tmp*func[freq[A[curR-1]]])%MOD;
			curR--;
		}
		ans=(ans*tmp)%MOD;
		//cout<<"cl clr "<<curL<<" "<<curR<<endl;
		//cout<<"L R "<<L<<" "<<R<<" ";
		//cout<<tmp<<endl;
	}

	printf("%lld\n",ans);
}
int main()
{
	int i,j,k,m,n,t,c,q,ans,l,r;
	sn tmp;

	//slli(n);
	//slli(c);
	//slli(q);

	n=input();
	c=input();
	q=input();

	f(i,0,n)
	A[i]=input();

	f(i,0,n+1)
	func[i]=input();


	//f(i,1,1000001)
	//{
	//	freq[i-1]=0;
		//RM[i]=power(i,MOD-2);
	//}

	f(i,0,q)
	{
		l=input();
		r=input();
		//slli(l);
		//slli(r);
		l--;
		r--;
		tmp.l=l;
		tmp.r=r;
		arr[i]=tmp;
	}

	preprocess(n,c,q);

}