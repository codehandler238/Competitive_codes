#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
#define lli long long int
#define slli(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define f(i,a,b) for(i=a;i<b;i++)
#define MAX 100005
int lps[MAX],arr[MAX];
void KMP(string pattern,string text)
{
	int i,j,k,n,m;
	n=text.length();
	m=pattern.length();

	while(i<n)
	{
		if(pattern[j] == text[i])
		{
			i++;
			j++;
		}

		if(j == m)
		{
			arr[i-j]=1;
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
	int i,j,k,m,n,len;
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
int main()
{
	int i,j,k,m,n,t;
	string text,pattern;
	cin>>text;
	cin>>pattern;
	n=text.length();
	
	f(i,0,n)
	arr[i]=0;

	calculate_LPS(pattern);
	KMP(pattern,text);
    
    f(i,0,n)
    cout<<arr[i]<<" ";
    cout<<endl; 
}