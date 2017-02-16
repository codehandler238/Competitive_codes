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
#define mp(a,b) make_pair(a,b)
#define vec vector<pair<int,int> >
vec graph[MAX];
int d[MAX],visited[MAX];
void fun(int start,int n)
{
    int i,j,k,m,count=n,sum=0,newv,newd,curv,curd;
    set<pair<int,int> >s;
    pair<int,int>cur,tmp;
    set<pair<int,int> >::iterator it;
    vector<pair<int,int> >::iterator it1;
    
    f(i,0,n){
    d[i]=INF;
    visited[i]=0;
    }

    s.insert(mp(0,start));
    d[start]=0;

    while(count--)
    {
        it=s.begin();
        cur=*it;
        s.erase(it);
        curd=cur.first;
        sum+=curd;
        curv=cur.second;
        visited[curv]=1;

        for(it1=graph[curv].begin();it1!=graph[curv].end();it1++)
        {
            tmp=*it1;
            newv=tmp.first;
            newd=tmp.second;
            if(d[newv] > newd && visited[newv]==0)
            {
                s.erase(mp(d[newv],newv));
                d[newv]=newd;
                s.insert(mp(newd,newv));
            }
        }
    }
    cout<<sum<<endl;
}
int main()
{
    int i,j,k,m,n,t,v1,v2,w,s;
        si(n);
        si(m);
        f(i,0,m)
        {
            si(v1);
            si(v2);
            si(w);
            v1--;
            v2--;
            graph[v1].pb(mp(v2,w));
            graph[v2].pb(mp(v1,w));
        }
        si(s);
        s--;
        fun(s,n);
}