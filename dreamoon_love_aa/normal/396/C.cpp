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
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
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
const int SIZE = 1e6+10;
struct BIT2{
    LL _d[SIZE];
    int _n;
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(LL)*(_n+1));
    }
    void ins(int x,LL v){
        for(;x;x-=x&-x)ADD(_d[x],v);
    }
    void ins_range(int x,int y,LL v){
        ins(y,v);
        if(x>1)ins(x-1,-v);
    }
    LL qq(int x){
        LL res=0;
        if(x<=0||x>_n)return 0;
        for(;x<=_n;x+=x&-x)ADD(res,_d[x]);
        return res;
    }
}bit[2];
VI e[SIZE];
int l[SIZE],r[SIZE],id,lv[SIZE];
void dfs(int x,int v){
    lv[x]=v;
    l[x]=r[x]=++id;
    for(int y:e[x]){
        dfs(y,v+1);
        r[x]=r[y];
    }
}
int main(){
    int n;
    R(n);
    FOR(i,2,n){
        int x;
        R(x);
        e[x].PB(i);
    }
    dfs(1,0);
    int q;
    R(q);
    REP(i,2)bit[i].init(n);
    while(q--){
        int ty;
        R(ty);
        if(ty==1){
            int v,x,k;
            R(v,x,k);
            bit[0].ins_range(l[v],r[v],x+(LL)lv[v]*k);
            bit[1].ins_range(l[v],r[v],k);
        }
        else{
            int v;
            R(v);
            LL ans=bit[0].qq(l[v]);
            ADD(ans,-bit[1].qq(l[v])*lv[v]);
            W(ans);
        }
    }
    return 0;
}