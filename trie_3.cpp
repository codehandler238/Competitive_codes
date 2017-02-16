#include <bits/stdc++.h>
using namespace std;
#define lli int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 10005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
#define INT 29
int brr[MAX][21],temp[MAX];
int power[INT],tmp[25];
sn{
	sn *arr[2];
	bool is_leaf;
};
inline int input()
{
        int n = 0;
        int ch = getchar_unlocked();
        while (ch < '0' || ch > '9') ch = getchar_unlocked();
        while (ch >= '0' && ch <= '9') {
                n = (n << 3) + (n << 1) + (ch - '0');
                ch = getchar_unlocked();
        }
        return n;

}
sn *create_node()
{
	sn *root;
	root=(sn *)malloc(sizeof(sn));
	root->arr[0]=NULL;
	root->arr[1]=NULL;
	root->is_leaf=false;

	return root;
}
sn * create_tree(sn *root,int index,int v)
{
	sn *root1=root;
	int i,j,pos,p;

	f(i,0,INT-1)
	{
		p=INT-2-i;
		int pos1=v&(1<<p);
		if(pos1>0)pos1=1;

		if(root1->arr[pos1]==NULL)
			root1->arr[pos1]=create_node();
		root1=root1->arr[pos1];
	}

	root1->is_leaf=true;
	return root;
}
sn *initialize(sn *root,int index)
{
	sn *root1=root;
	int i,j;
	f(i,0,INT-1)
	{
		if(root1->arr[0]==NULL)
			root1->arr[0]=create_node();
		root1=root1->arr[0];
	}

	root1->is_leaf=true;
	return root;
}
int query(sn *root,int index,int v)
{
	int ans;
	
	int pos1,i,j,k,t,pos,p;
	sn *root1=root,*root2=root;
	ans=0;
	f(i,0,INT-1)
	{


		p=INT-2-i;
		pos1=v&(1<<p);
		if(pos1>0)pos1=1;

		if(root2->arr[pos1]==NULL)
			root2->arr[pos1]=create_node();
		root2=root2->arr[pos1];



		pos=v&(1<<(INT-2-i));
		if(pos>0)
			pos=1;
	
		if(pos==0)
		{
			t=INT-i-2;
			if(root1->arr[1]!=NULL){
				ans+=power[t];
				root1=root1->arr[1];
			}
			else
				root1=root1->arr[0];
		}
		else
		{
			t=INT-i-2;
			if(root1->arr[0]!=NULL)
			{
				ans+=power[t];
				root1=root1->arr[0];
			}
			else
				root1=root1->arr[1];
		}
	}
	root2->is_leaf=true;
	return ans;
}
int kadanes(int n,int right,int t)
{
	int i,j,k,current,ans=0,Max=0,pre=0,m,sz;

	sn *root=create_node();
	root=initialize(root,0);
	n=min(n,1000);
	f(i,0,n)
	{
		temp[i]^=brr[i][right];
		pre=pre^temp[i];
		m=pre;

		ans=query(root,0,pre);
		if(ans>Max)
			Max=ans;
		if(right==t-1)
			temp[i]=0;
	}
	return Max;
}

int fun(int n,int m)
{
	int i,j,k,left,right,current,sum,Max=0;

	f(left,0,m)
	{
		//memset(temp,0,sizeof(temp));
		//f(i,0,n)
		//temp[i]=0;

		f(right,left,m)
		{
			//f(i,0,n)
			//temp[i]^=brr[i][right];

			current=kadanes(n,right,m);
			if(current > Max)
				Max=current;
		}
	}
	return Max;
}

int main()
{
	int i,j,k,m=MOD,len,n,t,count=0,l,ans;
	power[0]=1;
	
	f(i,1,INT)
	power[i]=power[i-1]*2;

	//si(n);
	//si(m);
	n=input();
	m=input();
	f(i,0,n)
	{
		f(j,0,m){
		//si(brr[i][j]);
		brr[i][j]=input();
		}
	}
	ans=fun(n,m);
	printf("%d\n",ans);
}