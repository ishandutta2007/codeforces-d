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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 2e5+1;
int dp[2][SIZE];
void update(int &x,int v){
    if(x==-1||x>v)x=v;
}
void no_change(int len){
    for(int i=SIZE-1;i>=len;i--)dp[1][i]=dp[1][i-len];
    memset(dp[1],-1,sizeof(int)*len);
}
int tmp[2][SIZE];
int stk[SIZE];
void change(int len){
    memcpy(tmp[0],dp[0],sizeof(dp[0]));
    for(int i=SIZE-1;i>=len;i--)tmp[1][i]=dp[1][i-len];
    memset(tmp[1],-1,sizeof(int)*len);
    REP(i,2){
        int sn=0,ll=0;
        REP(j,SIZE){
            if(dp[i][j]!=-1){
                while(sn>ll&&dp[i][stk[sn-1]]>=dp[i][j])sn--;
                stk[sn++]=j;
            }
            if(ll<sn&&stk[ll]+len<j)ll++;
            if(ll<sn){
                update(tmp[i][j],dp[i][stk[ll]]+2);
                update(tmp[i^1][j],dp[i][stk[ll]]+1);
            }
        }
    }
    memcpy(dp,tmp,sizeof(tmp));
}
int main(){
    MS1(dp);
    dp[0][0]=0;
    int N,K;
    R(N,K);
    int lt=0;
    REP(i,K){
        int l,r; R(l,r);
        if(l!=lt)no_change(l-lt);
        change(r-l);
        lt=r;
    }
    if(lt!=2*N)no_change(2*N-lt);
    if(dp[0][N]!=-1 || dp[1][N]!=-1){
        W("Full");
        int mi=dp[0][N];
        if(dp[1][N]!=-1){
            if(mi==-1||mi>dp[1][N])
                mi=dp[1][N];
        }
        W(mi);
    }
    else W("Hungry");
    return 0;
}