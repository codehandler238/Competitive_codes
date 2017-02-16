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
bool check(double x1,double y1,double x2,double y2,double x3,double y3,double x,double y)
{
	double sign1,sign2,tmp;
	if(x1 == x2)
	{
		sign1=x3-x1;
		sign2=x-x1;
	}
	else
	{
		tmp=(y2-y1)/(x2-x1);
		sign1=y3-x3*tmp+x1*tmp-y1;
		sign2=y-x*tmp+x1*tmp-y1;
	}
	cout<<sign1<<" "<<sign2<<endl;
	if(sign1>0 && sign2<0)
		return false;
	if(sign1<0 && sign2>0)
		return false;
	return true;
}
bool check_inside(double x1,double y1,double x2,double y2,double x3,double y3)
{
	bool a,b,c;
	double x,y;
	cout<<"enter points:";
	cin>>x>>y;
	a=check(x1,y1,x2,y2,x3,y3,x,y);
	if(!a)
		return false;
	b=check(x1,y1,x3,y3,x2,y2,x,y);
	if(!b)
		return false;
	c=check(x2,y2,x3,y3,x1,y1,x,y);
	return c;
}
int main()
{
	double i,j,k,m,n,t,x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;

	if(check_inside(x1,y1,x2,y2,x3,y3))
		cout<<"lie inside"<<endl;
	else
		cout<<"lie outside"<<endl;
}