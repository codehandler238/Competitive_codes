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
bool check_children_sum_util(sn *root)
{
	if(root == NULL)
		return true;
	bool a,b;
	int lvalue=0,rvalue=0;

	a=check_children_sum_util(root->lchild);
	b=check_children_sum_util(root->rchild);

	if(root->lchild == NULL && root->rchild == NULL)
		return true;

	if(root->lchild != NULL)
		lvalue=root->lchild->data;

	if(root->rchild != NULL)
		rvalue=root->rchild->data;

	if(root->data == (lvalue+rvalue))
	{
		if(a && b)
			return true;
	}
	return false;
}
void check_children_sum(sn *root)
{
	if(check_children_sum_util(root))
		cout<<"it satisfy"<<endl;
	else
		cout<<"it does not satisfy"<<endl;
}
void convert_children_sum_util(sn *root,int diff)
{
	root->data+=diff;

	if(isleaf(root))
		return;

	if(root->lchild != NULL)
		convert_children_sum_util(root->lchild,diff);
	else
		convert_children_sum_util(root->rchild,diff);
}
void convert_children_sum(sn *root)
{
	int lvalue=0,rvalue=0;

	if(root == NULL || isleaf(root))
		return;

	convert_children_sum(root->lchild);
	convert_children_sum(root->rchild);

	if(root->lchild != NULL)
		lvalue=root->lchild->data;
	
	if(root->rchild != NULL)
		rvalue=root->rchild->data;

	int diff=root->data-(lvalue+rvalue);

	if(diff <= 0)
	{
		root->data+=(-diff);
		return;
	}
	else
	{
		if(root->lchild != NULL)
			convert_children_sum_util(root->lchild,diff);
		else
			convert_children_sum_util(root->rchild,diff);
	}
}
void convert_proper_children_sum(sn *root)
{
	convert_children_sum(root);
	levelorder(root);
}
int getdiameter(sn *root,int &dia)
{
	if(root == NULL)
		return 0;

	int lh,rh;

	lh=getdiameter(root->lchild,dia);
	rh=getdiameter(root->rchild,dia);

	int cur_dia=lh+rh;
	if(cur_dia > dia)
		dia=cur_dia;

	return (1+max(lh,rh));
}
void diameter(sn *root)
{
	int dia=0;
	getdiameter(root,dia);
	cout<<"Diameter is : "<<dia<<endl;
}
int check_height_balance_util(sn *root,bool &flag)
{
	if(root == NULL)
		return 0;

	int lh,rh;
	lh=check_height_balance_util(root->lchild,flag);
	rh=check_height_balance_util(root->rchild,flag);

	if(abs(lh-rh)>1)
		flag=false;

	return (1+max(lh,rh));
}
void check_height_balance(sn *root)
{
	bool flag=true;
	check_height_balance_util(root,flag);
	
	if(flag)
		cout<<"it is height balanced"<<endl;

	else
		cout<<"it is not height balanced"<<endl;
}
void double_tree_util(sn *root)
{
	if(root == NULL)
		return;
	sn *left,*right,*tmp;

	left=root->lchild;
	right=root->rchild;

	tmp=(sn *)malloc(sizeof(sn));
	tmp->data=root->data;
	tmp->lchild=left;
	tmp->rchild=NULL;
	root->lchild=tmp;

	double_tree_util(left);
	double_tree_util(right);
}
void double_tree(sn *root)
{
	double_tree_util(root);
	levelorder(root);
}
int max_width_util(sn *root)
{
	sn *tmp;
	while(!q.empty())
		q.pop();

	int cur=0,Max=0;

	if(root == NULL)
		return 0;

	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		if(tmp == NULL && !q.empty())
		{
			if(cur > Max)
				Max=cur;
			cur=-1;
			q.push(NULL);
		}
		else if(tmp == NULL)
			{
				if(cur > Max)
					Max=cur;
			}
		else
		{
			if(tmp->lchild != NULL)
				q.push(tmp->lchild);
			if(tmp->rchild != NULL)
				q.push(tmp->rchild);
		}
		cur++;
	}
	return Max;
}
void max_width(sn *root)
{
	int Max=max_width_util(root);
	cout<<"maximum width is : "<<Max<<endl;
}
bool foldable_util(sn *root_l,sn *root_r)
{
	if( (root_l == NULL && root_r != NULL) || (root_l != NULL && root_r == NULL))
		return false;

	if(root_l == NULL)
		return true;

	return (foldable_util(root_l->lchild,root_r->rchild) && foldable_util(root_l->rchild,root_r->lchild));
}
void foldable(sn *root)
{
	if(foldable_util(root->lchild,root->rchild))
		cout<<"Tree is foldable"<<endl;

	else
		cout<<"Tree is not foldable"<<endl;
}
void nodes_k_distance_util(sn *root,int k)
{
	if(root == NULL)
		return;

	if(k == 0)
		cout<<root->data<<" ";

	nodes_k_distance_util(root->lchild,k-1);
	nodes_k_distance_util(root->rchild,k-1);
}
void nodes_k_distance(sn *root)
{
	int k;
	cout<<"enter k : "<<endl;
	cin>>k;
	nodes_k_distance_util(root,k);
}
int find_level_util(sn *root,int value)
{
	if(root == NULL)
		return 0;
	if(root->data == value)
		return 1;

	int a,b;
	a=find_level_util(root->lchild,value);
	b=find_level_util(root->rchild,value);

	if(a || b)
		return 1+max(a,b);
	else
		return 0;
}
void find_level(sn *root)
{
	int l;
	cout<<"enter element : "<<endl;
	cin>>l;
	int level=find_level_util(root,l);
	cout<<"level is : "<<level<<endl;
}
void print(int arr[],int index)
{
	int i;
	f(i,0,index)
	cout<<arr[i]<<" ";
	cout<<endl;
}
int print_ancestors_util(sn *root,int V,int arr[],int index)
{
	int a=0,b=0;
	if(root->data == V)
	{
		print(arr,index);
		return 1;
	}
	arr[index]=root->data;

	if(root->lchild != NULL)
		a=print_ancestors_util(root->lchild,V,arr,index+1);

	if(a)
		return 1;

	if(root->rchild != NULL)
		b=print_ancestors_util(root->rchild,V,arr,index+1);

	return b;
}
void print_ancestors(sn *root)
{
	int m,index=0,arr[MAX];
	cout<<"Enter element : "<<endl;
	cin>>m;
	print_ancestors_util(root,m,arr,index);
}
int check_sum_tree_util(sn *root,bool &flag)
{
	if(root == NULL)
		return 0;

	int lvalue,rvalue;
	lvalue=check_sum_tree_util(root->lchild,flag);
	rvalue=check_sum_tree_util(root->rchild,flag);

	if(isleaf(root))
		return root->data;

	if(root->data != (lvalue+rvalue))
		flag=false;

	return (root->data + lvalue + rvalue);
}
void check_sum_tree(sn *root)
{
	bool flag=true;
	check_sum_tree_util(root,flag);

	if(flag)
		cout<<"it is sum tree"<<endl;
	else
		cout<<"it is not a sum tree"<<endl;
}
bool check_identical(sn *root1,sn *root2)
{
	if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
		return false;

	if(root1 == NULL)
		return true;

    if(root1->data != root2->data)
    	return false;

	return (check_identical(root1->lchild,root2->lchild) &&  check_identical(root1->rchild,root2->rchild));
}
bool check_subtree_util(sn *root1,sn *root2)
{
	bool a;
	if(root2 == NULL)
		return true;

	if(root1 == NULL)
		return false;

	if(root1->data == root2->data)
		a=check_identical(root1,root2);

	if(a)
		return a;

	return (check_subtree_util(root1->lchild,root2) || check_subtree_util(root1->rchild,root2));
}
void check_subtree(sn *root1)
{
	int m,i,n;
	sn *root2=NULL;
	cout<<"enter number of elements : "<<endl;
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		root2=formation(root2,m);
	}
	if(check_subtree_util(root1,root2))
		cout<<"YO!!"<<endl;
	else
		cout<<"OY!!"<<endl;

}
int convert_sum_tree_util(sn *root)
{
	if(root == NULL)
		return 0;

	int lsum,rsum,tmp;
	
	lsum=convert_sum_tree_util(root->lchild);
	rsum=convert_sum_tree_util(root->rchild);

	tmp=root->data;
	root->data=lsum+rsum;
	return (root->data+tmp);
}
void convert_sum_tree(sn *root)
{
	convert_sum_tree_util(root);
	levelorder(root);
}
sn *Search(sn *root,int n)
{
	if(root == NULL)
		return root;

	if(root->data == n)
		return root;

	 sn *left=Search(root->lchild,n);
	 sn *right=Search(root->rchild,n);

	 if(left!=NULL)
	 	return left;
	 else
	 	return right;
}
bool get_ancestors_util(sn *root,sn *tmp,sn *ancestors[],int index,int &size)
{
	if(root == NULL)
		return false;

	if(root == tmp){
		size=index;
		return true;
	}

	ancestors[index]=root;

	bool a,b;

	a=get_ancestors_util(root->lchild,tmp,ancestors,index+1,size);

	if(a)
		return a;
	b=get_ancestors_util(root->rchild,tmp,ancestors,index+1,size);

	return b;
}
void get_ancestors(sn *root)
{
	int n,index=0,size=0,i;
	sn *tmp,*ancestors[100];
	cout<<"enter number:";
	cin>>n;
	tmp=Search(root,n);cout<<tmp->data<<endl;
	get_ancestors_util(root,tmp,ancestors,index,size);

	f(i,0,size)
	cout<<ancestors[i]->data<<" ";
	cout<<endl;
}
void find(sn *root,int k,sn *block)
{
	if(root==block || root == NULL)
		return;

	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	find(root->lchild,k-1,block);
	find(root->rchild,k-1,block);
}
void nodes_at_k_distance(sn *root)
{
    int n,index=0,size=0,i,k;
	sn *tmp,*ancestors[100];
	cout<<"enter number:";
	cin>>n;
	cout<<"enter distance:";
	cin>>k;
	tmp=Search(root,n);cout<<tmp->data<<endl;
	get_ancestors_util(root,tmp,ancestors,index,size);
	nodes_k_distance_util(tmp,k);

	int count=1;
    sn *block=tmp;
	for(i=size-1;i>=0;i--)
	{
		if(k-count<0)
			break;
		find(ancestors[i],k-count,block);
		count++;
		block=ancestors[i];
	}
}
void inorder_without_recursion(sn *root)
{
	sn *tmp=root,*t;
	stack<sn *>st;

	

	while(1)
	{
		while(tmp != NULL)
		{
			st.push(tmp);
			tmp=tmp->lchild;
		}
        if(st.empty())
        	break;

		t=st.top();
		st.pop();
		cout<<t->data<<" ";
		tmp=t->rchild;
	}
}
void print_leaf(sn *root)
{
	if(isleaf(root))
		cout<<root->data<<" ";

	print_leaf(root->lchild);
	print_leaf(root->rchild);
}
void printLeaf(sn *root)
{
    if(root == NULL)
    return;
    
    if(isleaf(root))
    {
        cout<<root->data<<" ";
        return;
    }

    printLeaf(root->lchild);
    printLeaf(root->rchild);
}

