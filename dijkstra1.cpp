#include<bits/stdc++.h>//THIS IS ACTUALLY UNIFORM COST SEARCH.
using namespace std;
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define si(a) scanf("%d",&a);
#define slli(a) scanf("%lld",&a);
#define mp(a,b) make_pair(a,b)
#define INF 1000000007
#define MAX 100005
#define MAXN 1030
#define pb(a) push_back(a)
#define sn struct node
#define vec vector< pair<int,int>  >//coordinate,distance
vec graph[MAXN];
int msk[MAXN],d[MAXN][MAXN];
void fun(int n,int k)
{
    int i,j,m,curd,curv,curmsk,tov,tomsk,tod,ans;
    
    f(i,0,MAXN)
    {
        f(j,0,MAXN)
        d[i][j]=INF;
    }

    set<pair<int,pair<int,int> > >s;//distance,vertex,msk
    
    pair<int,pair<int,int> > tmp;

    pair<int,int>tmp1;

    s.insert(mp(0,mp(0,msk[0])));
    d[0][msk[0]]=0;
    
    set<pair<int,pair<int,int> > >::iterator it;
    vector<pair<int,int> >::iterator it1;

    while(!s.empty())
    {
        it=s.begin();
        tmp=*it;
        s.erase(it);
        curd=tmp.first;
        curv=tmp.second.first;
        curmsk=tmp.second.second;

        for(it1=graph[curv].begin();it1!=graph[curv].end();it1++)
        {
            tmp1=*it1;
            tov=tmp1.first;
            tomsk=curmsk|msk[tov];
            tod=curd+tmp1.second;
            if(tod < d[tov][tomsk])
            {
                s.erase(mp(tod,mp(tov,tomsk)));
                d[tov][tomsk]=tod;
                s.insert(mp(tod,mp(tov,tomsk)));
            }
        }
    }

    ans=INF;
    f(i,0,(1<<k))
    {
        f(j,0,(1<<k))
        {
            if( (i|j) == ((1<<k)-1) )
            {
                ans=min(ans,max(d[n-1][i],d[n-1][j]));
            }
        }
    }

    printf("%d\n",ans);
}
int main()
{
    int i,j,k,m,n,t,v1,v2,w,x,no;
    si(n);
    si(m);
    si(k);

    f(i,1,n+1)
    {
        msk[i-1]=0;
        si(no);
        f(j,0,no)
        {
            si(x);
            x--;
            msk[i-1]|=(1<<x);
        }
    }
    f(i,0,m)
    {
        si(v1);
        si(v2);
        si(w);
        v1--;
        v2--;
        graph[v1].pb(make_pair(v2,w));
        graph[v2].pb(make_pair(v1,w));
    }
    fun(n,k);
}