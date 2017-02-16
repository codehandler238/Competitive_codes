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
void print(std::vector<int> v)
{
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t;
	std::vector<int> v;
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		v.push_back(m);
	}
	sort(v.begin(),v.end());
	
	vector<int>::iterator it;

	it=lower_bound(v.begin(),v.end(),3);

	cout<<*it<<endl;
	
	print(v);
	
	it=v.begin();

	advance(it,5);

	v.insert(it,10);

	print(v);
	
	it=v.begin();
	
	advance(it,3);

	v.erase(it);

	print(v);

	if(binary_search(v.begin(),v.end(),5))
		cout<<"is present"<<endl;
	else
		cout<<"not present"<<endl;

	vector<int>myvector(10,0);
	
	myvector.at(3)=3;
	
	print(myvector);

	v.swap(myvector);

	print(v);

	cout<<myvector.front()<<" "<<myvector.back()<<endl;
}