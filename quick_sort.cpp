#include<bits/stdc++.h>//heap sort and quick sort are not stable sort.
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
	int a,b;
};
int get_piv_first(int arr[],int low,int high)
{
	int i=low+1,tmp,pivot=arr[low],j=high;
	while(i<=j)
	{
		while(i<=high && arr[i]<=pivot)
			i++;

		while(arr[j]>pivot)
			j--;

		if(i<j)
		{
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;
			j--;
		}
	}
	
	arr[low]=arr[j];
	arr[j]=pivot;

	return j;
}
int get_piv_last(int arr[],int low,int high)
{
	int i=low,j=high-1,pivot=arr[high],tmp;

	while(i<=j)
	{
		while(j>=low && arr[j]>=pivot)
			j--;
		
		while(arr[i]<pivot)
			i++;
		
		if(i<j)
		{
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;
			j--;
		}
	}
	arr[high]=arr[i];
	arr[i]=pivot;
	return i;
}
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int get_piv_first1(int arr[],int low,int high)
{
	int pivot=arr[low],h=high,j;
    
    for(j=high;j>low;j--)
    {
    	if(arr[j]>=pivot)
    	{
    		swap(&arr[j],&arr[h--]);
    	}
    }
    swap(&arr[h],&arr[low]);
    return (h);
}
void quick_sort(int arr[],int low,int high)
{
	if(low>=high)
		return;

	int pivloc=get_piv_first1(arr,low,high);
	quick_sort(arr,low,pivloc-1);
	quick_sort(arr,pivloc+1,high);
}
void fun(int arr[],int low,int high)
{
	int i,index;
	cin>>index;
	
	i=get_piv_last(arr,low,index);
	get_piv_first(arr,i,high);
	
	f(i,1,high+1)
	cout<<arr[i]<<" ";
	cout<<endl;
}
void get_piv(int arr[],int low,int high,int &i,int &j)
{
	if((high-low)<=1)
	{
		if(arr[low] > arr[high])
			swap(&arr[low],&arr[high]);
		i=low;
		j=high;
		return;
	}
	int mid=low,pivot=arr[high];

	while(mid<=high)
	{
		if(arr[mid]<pivot)
			swap(&arr[mid++],&arr[low++]);
		else if(arr[mid]==pivot)
			mid++;
		else
			swap(&arr[mid],&arr[high--]);
	}
	i=low-1;
	j=mid;
}
void three_way_quick_sort(int arr[],int low,int high)
{
	int i,j;
	if(low<high)
	{
	get_piv(arr,low,high,i,j);

	three_way_quick_sort(arr,low,i);
	three_way_quick_sort(arr,j,high);
    }
}
void swap_structure(sn *p,sn *q)
{
	sn tmp;
	tmp=*p;
	*p=*q;
	*q=tmp;
}
int get_piv_structure(sn arr[],int low,int high)
{
	sn pivot=arr[high];
	int i=low-1,j;

	f(j,low,high)
	{
		if(arr[j].a < pivot.a)
		{
			i++;
			swap_structure(&arr[j],&arr[i]);
		}
		else if(arr[j].a == pivot.a)
		{
			if(arr[j].b < pivot.b)
			{
				i++;
				swap_structure(&arr[j],&arr[i]);
			}
		}
	}
	swap_structure(&arr[i+1],&arr[high]);
	return (i+1);
}
void structure_quick_sort(sn arr[],int low,int high)
{
	if(low<high)
	{
	int pivloc=get_piv_structure(arr,low,high);
	structure_quick_sort(arr,low,pivloc-1);
	structure_quick_sort(arr,pivloc+1,high);
    }
}
int main()
{
	lli i,j,k,m,n,t;
	cin>>n;
	sn arr[n+1];
	f(i,1,n+1)
	cin>>arr[i].a>>arr[i].b;

    //fun(arr,1,n);
	//quick_sort(arr,1,n);
	structure_quick_sort(arr,1,n);
	f(i,1,n+1)
	cout<<arr[i].a<<" "<<arr[i].b<<endl;
	//iterative_quick_sort();//********************
}