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
void print(stack<int>st)
{

	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t;
	stack<int>st;
	cin>>n;
	f(i,0,n)
	st.push(i);
    
    print(st);

	stack<int>s;
	s.push(1);
	s.push(2);

	swap(s,st);
	print(s);
	print(st);

	if(!st.empty())
		cout<<st.size()<<endl;
}