#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
struct node{
	int a,b;
	bool operator<(const struct node &c)const{
		return b>c.b;
	}
};

int main()
{
	int n,a,b,i,j,k;
	struct node m;
	priority_queue<struct node>pq;
//	priority_queue<struct node,vector<struct node>,greater<struct node> >pp;

	cin>>n;
	f(i,0,n)
	{
		cin>>a>>b;
		m.a=a;
		m.b=b;
		pq.push(m);
	}
	f(i,0,n)
	{
		m=pq.top();
		pq.pop();
		cout<<m.a<<" "<<m.b<<endl;
	}
	//cout<<endl;
}
bool operator<(const struct node &c)const{
	return b>c.b}
struct node{
	int a,b;
	bool operator<(const struct node &c)const{
		return b<c.b
	}
};
