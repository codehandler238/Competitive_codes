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
int main()
{
	lli i,j,k,m,n,t;
	cin>>n;
	bitset<3>str(n);//represent n in 3 bits
	cout<<str.flip()<<endl;//flip all bits
	cout<<str.count()<<endl;//count number of set bits
	cout<<str.size()<<endl;
}