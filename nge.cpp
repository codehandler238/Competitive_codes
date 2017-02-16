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
sn{
	int value,index;
};
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void fun(sn arr[],int n)
{
	int ans[n];
	stack<sn>st;
	int i=1,j,k,m;
	sn t,cur;
	st.push(arr[0]);

	while(!st.empty() && i<n)
	{
		t=st.top();
		cur=arr[i];

		while(!st.empty() && cur.value > t.value)
		{
			ans[t.index]=cur.value;
			st.pop();
			
			if(st.empty())
				break;

			t=st.top();
		}
		st.push(cur);
		i++;
	}

	while(!st.empty())
	{
		t=st.top();
		st.pop();
		ans[t.index]=-1;
	}
	f(i,0,n)
	cout<<ans[i]<<" ";
	cout<<endl;

}
int main()
{
	int i,j,k,m,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sn arr[n];
		f(i,0,n)
		{
			cin>>arr[i].value;
			arr[i].index=i;
		}
		fun(arr,n);
	}
}