/*
Problem1: Given an array of integers, we have to find two elements whose XOR is maximum.
Numbers are upto 2^30.
*/
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
sn{
	sn *arr[2];
	bool is_leaf;
};
int brr[MAX];
int tmp[35];
sn *create_node()
{
	sn *root;
	root=(sn *)malloc(sizeof(sn));
	root->arr[0]=NULL;
	root->arr[1]=NULL;
	root->is_leaf=false;

	return root;
}
sn * create_tree(sn *root,int n,int index)
{
	if(index==31)
	{
		root->is_leaf=true;
		return root;
	}

	if(root->arr[tmp[index]]==NULL)
		root->arr[tmp[index]]=create_node();

	root->arr[tmp[index]]=create_tree(root->arr[tmp[index]],n,index+1);

	return root;
}
sn *initialize(sn *root,int index)
{
	if(index==31)
	{
		root->is_leaf=true;
		return root;
	}
	root->arr[0]=create_node();
	root->arr[0]=initialize(root->arr[0],index+1);
	return root;
}
int query(sn *root,int index)
{
	int ans;
	
	if(index==31)
		return 0;

	if(tmp[index]==0)
	{
		if(root->arr[1]!=NULL)
		{
			ans=pow(2,31-index-1)+query(root->arr[1],index+1);
		}
		else
		{
			ans=query(root->arr[0],index+1);
		}
	}

	else
	{
		if(root->arr[0]!=NULL)
		{
			ans=pow(2,31-index-1)+query(root->arr[0],index+1);
		}
		else
		{
			ans=query(root->arr[0],index+1);
		}
	}
	return ans;
}
int main()
{
	int i,j,ans,k,sz,m,n,t,Max=0;
	si(n);

	f(i,0,n)
	si(brr[i]);

	sn *root;
	root=create_node();

	root=initialize(root,0);

	f(i,0,n)
	{
		m=brr[i];
		sz=30;
		
		f(j,0,31)
		tmp[i]=0;

		while(m!=0)
		{
			tmp[sz--]=(m%2==0)?0:1;
			m=m/2;
		}
		ans=query(root,0);cout<<ans<<endl;
		if(ans>Max)
			Max=ans;
		root=create_tree(root,brr[i],0);
	}
}