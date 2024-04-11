/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e5+10;
PII ee[SIZE];
VPII e[SIZE];
bool u[SIZE];
int lat[SIZE];
int v[SIZE],vid;
int ss[SIZE];
int bk[SIZE];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int n,m;
bool ou[SIZE];
void dfs(int x,int lt){
    u[x]=1;
    v[x]=bk[x]=vid++;
    int outer=0;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        int eid=e[x][i].S;
        if(y==lt)continue;
        if(!u[y]){
            lat[y]=eid;
            dfs(y,x);
            if(bk[y]<v[x]){
                DEBUG("%d,%d:(%d,%d)\n",x,y,v[x],bk[y]);
                if(outer){
                    U.uu(outer,ss[y]);
                }
                outer=ss[y];
                bk[x]=min(bk[x],bk[y]);
            }
        }
        else if(v[y]<v[x]){
            ou[eid]=1;
            bk[x]=min(bk[x],v[y]);
            if(outer){
                U.uu(outer,eid);
            }
            outer=eid;
        }
    }
    ss[x]=outer;
    DEBUG("%d: %d\n",x,ss[x]);
}
int sp[SIZE];
VI an;
int main(){
    R(n,m);
    U.init(m+1);
    FOR(i,1,m){
        int x ,y;
        R(x,y);
        ee[i]=MP(x,y);
        e[x].PB(MP(y,i));
        e[y].PB(MP(x,i));
    }
    FOR(i,1,n){
        if(!u[i]){
            dfs(i,i);
        }
    }
    FOR(i,1,m){
        if(ou[i]&&U.num[U.find(i)]==1){
            if(v[ee[i].F]>v[ee[i].S])swap(ee[i].F,ee[i].S);
            int now=ee[i].S;
            sp[i]=1;
            while(now!=ee[i].F){
                sp[lat[now]]=1;
                now=ee[lat[now]].F+ee[lat[now]].S-now;
            }

        }
    }
    FOR(i,1,m){
        if(sp[i])an.PB(i);
    }
    W(SZ(an));
    W(an);
    return 0;
}