void printLeftBoundary(sn *root)
{
    if(root == NULL)
    return;

    if(root->lchild)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->lchild);
    }
    else if(root->rchild)
    {
        cout<<root->data<<" ";
        printLeftBoundary(root->rchild);
    }
}

void printRightBoundary(sn *root)
{
    if(root == NULL)
    return;

    if(root->rchild)
    {
        printRightBoundary(root->rchild);
        cout<<root->data<<" ";
    }
    else if(root->lchild)
    {
        printRightBoundary(root->lchild);
        cout<<root->data<<" ";
    }
}
void boundary_nodes(sn *root)
{
    if(root == NULL)
    return;

    cout<<root->data<<" ";
    
    printLeftBoundary(root->lchild);
    printLeaf(root->lchild);
    printLeaf(root->rchild);
    printRightBoundary(root->rchild);
}

void reverse_level_order(sn *root)
{
	sn *tmp=root,*cur;
	stack<sn *>st;
	queue<sn *>qu;

	qu.push(tmp);

	while(!qu.empty())
	{
		cur=qu.front();
		qu.pop();
		st.push(cur);

		if(cur->rchild != NULL)
			qu.push(cur->rchild);

		if(cur->lchild != NULL)
			qu.push(cur->lchild);
	}

	while(!st.empty())
	{
		tmp=st.top();
		cout<<tmp->data<<" ";
		st.pop();
	}
}
void iterative_postorder(sn *root)
{
	sn *tmp,*cur;
	stack<sn *>st1;
	stack<sn *>st2;
	tmp=root;

	st1.push(tmp);

	while(!st1.empty())
	{
		cur=st1.top();
		st1.pop();
		st2.push(cur);

		if(cur->lchild != NULL)
			st1.push(cur->lchild);

		if(cur->rchild != NULL)
			st1.push(cur->rchild);
	}

	while(!st2.empty())
	{
		cout<<st2.top()->data<<" ";
		st2.pop();
	}
}

