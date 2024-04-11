#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define FOREACH(i,t) FORE(i,t)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define wez(x) int x; CZ(x);
#define wez2(x,y) int x,y; CZ2(x,y);
#define wez3(x,y,z) int x,y,z; CZ3(x,y,z);
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
inline void pisz (int x) { printf("%d\n", x); }

int a[1111][1111];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;CZ(n);
    int q;CZ(q);
    FOR(i,q)
    {
        int x,y;CZ2(x,y);
        a[x][y]=1;
    }
    int wyn=0;
    for(int s=2,t=n-1;s<=t;s++,t--)
    {
        if (s==t)
        {
            int ile1=0,ile2=0;
            REP(i,1,n)ile1+=a[i][s];
            REP(i,1,n)ile2+=a[s][i];
            if (!ile1 || !ile2) wyn++;
        }
        else
        {
            bool ok[4]={0};
            {int ile=0;REP(i,1,n)ile+=a[i][s];if (!ile)ok[0]=1;}
            {int ile=0;REP(i,1,n)ile+=a[i][t];if (!ile)ok[1]=1;}
            {int ile=0;REP(i,1,n)ile+=a[s][i];if (!ile)ok[2]=1;}
            {int ile=0;REP(i,1,n)ile+=a[t][i];if (!ile)ok[3]=1;}
            int best=0;
            FOR(m,1<<4)
            {
                bool zle=0;
                vector<pii> v;
                FOR(j,4) if (((1<<j)&m) && !ok[j]) zle=1;
                if (zle) continue;
                FOR(j,4) if (((1<<j)&m))
                {
                    if (j==0) v.pb(mp(1,0));
                    if (j==1) v.pb(mp(2,0));
                    if (j==2) v.pb(mp(0,1));
                    if (j==3) v.pb(mp(0,2));
                }
                FOR(g,1<<(v.sz))
                {
                    vector<pii> f;
                    FOR(j,v.sz)
                    {
                        if ((1<<j)&g)f.pb(mp(-v[j].fi,-v[j].se));
                        else f.pb(mp(v[j].fi,v[j].se));
                    }
                    bool zlo=0;
                    FOR(i,f.sz)FOR(j,i)
                    {
                        pii p=f[i],q=f[j];
                        if (p.fi*q.fi+p.se*q.se!=0) continue;
                        if (q.fi) swap(p,q);
                        if (p.fi==q.se)zlo=1;
                        if (abs(p.fi)!=abs(q.se) && p.fi*q.se<0)zlo=1;
                    }
                    if (!zlo) {REMAX(best,__builtin_popcount(m));break;}
                }
                
            }
            wyn+=best;
        }
    }
    cout<<wyn;

    return 0;
}