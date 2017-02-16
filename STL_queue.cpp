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
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int main()
{
	int i,j,k,m,n,t;
	queue<int>q;
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		q.push(m);
	}
	cout<<q.front()<<" "<<q.back()<<endl;

	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	queue<int>qu;
	q.push(1);
	swap(q,qu);
	cout<<qu.size()<<endl;
}