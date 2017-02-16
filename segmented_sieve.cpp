#include<bits/stdc++.h>
using namespace std;
#define lli int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%d",&a);
#define INF 1000000007
#define MAX 100005
#define pb(a) push_back(a)
#define sn struct node
//vector<lli>arr;
int prime[MAX];
int arr[MAX];
bool p[MAX];
//vector<bool>p;
//vector<lli>prime;
int sie(lli limit,lli n,lli m)
{
	lli i,j,k,index,m1,size=0;
	//arr.clear();

	f(i,0,limit-2)
	arr[i]=i+2;

	f(i,0,limit-2)
	{
		if(arr[i] != 0)
		{
			m1=1;
			index=arr[i]*m1+i;

			while(index < limit-2)
			{
				index=arr[i]*m1+i;
				arr[index]=0;
				m1++;
			}
		}
	}
	f(i,0,limit-2)
	{
		if(arr[i] != 0){
			if(arr[i]>=n && arr[i]<=m)
				cout<<arr[i]<<endl;
			prime[size++]=arr[i];
		}
	}
	return size;
}
void ss(lli n,lli m)
{
	lli s,index,limit=floor(sqrt(m))+1,low,high,i,tmp; //cout<<"limit="<<limit<<endl;
	//vector<lli>prime;
	//prime.clear();
	s=sie(limit,n,m);
	low=n;
	high=low+limit;
	if(high>m)
		high=m+1;
    //s=prime.size();
 
	while(low<=m)
	{
		//p.clear();
		
		f(i,0,high-low+1)
		p[i]=true;

		for(i=0;i<s;i++)
		{
			tmp=floor(low/prime[i])*prime[i];
	//		cout<<"tmp="<<tmp<<endl;
			if(tmp<low)
				tmp+=prime[i];

			index=tmp-low;
            
			while(index < (high-low))
			{
				p[index]=false;
				index+=prime[i];
			}
		}
		f(i,0,high-low)
		{
			if(p[i]==true && (i+low)!=1)
				cout<<(i+low)<<endl;
				
		}
		if(high==low && p[0]==1)
			cout<<low<<endl;
		
		low+=limit;
		high+=limit;
	//	cout<<low<<" "<<high<<endl;
		if(high>m)
			high=m+1;
	}
	cout<<endl;
}
int main()
{
	lli i,j,k,m,n,t;
	slli(t);
	while(t--)
	{
		slli(n);
		slli(m);
		ss(n,m);
	}
}