void rootToLeafUtil(sn *root, vector<int>v)
{
	if(root == NULL)
	return;

	v.pb(root->data);

	if(isleaf(root))
	{
		vector<int>::iterator it;
		for(it = v.begin();it != v.end();it++)
		cout<<*it<<" ";
		cout<<endl;
		return;
	}

	rootToLeafUtil(root->lchild, v);
	rootToLeafUtil(root->rchild, v);
}

void rootToLeaf(sn *root)
{
	vector<int>v;
	rootToLeafUtil(root, v);
}

int main()
{
	int i,j,k,m,n,t;
    sn *root=NULL;
    cout<<"Enter number of nodes in tree\n";
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		root=formation(root,m);
    }
    
		/*root=newNode(1);
		root->lchild=newNode(2);
		root->lchild->lchild=newNode(3);
        root->rchild=newNode(4);
        root->rchild->rchild = newNode(8);
        root->rchild->rchild->lchild = newNode(9);
        root->rchild->rchild->lchild->lchild = newNode(10);
        root->rchild->rchild->lchild->rchild = newNode(11);
        root->lchild->lchild->rchild = newNode(5);
        root->lchild->lchild->rchild->lchild = newNode(6);
        root->lchild->lchild->rchild->lchild->lchild = newNode(7);

		//root->lchild->rchild=newNode(12);
		//root->lchild->rchild->lchild=newNode(10);
		//root->lchild->rchild->rchild=newNode(14);
		//root->lchild->lchild->lchild=newNode(5);
		//root->lchild->rchild->rchild=newNode(6);
        //root->rchild->rchild = newNode(25);
        /*root->rchild=newNode(4);
		root->rchild->rchild=newNode(5);
		root->lchild->lchild->lchild=newNode(6);*/
		
	//postorder(root);
	//levelorder(root);
	//spiral_levelorder(root);//*******
	//rootToLeaf(root);
	//inorder_without_recursion(root);//************
	//check_children_sum(root);
	//convert_proper_children_sum(root);
	//diameter(root);
	//check_height_balance(root);
	//double_tree(root);
	//max_width(root);
	//foldable(root);
	//nodes_k_distance(root);
	//find_level(root);
	//print_ancestors(root);
	//check_sum_tree(root);
	//check_subtree(root);O(mn)
	//	convert_sum_tree(root);
	//get_ancestors(root);
	//nodes_at_k_distance(root);
    //boundary_nodes(root);//********	
	//reverse_level_order(root);
	//iterative_postorder(root);
}
