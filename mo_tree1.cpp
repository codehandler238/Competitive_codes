/*
You will be given a rooted Tree T of N nodes where each node is associated with a value A[node]. You need to handle 
Q queries, each comprising one integer u. In each query you must report the number of distinct values in the subtree rooted at u. 
In other words, if you store all the values in the subtree rooted at u in a set, what would be the size of this set?
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define MOD 100000000007
#define MAX 500005
#define PI 3.14159265
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sn struct node
sn{
    lli L,R,I;
};
lli frequency[MAX],Size[MAX],values[MAX],Map[MAX],ans[MAX],block;
vector<vector<lli> >graph(MAX);
vector<int>prefix;
sn brr[MAX];

bool cmp(sn s1,sn s2)
{
    if(s1.L/block != s2.L/block)
        return (s1.L/block < s2.L/block);

    return (s1.R < s2.R);
}

lli dfs(lli src,lli prv,lli &I)
{
    lli count=0;
    
    prefix.pb(src);

    Map[src]=I;
    
    I++;

    vector<lli>::iterator it;

    for(it=graph[src].begin();it!=graph[src].end();it++)
    {
        if(*it != prv)
            count+=dfs(*it,src,I);
    }

    Size[src]=count;

    return 1+count;
}
void MO(lli q,lli n)
{
    lli i,j,k,m,t,L,R,curL,curR,cursum,count,index;

    block=sqrt(n);

    sort(brr,brr+q,cmp);

    curL=0;
    curR=0;
    cursum=0;
    count=0;

    f(i,0,q)
    {
        L=brr[i].L;
        R=brr[i].R;

        while(curL < L)
        {
            //cursum-=values[curL];
            frequency[values[prefix[curL]]]--;
            if(frequency[values[prefix[curL]]] == 0)
                count--;
            curL++;
        }

        while(curL > L)
        {
            //cursum+=values[curL-1];
            frequency[values[prefix[curL-1]]]++;
            if(frequency[values[prefix[curL-1]]] == 1)
                count++;
            curL--;
        }

        while(curR <= R)
        {
            //cursum+=values[curR];
            frequency[values[prefix[curR]]]++;
            if(frequency[values[prefix[curR]]] == 1)
                count++;
            curR++;
        }

        while(curR > R+1)
        {
            //cursum-=values[curR-1];
            frequency[values[prefix[curR-1]]]--;
            if(frequency[values[prefix[curR-1]]] == 0)
                count--;
            curR--;
        }
        index=brr[i].I;
        //cout<<"L R "<<L<<" "<<R<<" "<<count<<endl;
        ans[index]=count;
    }
    
    f(i,0,q)
    cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    lli i,j,k,m,n,t,u,v,I,q;

    sn tmp;

    slli(n);

    f(i,0,n-1)
    {
        slli(u);

        slli(v);

        u--;
        v--;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    f(i,0,n)
    slli(values[i]);
    
    I=0;

    dfs(0,-1,I);
    
    slli(q);

    f(i,0,q)
    {
        slli(m);
        m--;
        
        tmp.L=Map[m];
        tmp.R=Map[m]+Size[m];
        tmp.I=i;

        brr[i]=tmp;
    }

    MO(q,n);
}