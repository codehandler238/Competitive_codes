#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define lli long long int
#define slli(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define f(i,a,b) for(i=a;i<b;i++)
#define MAX 300005
lli lps[MAX],arr[MAX],Ans[MAX],prefix[MAX];
void KMP(string pattern,string text)
{
	int i,j,k,n,m;
	n=text.length();
	m=pattern.length();

    i=0;
    j=0;

	while(i<n)
	{
		if(pattern[j] == text[i])
		{
			i++;
			j++;
		}

		if(j == m)
		{
			arr[i-1]=1;
			j=lps[j-1];
		}

		else if(i<n && pattern[j] != text[i])
		{
			if(j != 0)
				j=lps[j-1];
			else
				i+=1;
		}
	}
}
void calculate_LPS(string pattern)
{
	int i,j,k,m,n,len=0;
	m=pattern.length();
	lps[0]=0;
	i=1;
	while(i<m)
	{
		if(pattern[len] == pattern[i])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len != 0)
				len=lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
lli fun(lli n,lli m)
{
	lli i,j,k,t;
	f(i,0,m-1)
	{
		Ans[i]=0;
		prefix[i]=0;
	}
	f(j,i,n)
	{
		if(arr[j] != 0)
		{
			if((j-m) < 0)
				Ans[j]=1;
			else
				Ans[j]=(prefix[j-m]+1)%MOD;
		}
		prefix[j]=(prefix[j-1]+Ans[j])%MOD;
	}
	return prefix[n-1];
}
int main()
{
	lli i,j,k,m,n,t,ans;
	string text,pattern;
	slli(t);
	while(t--)
	{
		cin>>text;
		cin>>pattern;
		n=text.length();
	    m=pattern.length();

		f(i,0,n)
		{
		arr[i]=0;
		Ans[i]=0;
		prefix[i]=0;
	    }

		calculate_LPS(pattern);
		KMP(pattern,text);
        //f(i,0,n)cout<<arr[i]<<" ";cout<<endl;
		ans=fun(n,m);
		printf("%lld\n",ans);

	}
}