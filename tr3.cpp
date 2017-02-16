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
#define sndl struct node_dll
sndl{
	int data;
	sndl *next,*prv;
};
sn{
	int data;
	sn *lchild,*rchild;
};
queue<sn *>q;
sn *newNode(int data)
{
	sn *root;
	root=(sn *)malloc(sizeof(sn));
	root->data=data;
	root->lchild=NULL;
	root->rchild=NULL;

	return root;
}
sn *formation(sn *root,int data)
{
	sn *temp,*p;
	int flag;
	if(root==NULL)
	{
		temp=(sn *)malloc(sizeof(sn));
		temp->data=data;
		temp->lchild=NULL;
		temp->rchild=NULL;
		return temp;
	}
	q.push(root);
	while(!q.empty())
	{
		p=q.front();
		q.pop();

		if(p->lchild==NULL)
		{
			flag=1;
			break;
		}

		else if(p->rchild==NULL)
		{
			flag=2;
			break;
		}

		else
		{
			q.push(p->lchild);
			q.push(p->rchild);
		}
	}
	temp=(sn *)malloc(sizeof(sn));
	temp->data=data;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(flag==1)
		p->lchild=temp;

	else if(flag==2)
		p->rchild=temp;

	while(!q.empty())
		q.pop();

	return root;

}
bool isleaf(sn *root)
{
	if(root->lchild == NULL && root->rchild == NULL)
		return true;
    else
    	return false;
}
void levelorder_util(sn *root)
{
	sn *tmp=root;

	if(root == NULL)
		return;

	queue<sn *>qu;
	qu.push(tmp);

	while(!qu.empty())
	{
		tmp=qu.front();
		qu.pop();
		cout<<tmp->data<<" ";
		if(tmp->lchild != NULL)
			qu.push(tmp->lchild);
		if(tmp->rchild != NULL)
			qu.push(tmp->rchild);
	}
	cout<<endl;
}
void levelorder(sn *root)
{
	levelorder_util(root);
}
void inorder_util(sn *root)
{
	if(root == NULL)
		return;

	inorder_util(root->lchild);
	cout<<root->data<<" ";
	inorder_util(root->rchild);
}
void postorder_util(sn *root)
{
	if(root == NULL)
		return;

	postorder_util(root->lchild);
	postorder_util(root->rchild);
	cout<<root->data<<" ";
}
void preorder_util(sn *root)
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preorder_util(root->lchild);
	preorder_util(root->rchild);
}
void postorder(sn *root)
{
	postorder_util(root);
	cout<<endl;
}
void preorder(sn *root)
{
	preorder_util(root);
	cout<<endl;
}
void inorder(sn *root)
{
	inorder_util(root);
	cout<<endl;
}
void print_leaf(sn *root)
{
	if(root == NULL)
		return;

	if(isleaf(root)){
		cout<<root->data<<" ";
		return;
	}

	print_leaf(root->lchild);
	print_leaf(root->rchild);
}
void print_right(sn *root)
{
	if(root==NULL || isleaf(root))
		return;

	print_right(root->rchild);
	cout<<root->data<<" ";
}
void boundary_nodes(sn *root)
{
	
	sn *tmp=root;

	while((tmp != NULL) && !isleaf(tmp))
		{
			cout<<tmp->data<<" ";
			tmp=tmp->lchild;
		}

		print_leaf(root);

		print_right(root);

		cout<<endl;
}
int search(int n,int arr[],int l,int h)
{
	int i,j;
	f(i,l,h+1)
	{
		if(arr[i] == n)
			return i;
	}
}
sn *construction_util(int l,int r,int &index,int pre[],int post[])
{
	if(l>r)
		return NULL;

	int i1,i2;

	sn *tmp=(sn *)malloc(sizeof(sn));
	tmp->data=pre[index];
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	if(l==r)
		return tmp;

	i1=search(pre[index],post,l,r);
	i2=search(pre[index+1],post,l,r);
    index++;
	tmp->lchild=construction_util(l,i2,index,pre,post);
	index++;
	tmp->rchild=construction_util(i2+1,r-1,index,pre,post);

	return tmp;
}
void construction()
{
	int i,j,k,n,index=0;
	cin>>n;
	int pre[n],post[n];
	cout<<"enter preorder"<<endl;
	f(i,0,n)
	cin>>pre[i];
    
    cout<<"enter postorder"<<endl;
	f(i,0,n)
	cin>>post[i];
    index=0;
	sn *root=construction_util(0,n-1,index,pre,post);
	inorder(root);
}
void iterative_preorder(sn *root)
{
	stack<sn *>st;
	sn *tmp=root,*t;
	while(1)
	{
		while(tmp != NULL)
		{
			cout<<tmp->data<<" ";
			st.push(tmp);
			tmp=tmp->lchild;
		}

		if(st.empty())
			break;
		t=st.top();
		st.pop();
		tmp=t->rchild;
	}
}
int main()
{
	int i,j,k,m,n,t;
	sn *root=NULL;
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		root=formation(root,m);
	}
		/*root=newNode(1);
		root->lchild=newNode(8);
		root->rchild=newNode(22);
		root->lchild->lchild=newNode(4);
		root->lchild->rchild=newNode(12);
		root->rchild->rchild=newNode(25);
		root->lchild->rchild->lchild=newNode(10);
		root->lchild->rchild->rchild=newNode(14);*/
	//boundary_nodes(root);
	//construction();
		iterative_preorder(root);
}