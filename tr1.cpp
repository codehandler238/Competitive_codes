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
sn *formation1(sn *root,int data)
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

sn *formation(sn *root,int data)
{
	sn *tmp;
	if(root==NULL)
	{
		tmp=(sn *)malloc(sizeof(sn));
		tmp->data=data;
		tmp->lchild=NULL;
		tmp->rchild=NULL;
		return tmp;
	}
	
	if(root->data < data)
		root->rchild=formation(root->rchild,data);
	
	else
		root->lchild=formation(root->lchild,data);

	return root;
}
void formation_dll(sndl *&head,sndl *&tail,int data)
{
	sndl *tmp;
	tmp=(sndl *)malloc(sizeof(sndl));
	tmp->data=data;
	tmp->next=NULL;
	tmp->prv=NULL;

	if(head == NULL)
	{
		head=tmp;
		tail=tmp;
		return;
	}
	else
	{
		tail->next=tmp;
		tmp->prv=tail;
		tail=tmp;
		return;
	}
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
bool search_util(sn *root,int data)
{
	if(root == NULL)
		return false;

	if(root->data == data)
		return true;

	else if(root->data < data)
		return search_util(root->rchild,data);

	else
		return search_util(root->lchild,data);
}
void search(sn *root)
{
	int m;
	cout<<"Enter data to be searched"<<endl;
	cin>>m;
	
	if(search_util(root,m))
		cout<<"Data found"<<endl;
	else
		cout<<"Data not found"<<endl;
}
sn *Delete_util(sn *root,int data)
{
	sn *tmp;
	if(root->data < data)
		root->rchild=Delete_util(root->rchild,data);

	else if(root->data > data)
		root->lchild=Delete_util(root->lchild,data);

	else
	{
		if(root->lchild!=NULL && root->rchild!=NULL)
		{
			tmp=root->rchild;

			while(tmp->lchild!=NULL)
				tmp=tmp->lchild;

			root->data=tmp->data;
			root->rchild=Delete_util(root->rchild,root->data);
		}

		else if(root->lchild!=NULL)
			root=root->lchild;

		else if(root->rchild!=NULL)
			root=root->rchild;

		else
			root=NULL;
	}
	return root;
}
void Delete(sn *root)
{
	int m;
	while(1)
	{
	cout<<"Enter data to be deleted"<<endl;
	cin>>m;
    
    if(m==-1)
    	break;

	if(!search_util(root,m))
		cout<<"Data is not present"<<endl;

	else
		root=Delete_util(root,m);

	inorder(root);
    }
}
sn *predecessor_util(sn *root,int m,sn *pred)
{
	sn *tmp;
	
	if(root==NULL)
		return root;

	if(root->data > m)
	{
		return predecessor_util(root->lchild,m,pred);
	}

	else if(root->data < m)
	{
		pred=root;
		return predecessor_util(root->rchild,m,pred);
	}

	else
	{
		tmp=root->lchild;
        
        if(tmp == NULL)
        	return pred;

		while(tmp->rchild!=NULL)
			tmp=tmp->rchild;

		return tmp;
	}
}
sn *predecessor_util(sn *root,int m,sn *&p1,sn *&p2)
{
	if(root == NULL)
		return root;
	sn *a,*b;

	a=predecessor_util(root->lchild,m,p1,p2);

	if(p1 == NULL)
	{
		p1=root;
	}
	else if(p2==NULL)
	{
		p2=root;
		if(p2->data == m)
			return p1;
	}
	else
	{
		p1=p2;
		p2=root;
		if(p2->data == m)
			return p1;
	}
	
	if(a==NULL)
	b=predecessor_util(root->rchild,m,p1,p2);

    if(a!=NULL)
    	return a;
    else
    	return b;
}
void predecessor(sn *root)
{
	int m;
	sn *ptr,*p1=NULL,*p2=NULL,*pred;
	while(1)
	{
		p1=NULL;
		p2=NULL;
	    cout<<"Enter number : "<<endl;
	    cin>>m;

	    if(m==-1)
	    	break;
	    
	    /*if(!(ptr = predecessor_util(root,m,p1,p2)))
		    cout<<"No predecessor"<<endl;
	    else
		    cout<<"Predecessor is "<<ptr->data<<endl;*/

		if(!(ptr = predecessor_util(root,m,pred)))
		    cout<<"No predecessor"<<endl;
	    else
		    cout<<"Predecessor is "<<ptr->data<<endl;
	}
}
sn *successor_util(sn *root,int m,sn *&p1,sn *&p2)
{
	if(root == NULL)
		return root;
	sn *a,*b;

	a=successor_util(root->lchild,m,p1,p2);

	if(p1 == NULL)
	{
		p1=root;
	}
	else if(p2==NULL)
	{
		p2=root;
		if(p1->data == m)
			return p2;
	}
	else
	{
		p1=p2;
		p2=root;
		if(p1->data == m)
			return p2;
	}
	
	if(a==NULL)
	b=successor_util(root->rchild,m,p1,p2);

    if(a!=NULL)
    	return a;
    else
    	return b;
}
sn *successor_util(sn *root,int m,sn *succ)
{
	sn *tmp;
	
	if(root==NULL)
		return root;

	if(root->data > m)
	{
		succ=root;
		return successor_util(root->lchild,m,succ);
	}

	else if(root->data < m)
		return successor_util(root->rchild,m,succ);

	else
	{
		tmp=root->rchild;
        
        if(tmp == NULL)
        	return succ;

		while(tmp->lchild!=NULL)
			tmp=tmp->lchild;

		return tmp;
	}
}
void successor(sn *root)
{
	int m;
	sn *ptr,*p1=NULL,*p2=NULL,*succ;
	while(1)
	{
		p1=NULL;
		p2=NULL;
	    cout<<"Enter number : "<<endl;
	    cin>>m;

	    if(m==-1)
	    	break;
	    
	    /*if(!(ptr = successor_util(root,m,p1,p2)))
		    cout<<"No successor"<<endl;
	    else
		    cout<<"Successor is "<<ptr->data<<endl;*/

	    if(!(ptr = successor_util(root,m,succ)))
		    cout<<"No successor"<<endl;
	    else
		    cout<<"Successor is "<<ptr->data<<endl;
	}
}
bool check_BST_util(sn *root,int INTMAX,int INTMIN)
{
	if(root == NULL)
		return true;

	if(root->data > INTMIN && root->data < INTMAX)
		return (check_BST_util(root->lchild,root->data-1,INTMIN) && check_BST_util(root->rchild,INTMAX,root->data+1));

	else
		return false;
}
bool check_BST_util(sn *root)
{
	bool a,b;
	static sn *prv=NULL;

	if(root == NULL)
		return true;

	a=check_BST_util(root->lchild);

	if(a==false)
		return a;
   
    if(prv!=NULL && root->data <= prv->data)
    	return false;
	
	prv=root;

	b=check_BST_util(root->rchild);

	return b;
}
bool check_BST_util(sn *root,sn *&p1,sn *&p2)
{
	if(root == NULL)
		return true;
	
	bool a,b;

	a=check_BST_util(root->lchild,p1,p2);

	if(p1 == NULL)
	{
		p1=root;
	}
	else if(p2==NULL)
	{
		p2=root;
		if(p2->data < p1->data)
			return false;
	}
	else
	{
		p1=p2;
		p2=root;
		if(p2->data < p1->data)
			return false;
	}
	
	b=check_BST_util(root->rchild,p1,p2);

    return (a && b);
}

void check_BST(sn *root)//A postorder solution can also be done.
{
	sn *p1=NULL,*p2=NULL;
	int INTMAX=100000,INTMIN=-INTMAX;
	/*if(check_BST_util(root,p1,p2))
		cout<<"Tree is BST"<<endl;

	else
		cout<<"Tree is not BST"<<endl;*/
	
	/*if(check_BST_util(root,INTMAX,INTMIN))
		cout<<"Tree is BST"<<endl;

	else
		cout<<"Tree is not BST"<<endl;*/
	if(check_BST_util(root))
		cout<<"Tree is BST"<<endl;

	else
		cout<<"Tree is not BST"<<endl;
}
sn *lca_util(sn *root,int a,int b)
{
	if(root == NULL)
		return root;

	if(root->data >= a && root->data <= b)
		return root;

	if(root->data < a && root->data < b)
		return lca_util(root->rchild,a,b);

	else if(root->data > a && root->data > b)
		return lca_util(root->lchild,a,b);
}
void lca(sn *root)
{
	int a,b;
	cout<<"Enter numbers"<<endl;
	cin>>a>>b;
	cout<<"LCA is "<<lca_util(root,min(a,b),max(a,b))->data<<endl;
}
void BST_array_util(int arr[],int start,int end)
{
	if(start >= end)
		return;

	BST_array_util(arr,2*start+1,end);

	cout<<arr[start]<<" ";

	BST_array_util(arr,2*start+2,end);
}
void BST_array()
{
	int i,j,k,n,start=0,end;
	cin>>n;
	int arr[n+1];

	f(i,0,n)
	cin>>arr[i];

    end=n;
	BST_array_util(arr,start,end);
	cout<<endl;
}
sn *kth_smallest_util(sn *root,int k)
{
	sn *ptr;
	static int count=1;

	if(root == NULL)
		return root;

	if((ptr=kth_smallest_util(root->lchild,k))!=NULL)
		return ptr;

	if(count == k)
		return root;
	count++;

	return kth_smallest_util(root->rchild,k);
}
void kth_smallest(sn *root)
{
	int i,j,k,n;
	sn *ptr;

	cout<<"Enter value of k "<<endl;
	cin>>k;
    ptr=kth_smallest_util(root,k);
    cout<<ptr->data<<endl;
}
void print_in_range_util(sn *root,int k1,int k2)
{
	if(root == NULL)
		return;

	if(root->data > k1)
		print_in_range_util(root->lchild,k1,k2);

	if(root->data >= k1 && root->data <= k2)
		cout<<root->data<<" ";

	if(root->data < k2)
		print_in_range_util(root->rchild,k1,k2);
}
void print_in_range(sn *root)
{
	int k1,k2;
	cout<<"Enter range"<<endl;
	cin>>k1>>k2;
	print_in_range_util(root,k1,k2);
	cout<<endl;
}
sn *sorted_array_BST_util(int arr[],int low,int high)
{
	if(low > high)
		return NULL;

	int mid=(low+high)/2;

	sn *root=NULL;
	
	root=formation(root,arr[mid]);

	root->lchild=sorted_array_BST_util(arr,low,mid-1);

	root->rchild=sorted_array_BST_util(arr,mid+1,high);

	return root;
}
void sorted_array_BST()
{
	int i,j,k,m,n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	int arr[n+1];

	cout<<"Enter elements"<<endl;
	f(i,0,n)
	cin>>arr[i];

	sn *root=NULL;
	root=sorted_array_BST_util(arr,0,n-1);
	preorder(root);
}
int largest_BST_util(sn *root,int *isBST,int *max_ref,int *min_ref)
{
	if(root == NULL)
	{
		*isBST=1;
		return 0;
	}
	
	int l_flag,r_flag,max_l,max_r,min_l,min_r,Max=INF,Min=-INF,l,r;

	*max_ref=INF;
	*min_ref=-INF;
	
	l=largest_BST_util(root->lchild,isBST,max_ref,min_ref);
	max_l=*max_ref;
	min_l=*min_ref;

	if(*isBST==1)
		l_flag=1;
    
    *max_ref=INF;
    *min_ref=-INF;
	r=largest_BST_util(root->rchild,isBST,max_ref,min_ref);

	max_r=*max_ref;
	min_r=*min_ref;

	if(*isBST==1)
		r_flag=1;

    int a=INF,b=-INF;

    if(l_flag==1 && r_flag==1)
    {
	if(max_l==INF)
		a=-INF;
	else
		a=max_l;

	if(min_r==-INF)
		b=INF;
	else
		b=min_r;
    }

       if(max_r==INF)
			*max_ref=root->data;
		else
			*max_ref=max_r;

		if(min_l==-INF)
			*min_ref=root->data;
		else
			*min_ref=min_l;

	if(root->data > a && root->data < b)
	{
		*isBST=1;
		return (l+r+1);
	}

	else
	{
		*isBST=0;

		if(root->lchild==NULL && root->rchild==NULL)
			return 1;
		else
		    return max(l,r);
	}
}
void largest_BST(sn *root)
{
	int max_ref=INF,min_ref=-INF,isBST=0;
	cout<<largest_BST_util(root,&isBST,&max_ref,&min_ref)<<endl;
}
struct node* newNode(int data)
{
	struct node* Node = new(struct node);
	Node->data = data;
	Node->lchild = NULL;
	Node->rchild = NULL;
	return (Node);
}
bool is_same_BST_util(int arr[],int brr[],int i1,int j1,int n,int Max,int Min)
{
	int i,j,k;

	for(i=i1;i<n;i++)
		if(arr[i]>Min && arr[i]<Max)
			break;

	for(j=j1;j<n;j++)
		if(brr[j]>Min && brr[j]<Max)
			break;

	if(i==n && j==n)
		return true;

	if(arr[i]!=brr[j] || ((i==n)^(j==n))) 
		return false;

	return ( is_same_BST_util(arr,brr,i+1,j+1,n,arr[i],Min) && is_same_BST_util(arr,brr,i+1,j+1,n,Max,arr[i]) );
}
void is_same_BST()
{
	int i,j,k,m,n,Max=INF,Min;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	int arr[n+1],brr[n+1];

	cout<<"Enter elements"<<endl;
	f(i,0,n)
	cin>>arr[i];

	cout<<"Enter elements"<<endl;
	f(i,0,n)
	cin>>brr[i];

	if(is_same_BST_util(arr,brr,0,0,n,Max,Min))
		cout<<"Two are same"<<endl;

	else
		cout<<"Two are not same"<<endl;
}

void add_all_greater_values_util(sn *root)
{
	if(root == NULL)
		return;

	static int count=0;

	add_all_greater_values_util(root->rchild);

	root->data+=count;
	count=root->data;

	add_all_greater_values_util(root->lchild);
}

void add_all_greater_values(sn *root)
{
	add_all_greater_values_util(root);
	inorder(root);
}

sn *remove_outside_range_util(sn *root,int l,int h)
{
	if(root == NULL)
		return root;

	root->lchild=remove_outside_range_util(root->lchild,l,h);
	root->rchild=remove_outside_range_util(root->rchild,l,h);

	if(root->data < l)
		return root->rchild;

	if(root->data > h)
		return root->lchild;

	return root;
}

void remove_outside_range(sn *root)
{
	int l,h;
	cout<<"Enter range"<<endl;
	cin>>l>>h;
	root=remove_outside_range_util(root,l,h);
	inorder(root);
}

bool one_child_util(int arr[],int n)
{
	int i,j,Min,Max;
	if(n<=1)
		return false;

	Min=arr[n-1];
	Max=arr[n-1];

	for(i=n-2;i>=0;i--)
	{
		if(arr[i] < Min && arr[i] < Max)
			Min=arr[i];

		else if(arr[i] > Min && arr[i] > Max)
			Max=arr[i];

		else
			return false;
	}
	return true;
}

void one_child()
{
	int n,i;
	cout<<"enter size of array:"<<endl;
	cin>>n;
	int arr[n+1];
	cout<<"Enter elements:"<<endl;
	f(i,0,n)
	cin>>arr[i];

	if(one_child_util(arr,n))
		cout<<"Every internal node has one child"<<endl;
	else
		cout<<"Not every internal node has one child"<<endl;
}
void get_array(sn *root,int arr[],int &index)
{
	if(root == NULL)
		return;

	get_array(root->lchild,arr,index);
	
	arr[index++]=root->data;
	
	get_array(root->rchild,arr,index);
}
void print_array(int arr[],int n)
{
	int i;
	f(i,0,n)
	cout<<arr[i]<<" ";
	cout<<endl;
}
void merge_array(int arr[],int brr[],int new_array[],int size1,int size2)
{
	int i=0,j=0,size=0;
	while(i<size1 && j<size2)
	{
		if(arr[i] < brr[j])
		{
			new_array[size++]=arr[i];
			i++;
		}
		else 
		{
			new_array[size++]=brr[j];
			j++;
		}
	}
	while(i<size1)
		new_array[size++]=arr[i++];

	while(j<size2)
		new_array[size++]=brr[j++];
}

void merge(sn *root1,int size1)
{
	int n,m,i,size2,index;
	sn *root2=NULL;
	cout<<"Enter size:"<<endl;
	cin>>size2;
	
	int new_array[size1+size2+1];

	f(i,0,size2)
	{
		cin>>m;
		root2=formation(root2,m);
	}
	
	int arr[size1+1],brr[size2+1];
    
    index=0;
	get_array(root1,arr,index);
    
    index=0;
    get_array(root2,brr,index);
    
    merge_array(arr,brr,new_array,size1,size2);
    
    sn *root=sorted_array_BST_util(new_array,0,size1+size2-1);
    
    inorder(root);
}
int get_size(sndl *head)
{
	int size=0;
	sndl *tmp=head;
	while(tmp!=NULL)
	{
		tmp=tmp->next;
		size++;
	}
	return size;
}
sndl *DLL_to_BST_util(int low,int high,sndl *head)
{
	int mid=(low+high)/2,i;
	if(low>high)
		return NULL;
	if(low==high)
	{
		head->prv=NULL;
		head->next=NULL;
		return head;
	}
	sndl *root=head;
    f(i,low,mid)
    root=root->next;

    root->prv=DLL_to_BST_util(low,mid-1,head);
    root->next=DLL_to_BST_util(mid+1,high,root->next);

    return root;  
}
void print_inorder(sndl *root)
{
	if(root == NULL)
		return;
    cout<<root->data<<" ";
	print_inorder(root->prv); 

	//cout<<root->data<<" ";

	print_inorder(root->next);
}
sndl *DLL_to_BST_util1(sndl *&head,int n)
{
	if(n<=0)
		return NULL;

	sndl *left,*root;

	left=DLL_to_BST_util1(head,n/2);

	root=head;
	root->prv=left;
	head=head->next;

	root->next=DLL_to_BST_util1(head,n-n/2-1);

	return root;
}
void DLL_to_BST()
{
	int i,j,k,m,n,t,size;
	sndl *head=NULL,*tail=NULL;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;
	cout<<"Enter sorted DLL:"<<endl;
	f(i,0,n)
	{
		cin>>m;
		formation_dll(head,tail,m);
	}
    size=get_size(head);
    //sndl *root=DLL_to_BST_util(0,size-1,head);
    sndl *root=DLL_to_BST_util1(head,size);
    print_inorder(root);
    cout<<endl;
}
void BST_to_DLL_util(sn *root,sn *&prev,sn *&head)
{
	if(root == NULL)
		return;

	BST_to_DLL_util(root->lchild,prev,head);

	if(prev!=NULL)
	{
		prev->rchild=root;
		root->lchild=prev;
	}
	
	if(prev==NULL)
		head=root;

	prev=root;

	BST_to_DLL_util(root->rchild,prev,head);
}

void print_DLL(sn *head)
{
	sn *tmp=head,*tail;
	cout<<"New formed DLL is:"<<endl;
	while(tmp!=NULL)
	{
		if(tmp->rchild == NULL)
			tail=tmp;

		cout<<tmp->data<<" ";
		tmp=tmp->rchild;
	}
	cout<<endl;
    while(tail!=NULL)
    {
    	cout<<tail->data<<" ";
    	tail=tail->lchild;
    }
    cout<<endl;

}
void BST_to_DLL(sn *root)
{
	sn *head=NULL,*prev=NULL;
	BST_to_DLL_util(root,prev,head);
	print_DLL(head);
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
		
	//inorder(root);
	//search(root);
	//Delete(root);
	//successor(root);
	//predecessor(root);
	//check_BST(root);
	//lca(root);
	//BST_array();
	//kth_smallest(root);
	//print_in_range(root);
	//sorted_array_BST();
	//largest_BST(root);********************************************
	//is_same_BST();//two given arrays represent same BST or not**********
        //add_all_greater_values(root);
        //remove_outside_range(root);******
        //one_child();
        //merge(root,n);
        //DLL_to_BST();*****************************************Two methods O(nlogn),O(n).
        //BST_to_DLL(root);
	get_ancestors(root);
}
