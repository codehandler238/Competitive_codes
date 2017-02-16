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
void build_heap(int heap[],int index)
{
	if(index == 1)
		return;

	int par,par_index,child=heap[index];

	while(index > 1)
	{
		par_index=index/2;
		par=heap[par_index];

		if(par > child)
			heap[index]=par;
		else
			break;

		index=par_index;
	}
	heap[index]=child;
}
void min_heapify(int heap[],int size,int index)
{
	int lchild,rchild,min_index;
	lchild=2*index;
	rchild=lchild+1;

	if(rchild < size)
	{
		if(heap[index] > heap[lchild] || heap[index] > heap[rchild])
		{
			if(heap[lchild] < heap[rchild])
				min_index=lchild;
			else
				min_index=rchild;

			swap(&heap[index],&heap[min_index]);

			min_heapify(heap,size,min_index);
		} 
	}
	else if(lchild < size)
	{
		if(heap[index] > heap[lchild])
		{
			swap(&heap[index],&heap[lchild]);
			min_heapify(heap,size,lchild);
		}
	}
}
int del(int heap[],int *size)
{
	int tmp,Min;
	tmp=heap[*size-1];
	Min=heap[1];
	heap[1]=tmp;
	(*size)--;
	min_heapify(heap,*size,1);
	return Min;
}
void heap_sort(int heap[],int size)
{
	while(size>1)
		cout<<del(heap,&size)<<" ";
	cout<<endl;
}
int main()
{
	int i,j,k,m,n,t,heap[100];
	cin>>n;
	int size=1;
	f(i,1,n+1)
	{
		cin>>m;
		heap[size++]=m;
		build_heap(heap,i);
	}
	heap_sort(heap,size);
}