#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 1000000007
#define MAX 100005
#define pb(a) push_back(a)
#define sn struct node
#define sndl struct node_dll
sn *newNode(int data);
sndl{
	int data;
	sndl *next,*prv;
};
sn{
	int data;
	sn *next;
};
struct tree_node{
	int data;
	struct tree_node *lchild,*rchild;
};
struct tree_node *newNode1(int data)
{
	struct tree_node *tmp;
	tmp=(struct tree_node *)malloc(sizeof(struct tree_node));
	tmp->data=data;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	return tmp;
}
sn *formation(sn *head,int data)
{
	sn *tmp,*k;

	tmp=(sn *)malloc(sizeof(sn));
	tmp->data=data;
	tmp->next=NULL;

	if(head==NULL)
	{
		head=tmp;
		return head;
	}

	k=head;
	while(k->next!=NULL)
		k=k->next;

	k->next=tmp;
	return head;
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
void print(sn *head)
{
	sn *tmp;
	tmp=head;
	if(head==NULL)
	{
		cout<<"No element in list"<<endl;
		return;
	}
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
}
int find_length_recursive_util(sn *head)
{
	if(head==NULL)
		return 0;
	else
		return 1+find_length_recursive_util(head->next);
}
void find_length_recursive(sn *head)
{
	int l=find_length_recursive_util(head);

	cout<<"length is "<<l<<endl;
}
sn *swap_links_util_heads(sn *head,sn *b)
{
	sn *tmp1=head,*tmp2=head;

	while(tmp2->next!=b)
		tmp2=tmp2->next;

	tmp2->next=head;

	tmp1=head->next;
	head->next=b->next;
	b->next=tmp1;
	head=b;
	return head;
}
sn *swap_links_util(sn *head,int a,int b)
{
	sn *tmp,*ptr_a=head,*ptr_b=head,*ptr_a_prev=NULL,*ptr_b_prev=NULL;
    
    while(ptr_a->data!=a){
    	ptr_a_prev=ptr_a;
    	ptr_a=ptr_a->next;
    }

    while(ptr_b->data!=b){
    	ptr_b_prev=ptr_b;
    	ptr_b=ptr_b->next;
    }

    if(ptr_a_prev!=NULL){
    	//head=swap_links_util_heads(head,ptr_b);
    	//return head;
    	ptr_a_prev->next=ptr_b;
    }
    else
    	head=ptr_b;
  

     if(ptr_b_prev!=NULL){
    	//head=swap_links_util_heads(head,ptr_a);
    	//return head;
    	ptr_b_prev->next=ptr_a;
    }
    else
    	head=ptr_a;

    //ptr_a_prev->next=ptr_b;
    //ptr_b_prev->next=ptr_a;

    tmp=ptr_a->next;
    ptr_a->next=ptr_b->next;
    ptr_b->next=tmp;
    return head;
}

void swap_links(sn *head)
{
	int a,b;
	while(1){
	cout<<"enter two numbers to be swapped"<<endl;
	
	cin>>a>>b;
	
	head=swap_links_util(head,a,b);
	print(head);}
}
int find_middle_util(sn *head)
{
	sn *ptr1=head,*ptr2=head;
    while(1)
    {
    	if(ptr2==NULL || ptr2->next==NULL)
    		return ptr1->data;

    	ptr1=ptr1->next;
    	ptr2=ptr2->next->next;
    }
}
void find_middle(sn *head)
{
	int mid;
	mid=find_middle_util(head);

	cout<<"Middle element is "<<mid<<endl;
}
sn *delete_ll_util(sn *head)
{
	if(head==NULL)
		return head;

	head->next=delete_ll_util(head->next);
	free(head);
	return NULL;
}
void delete_ll(sn *head)
{
	head=delete_ll_util(head);
	print(head);
}
sn *reverse_util(sn *head)
{
	sn *cur=head,*prv=NULL,*nex;
	while(cur!=NULL)
	{
		nex=cur->next;
		cur->next=prv;
		prv=cur;
		cur=nex;
	}
	head=prv;
	return head;
}
void reverse(sn *head)
{
	head=reverse_util(head);
	print(head);
}
bool check_cycle_util(sn *head)
{
	sn *ptr1=head,*ptr2=head->next;
	while(ptr2!=NULL)
	{
		if(ptr1==ptr2)
			return true;

		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}
	return false;
}
void check_cycle(sn *head)
{
	if(check_cycle_util(head))
		cout<<"linklist is cyclic"<<endl;

	else
		cout<<"linklist is not cyclic"<<endl;
}
sn *add_manually(sn *head)
{
	sn *tmp;
	tmp=(sn *)malloc(sizeof(sn));
	tmp->data=1;
	tmp->next=NULL;
	head=tmp;
	
	tmp=(sn *)malloc(sizeof(sn));
	tmp->data=1;
	tmp->next=head;
	head->next=tmp;

	return head;
}
sn *merge_util(sn *head,sn *head1,sn *head2)
{
	sn *tmp=head,*tmp1=head1;

	while(tmp!=NULL && tmp1!=NULL)
	{
		if(tmp->data  < tmp1->data){
			head2=formation(head2,tmp->data);
			tmp=tmp->next;
		}
		else{
			head2=formation(head2,tmp1->data);
			tmp1=tmp1->next;
		}
	}

	while(tmp!=NULL)
	{
		head2=formation(head2,tmp->data);
		tmp=tmp->next;
	}

	while(tmp1!=NULL)
	{
		head2=formation(head2,tmp1->data);
		tmp1=tmp1->next;
	}
	return head2;
}
sn *inplace_merge_util(sn *head,sn *head1)
{
	sn *tmp1=head,*tmp2=head1,*tmp;

	while(tmp1!=NULL && tmp2!=NULL)
	{
		if(tmp1->data <= tmp2->data)
		{
			if(tmp1->next==NULL || tmp2->data < tmp1->next->data)
			{
				tmp=tmp1->next;
				tmp1->next=tmp2;
				tmp1=tmp;
			}
			else
				tmp1=tmp1->next;
		}

		else
		{
			if(tmp2->next==NULL || tmp1->data <= tmp2->next->data)
			{
				tmp=tmp2->next;
				tmp2->next=tmp1;
				tmp2=tmp;
			}
			else
				tmp2=tmp2->next;
		}
	}

	if(head==NULL)
		return head1;

	if(head1==NULL)
		return head;


	if(head->data <= head1->data)
		return head;

	else if(head1->data < head->data)
		return head1;
}
sn *recursive_merge_util(sn *head1,sn *head2)
{
	sn *head;

	if(head1==NULL)
		return head2;

	if(head2==NULL)
		return head1;

	if(head1->data <= head2->data)
	{
		head=head1;
		head->next=recursive_merge_util(head1->next,head2);
	}
	else
	{
		head=head2;
		head->next=recursive_merge_util(head1,head2->next);
	}
	return head;
}

void merge(sn *head)
{
	int n,data,i;
	sn *head2=NULL,*head1=NULL;
	cout<<"Enter number of elements in second linklist"<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	f(i,0,n)
	{
		cin>>data;
		head1=formation(head1,data);
	}
	//print(head1);
	head2=recursive_merge_util(head,head1);
	print(head2);
}

bool check_palindrome_util(sn *head,sn* &H)
{
	if(head == NULL)
		return true;

	if(check_palindrome_util(head->next,H))
	{
		if(head->data == H->data)
		{
			H=H->next;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void check_palindrome(sn *head)
{
	sn *H=head;
	if(check_palindrome_util(head,H))
		cout<<"Is Palindrome"<<endl;
	else
		cout<<"not palindrome"<<endl;
}
sn *remove_duplicates_util(sn *head)
{
	int curr;
	sn *tmp1,*tmp=head,*temp;

	while(tmp!=NULL)
	{
		curr=tmp->data;

		tmp1=tmp->next;
		while(tmp1!=NULL && tmp1->data == curr)
			{
				temp=tmp1;
				tmp1=tmp1->next;
				free(temp);
			}

		tmp->next=tmp1;
		tmp=tmp1;
	}
	return head;
}
sn *remove_duplicates_util_unsorted(sn *head)//O(n^2)
{
	sn *tmp=head,*tmp1,*prv;

	while( tmp!=NULL && tmp->next != NULL)
	{
		prv=tmp;
		tmp1=tmp->next;

		while(tmp1!=NULL)
		{
			if(tmp1->data == tmp->data)
			{
				if(tmp1->next==NULL)
				{
					prv->next=NULL;
					tmp1=NULL;
				}
				else
				{
					prv->next=tmp1->next;
					tmp1=prv->next;
				}
			}
			else
			{
				prv=tmp1;
				tmp1=tmp1->next;
			}
		}
		tmp=tmp->next;
	}
	return head;
}
void remove_duplicates(sn *head)
{
	head=remove_duplicates_util_unsorted(head);//O(n) solution can be made with hashing

	print(head);
}
sn *swap_adjacent_util(sn *head)
{
	sn *curr=head,*nex;
	int tmp;
    
    if(curr==NULL || curr->next==NULL)
    	return curr;

    nex=curr->next;

	while(curr!=NULL && curr->next!=NULL)
	{
		tmp=curr->data;
		curr->data=nex->data;
		nex->data=tmp;
		curr=nex->next;
		if(curr==NULL)
			break;
		nex=curr->next;
	}
	return head;
}
void swap_adjacent(sn *head)
{
	head=swap_adjacent_util(head);

	print(head);
}
sn *find_intersection_util(sn *head,sn *head1,sn *head2)
{
	sn *tmp1=head1,*tmp2=head2;

	while(tmp1!=NULL && tmp2!=NULL)
	{
		if(tmp1->data < tmp2->data)
			tmp1=tmp1->next;

		else if(tmp2->data  < tmp1->data)
			tmp2=tmp2->next;

		else
		{
			head=formation(head,tmp1->data);
			tmp1=tmp1->next;
			tmp2=tmp2->next;
		}
	}
	return head;
}
void find_intersection(sn *head1)
{
	int n,m,i;
	sn *head2=NULL,*head=NULL;
	cout<<"Enter number of elements in 2nd ll"<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	f(i,0,n)
	{
		cin>>m;
		head2=formation(head2,m);
	}
	head=find_intersection_util(head,head1,head2);
    print(head);
}
sn *delete_alternate_util(sn *head)
{
	int count=0;
	sn *tmp=head,*prv=NULL;

	while(tmp!=NULL)
	{
		if(count==0)
		{
			prv=tmp;
			tmp=tmp->next;
			count++;
		}
		else
		{
			if(tmp->next==NULL)
			{
				prv->next=NULL;
				break;
			}
			tmp->data=tmp->next->data;
			free(tmp->next);
			tmp->next=tmp->next->next;
			count=0;
		}
	}
	return head;
}
void delete_alternate(sn *head)
{
	head=delete_alternate_util(head);
	print(head);
}
sn *alternating_split_util(sn *head,sn *(&head1),sn *(&head2))
{
	if(head == NULL)
		return NULL;

	head1=formation(head1,head->data);

	sn *nex=head->next;

	if(nex == NULL)
		return nex;

	head2=formation(head2,nex->data);

	alternating_split_util(nex->next,head1,head2);
}
void alternating_split(sn *head)
{
	sn *head1=NULL,*head2=NULL;
	alternating_split_util(head,head1,head2);

	print(head1);
	print(head2);
}
void get_mid(sn *head,sn *(&front),sn *(&back))
{
	sn *slow=head,*fast=slow->next;

	while(fast != NULL && fast->next != NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	back=slow->next;
	slow->next=NULL;
	front=head;
}
void merge_sort_util(sn *(&head))
{
	if(head == NULL || head->next == NULL)
		return;

	sn *a,*b;

	get_mid(head,a,b);

	merge_sort_util(a);
	merge_sort_util(b);

	head=recursive_merge_util(a,b);
}
void merge_sort(sn *head)
{
	merge_sort_util(head);
	cout<<"Sorted link list is"<<endl;
	print(head);
}
sn *reverse_kalternate_util(sn *head,int k)
{
	if(head==NULL || head->next==NULL)
		return head;

	sn *tmp,*beg=head,*end=head;
	int count=0;

	while(count<k-1 && end->next!=NULL)
	{
		count++;
		end=end->next;
	}
	tmp=end->next;
	end->next=NULL;
	head=reverse_util(head);
	beg->next=reverse_kalternate_util(tmp,k);
	return head;
}
void reverse_kalternate(sn *head)
{
	int k;
	cout<<"Enter value of k"<<endl;
	cin>>k;
	head=reverse_kalternate_util(head,k);
	print(head);
}
int delete_right_util(sn *head)
{
	if(head->next==NULL)
		return head->data;

	int m=delete_right_util(head->next);

	m=max(m,head->data);

	if(m!=head->data)
	{
		head->data=head->next->data;
		head->next=head->next->next;
	}
	return m;
}
void delete_right(sn *head)
{
	delete_right_util(head);
	print(head);
}
sn *even_odd_util(sn *head)
{
	sn *new_head,*prv,*tmp,*end_odd,*end_even,*first_odd;
	if(head==NULL || head->next==NULL)
		return head;

	if(head->data % 2!=0)
	{
		first_odd=head;
		tmp=head;
		prv=NULL;

		while( tmp!=NULL && tmp->data %2!=0)
		{
			prv=tmp;
			tmp=tmp->next;
		}
		if(tmp==NULL)
			return head;
		prv->next=NULL;
		end_odd=prv;
		new_head=tmp;

		while(1)
		{
			while( tmp!=NULL && tmp->data %2 ==0 )
			{
				prv=tmp;
				tmp=tmp->next;
			}
			end_even=prv;
			prv->next=NULL;

			if(tmp==NULL)
			{
				end_even->next=first_odd;
				break;
			}

            end_odd->next=tmp;

			while( tmp!=NULL && tmp->data % 2 != 0)
			{
				prv=tmp;
				tmp=tmp->next;
			}
			end_odd=prv;
			prv->next=NULL;

			if(tmp==NULL)
			{
				end_even->next=first_odd;
				break;
			}
			end_even->next=tmp;
		}
		return new_head;
	}
	else
	{
		tmp=head;
		while(tmp!=NULL && tmp->data %2==0)
			{
				prv=tmp;
				tmp=tmp->next;
			}
			prv->next=even_odd_util(tmp);
			return head;
	}
}
void even_odd(sn *head)
{
	head=even_odd_util(head);
	print(head);
}
sn *add_util(sn *head,sn *head1,sn *head2,int carry)
{
	if(head1 == NULL && head2 == NULL)
		{
			if(carry!=0)
			{
				sn *tmp=newNode(carry);
				head=formation(head,carry);
			}
			return head;
		}

	int a=0,b=0;

	if(head1 != NULL)
		a=head1->data;

	if(head2 != NULL)
		b=head2->data;

	int m=(a+b+carry)%10;
	int Carry=(a+b+carry)/10;

	head=formation(head,m);

	if(head1 != NULL && head2 != NULL)
		return add_util(head,head1->next,head2->next,Carry);

	if(head1 == NULL)
		return add_util(head,head1,head2->next,Carry);

	if(head2 == NULL)
		return add_util(head,head1->next,head2,Carry);
}
void add(sn *head1)
{

	int n,m,i;
	sn *head2=NULL,*head=NULL;
	cout<<"Enter number of elements in 2nd ll"<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	f(i,0,n)
	{
		cin>>m;
		head2=formation(head2,m);
	}
	head=add_util(head,head1,head2,0);
	print(head);
}
void print_dll(sndl *head,sndl *tail)
{
	sndl *tmp;
	tmp=head;
	while(tmp!=NULL){
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;

	tmp=tail;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->prv;
	}
	cout<<endl;
}
sndl *merge_dll_util(sndl *head1,sndl *head2,sndl *prev)
{
	sndl *head;

	if(head1 == NULL)
	{
		head2->prv=prev;
		return head2;
	}
	if(head2 == NULL)
	{
		head1->prv=prev;
		return head1;
	}
	if(head1->data < head2->data)
	{
		head=head1;
		head->prv=prev;
		prev=head;
		head->next=merge_dll_util(head1->next,head2,prev);
	}
	else
	{
		head=head2;
		head->prv=prev;
		prev=head;
		head->next=merge_dll_util(head1,head2->next,prev);
	}
	return head;
}
void merge_dll(sndl *head1)
{
	int i,j,k,m,n,t;
	sndl *head2=NULL,*tail=NULL,*tail2=NULL;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		formation_dll(head2,tail2,m);
	}
	sndl *prev=NULL;
	sndl *head=merge_dll_util(head1,head2,prev);
	tail=head;

	while(tail->next!=NULL)
		tail=tail->next;
	
	print_dll(head,tail);
}
void call_dll()
{
	int i,j,k,m,n,t;
	sndl *head=NULL,*tail=NULL;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;
	f(i,0,n)
	{
		cin>>m;
		formation_dll(head,tail,m);
	}
	merge_dll(head);
	
}
sn *back(sn *pivloc,sn *head)
{
	if(pivloc == head)
		return NULL;

	sn *tmp=head;
	while(tmp->next != pivloc)
		tmp=tmp->next;

	return tmp;
}
sn *front(sn *pivloc,sn *tail)
{
	if(pivloc == tail)
		return NULL;

	return (pivloc->next);
}
sn *get_piv(sn *head,sn *tail)
{
	int temp;

	if(head == tail)
		return head;

	sn *pivot=tail,*tmp=head,*i=NULL;

	while(tmp != tail)
	{
		if(tmp->data <= pivot->data)
		{
			if(i == NULL)
				i=head;
			else
				i=i->next;

			temp=tmp->data;
			tmp->data=i->data;
			i->data=temp;
		}
		tmp=tmp->next;
	}

    if(i == NULL)
    	i=head;
    else
    	i=i->next;

	temp=pivot->data;
	pivot->data=i->data;
	i->data=temp;

	return i;
}
void quick_sort_util(sn *head,sn *tail)
{
	if(head!=NULL && tail!=NULL && head!=tail)
	{
		sn *pivloc=get_piv(head,tail);//O(n)
		quick_sort_util(head,back(pivloc,head));
		quick_sort_util(front(pivloc,tail),tail);
	}
}
void quick_sort(sn *head)
{
	sn *tail=head;

	while(tail->next!=NULL)
		tail=tail->next;

	quick_sort_util(head,tail);
	print(head);
}
sn *newNode(int data)
{
	sn *tmp;
	tmp=(sn *)malloc(sizeof(sn));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
sn *sum(sn *first,sn *second,int &carry)
{
	if(first == NULL)
		return NULL;

	sn *head=sum(first->next,second->next,carry);

	int s=first->data+second->data+carry;
	carry=s/10;
	s=s%10;
	sn *new_head=newNode(s);
	new_head->next=head;

	return new_head;
}
void add_carry(sn *first,sn *&head,int &carry,int diff)
{
	if(diff < 0)
		return;

	add_carry(first->next,head,carry,diff-1);

	int s=first->data+carry;
	carry=s/10;
	s=s%10;

	sn *tmp=newNode(s);
	tmp->next=head;
	head=tmp;
}
sn *add_util(sn *first,int l1,sn *second,int l2)
{
	if(first == NULL)
		return second;

	if(second == NULL)
		return first;

	int diff,carry=0,i;
	sn *tmp,*head;

	if(l1 == l2)
		head=sum(first,second,carry);
    else{
	if(l2 > l1)
	{
		tmp=first;
		first=second;
		second=tmp;
		swap(&l1,&l2);
	}
	diff=l1-l2;
	tmp=first;
	f(i,0,diff)
	tmp=tmp->next;

	head=sum(tmp,second,carry);

	add_carry(first,head,carry,diff-1);
    }
	if(carry > 0)
	{
		tmp=newNode(carry);
		tmp->next=head;
		head=tmp;
	}
	return head;
}
void add1(sn *head1)
{
    int i,j,k,m,n,t,l1,l2;
	sn *tmp,*head2=NULL;
	cin>>n;

	f(i,0,n)
	{
		cin>>m;
		head2=formation(head2,m);
	}
    tmp=head1;
    l1=0;
    while(tmp != NULL)
    {
    	tmp=tmp->next;
    	l1++;
    }
    l2=n;
    sn *head=add_util(head1,l1,head2,l2);
    print(head);
}
sn *swap1_util(sn *head,sn *tail)
{
	if(head == tail)
		return head;

	if(tail->next == head)
		return NULL;

	sn *tmp=head;
	while(tmp->next != tail)
		tmp=tmp->next;

	sn *new_head,*new_tail;
	new_head=head->next;
	new_tail=tmp;
	tmp->next=NULL;
	head->next=tail;
	tail->next=swap1_util(new_head,new_tail);
	return head;
}
void swap1(sn *head)
{
	sn *tmp,*tail;
	tail=head;
	while(tail->next != NULL)
		tail=tail->next;

	head=swap1_util(head,tail);
	print(head);
}
void even_odd1_util(sn *root,sn *&even,sn *&odd,sn *&even_head,sn *&odd_head)
{
	if(root == NULL)
		return;

	if(root->data%2 == 0)
	{
		if(even_head == NULL)
		{
			even_head=root;
			even=root;
		}
		else
		{
			even->next=root;
			even=root;
		}
	}
	else
	{
		if(odd_head == NULL)
		{
			odd_head=root;
			odd=root;
		}
		else
		{
			odd->next=root;
			odd=root;
		}
	}
	sn *tmp=root->next;
	root->next=NULL;
	even_odd1_util(tmp,even,odd,even_head,odd_head);

}
void even_odd1(sn *head)
{
	sn *even_head=NULL,*odd_head=NULL,*even=NULL,*odd=NULL;
	even_odd1_util(head,even,odd,even_head,odd_head);
	if(even_head==NULL)
		print(odd_head);
	else if(odd_head==NULL)
		print(even_head);
	else
	{
		head=even_head;
		even->next=odd_head;
		print(head);
	}

}
void inorder(struct tree_node *root)
{
	if(root == NULL)
		return;

	inorder(root->lchild);

	cout<<root->data<<" ";
	
	inorder(root->rchild);
}
void BT_construction_ll(sn *head)
{
	queue<struct tree_node *>q;
	sn *tmp;
	tmp=head;
	struct tree_node *tmp_tree,*root,*left,*right;
    root=newNode1(tmp->data);
    tmp_tree=root;
    q.push(tmp_tree);

    while(tmp != NULL)
    {
    	tmp_tree=q.front();
    	q.pop();

    	tmp=tmp->next;
    	if(tmp==NULL)
    		break;
    	
    	left=newNode1(tmp->data);
    	tmp_tree->lchild=left;
    	q.push(left);

    	tmp=tmp->next;
    	if(tmp==NULL)
    		break;

    	right=newNode1(tmp->data);
    	tmp_tree->rchild=right;
    	q.push(right);
    }
    inorder(root);
    cout<<endl;
}
int main()
{
	int i,j,k,m,n,t;
	sn *head=NULL;
	cin>>n;

	f(i,0,n)
	{
		cin>>m;
		head=formation(head,m);
	}
	//head=add_manually(head);
	//print(head);
	//add(head);
	//remove_loop//******code is not made here
	//even_odd(head);//***************************************
	//delete_right(head);
	//reverse_kalternate(head);//****************
	//merge_sort(head);****************
	//alternating_split(head);//recursive,cool isn't
	//delete_alternate(head);//go for recursive solution
	//find_intersection(head);//O(m+n)Analyse
	//swap_adjacent(head);
	//remove_duplicates(head);
	//check_palindrome(head);/*Recursive cool one */
	//merge(head);
	//check_cycle(head);
	//reverse(head);
	//find_middle(head);
	//delete_ll(head);
	//find_length_recursive(head);
	//swap_links(head);
	//call_dll();
	//quick_sort(head);
	//add1(head);***************
	//even_odd1(head);
	//swap1(head);
	BT_construction_ll(head);
}
