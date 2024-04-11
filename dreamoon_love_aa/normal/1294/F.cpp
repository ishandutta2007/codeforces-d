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
vector<pair<int,int> >e[SIZE];
PII dp[SIZE][3],far[SIZE];
void dfs1(int x,int lt){
    bool get=0;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        get=1;
        dfs1(y,x);
        if(dp[y][0].F+e[x][i].S>dp[x][0].F){
            dp[x][2]=dp[x][1];
            dp[x][1]=dp[x][0];
            dp[x][0]=MP(dp[y][0].F+e[x][i].S,dp[y][0].S);
        }
        else if(dp[y][0].F+e[x][i].S>dp[x][1].F){
            dp[x][2]=dp[x][1];
            dp[x][1]=MP(dp[y][0].F+e[x][i].S,dp[y][0].S);
        }
        else if(dp[y][0].F+e[x][i].S>dp[x][2].F){
            dp[x][2]=MP(dp[y][0].F+e[x][i].S,dp[y][0].S);
        }
    }
    if(!get){
        dp[x][0]=MP(0,x);
    }
}
int ma_ans;
VI ans;
void dfs2(int x,int lt,PII v){
    PII AA[4];
    REP(i,3)AA[i]=dp[x][i];
    AA[3]=v;
    sort(AA,AA+4,greater<PII>());
    if(AA[0].F+AA[1].F+AA[2].F>ma_ans){
        ma_ans=AA[0].F+AA[1].F+AA[2].F;
        ans={AA[0].S,AA[1].S,AA[2].S};
    }
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(dp[y][0].S==dp[x][0].S){
            PII tmp=max(v,dp[x][1]);
            tmp.F+=e[x][i].S;
            dfs2(y,x,tmp);
        }
        else{
            PII tmp=max(v,dp[x][0]);
            tmp.F+=e[x][i].S;
            dfs2(y,x,tmp);
        }
    }
}
void add_edge(int x,int y,int v){
    e[x].PB(MP(y,v));
    e[y].PB(MP(x,v));
}
int u[SIZE];
int main(){
    int n;
    R(n);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        add_edge(x,y,1);
    }
    dfs1(1,1);
    dfs2(1,1,MP(0,0));
    W(ma_ans);
    sort(ALL(ans));
    REP(i,SZ(ans)){
        u[ans[i]]=1;
    }
    REP(i,SZ(ans)){
        if(ans[i]==0){
            int now=1;
            while(u[now])now++;
            ans[i]=now;
            u[now]=1;
        }
    }
    W(ans);
    return 0;
}