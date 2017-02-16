#include <bits/stdc++.h>//index for minimum lexicographical rotation
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 200005
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
sn{
	int a[2];
	int b;
}L[MAX];
int p[20][MAX];
bool cmp(sn r,sn s)
{
	if(r.a[0]==s.a[0])
	{
		if(r.a[1]<s.a[1])
			return 1;
		else
			return 0;
	}
	else
	{
		if(r.a[0]<s.a[0])
			return 1;
		else
			return 0;
	}
}
void suffix_array(string str)
{
	int untill=1,step=1,i,j,k,m,n,l,t;
	l=str.length();

	f(i,0,l)
	p[0][i]=str[i]-'a';

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
	/*f(i,0,step)
	{
		f(j,0,l)
		cout<<p[i][j]<<" ";
		cout<<endl;
	}*/
}

int find(string str)
{
	int ans,index,i,j,k=str.length()/2,l=ceil(log2(k));
	f(j,0,k)
	{
		if(L[j].b<k)
		{
			ans=L[j].b;
			break;
		}
	}
	int count=k/2;
	//cout<<index<<endl;
	string new_str=str.substr(ans,k);
    ans=str.find(new_str);
    //cout<<ans<<endl;
	return ans;
}
int main()
{
	int ans,i,j,k,m,n,t,l;
	string str;
	si(t);
	while(t--)
	{
		si(l);
		cin>>str;
		//cout<<str<<endl;
		str+=str;
		suffix_array(str);
        ans=find(str);
        cout<<ans<<endl;
	}
}