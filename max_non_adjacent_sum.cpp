#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define INF 1000000007
#define MAX 100005
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
sn{
	int data;
	sn *lchild,*rchild;
};
map<sn*,int>hash;
sn *Newnode(int d)
{
	sn *root;
	root=(sn *)malloc(sizeof(sn));
	root->data=d;
	root->lchild=NULL;
	root->rchild=NULL;

	return root;
}
int Max(int a,int b,int c,int d)
{
	return max(max(max(a,b),c),d);
}
int get_max_sum(sn *root)
{
	int a1=0,a2=0,a3=0,a4=0,curr=0,sum,l,r;

	if(root == NULL)
		return 0;

	if(hash.find(root)!=hash.end())
		return hash[root];

	//take current one
	if(root->lchild!=NULL)
		a1=get_max_sum(root->lchild->lchild);

	if(root->lchild!=NULL)
		a2=get_max_sum(root->lchild->rchild);

	if(root->rchild!=NULL)
		a3=get_max_sum(root->rchild->lchild);

	if(root->rchild!=NULL)
		a4=get_max_sum(root->rchild->rchild);

	l=root->data+a1+a2+a3+a4;

	//not take current one
	r=get_max_sum(root->lchild)+get_max_sum(root->rchild);

	hash[root]=max(l,r);
	return hash[root];
}
int main()
{
	int i,j,k,m,n,t;
	sn *root=NULL;
	root=Newnode(100);
	root->lchild=Newnode(200);
	root->lchild->lchild=Newnode(1);
	root->rchild=Newnode(3);
	root->rchild->lchild=Newnode(4);
	root->rchild->rchild=Newnode(5);
	int ans=get_max_sum(root);
	cout<<ans<<endl;
}