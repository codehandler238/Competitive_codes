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
int main()
{
	int i,j,k,m,n,t,count,s,ans,required,c=1;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector<int>v;
	si(t);
	while(t--)
	{
		si(n);
		v.clear();
		count=0;
		f(i,0,n)
		{
			si(m);
			if(m>=50)count++;
			else
				v.pb(m);
		}
		if(count == n)
			ans=n;
		else
		{
			sort(v.begin(),v.end());
			s=v.size();
			i=0;
			j=s-1;
			while(1)
			{
				m=v[j];
				if(50%m==0)
					required=50/m-1;
				else
					required=50/m;
				i=i+required;
				if(i<=j)count++;
				j-=1;
				//cout<<i<<" "<<j<<endl;
				if(i>j)break;
			}
			ans=count;
		}
		cout<<"Case #"<<c<<": "<<ans<<endl;
		c++;
	}
}