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
LL dp[2][10];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    int n; R(n);
    MS1(dp);
    dp[0][0]=0;
    int now=0,nxt=1;
    while(n--){
        int k; R(k);
        memcpy(dp[nxt],dp[now],sizeof(dp[now]));
        VL AA[4];
        REP(j,k){
            int x,y; R(x,y);
            AA[x].PB(y);
        }
        FOR(j,1,3)sort(ALL(AA[j]),greater<LL>());
        REP(i,10){
            if(dp[now][i]==-1)continue;
            FOR(j,1,3){
                if(SZ(AA[j])>0)maa(dp[nxt][(i+1)%10],dp[now][i]+(AA[j][0]*(1+((i+1)==10))));
            }
            if(SZ(AA[1])>=3){
                maa(dp[nxt][(i+3)%10],dp[now][i]+AA[1][0]*(1+((i+3)>=10))+AA[1][1]+AA[1][2]);
            }
            if(SZ(AA[1])>=2){
                maa(dp[nxt][(i+2)%10],dp[now][i]+AA[1][0]*(1+((i+2)>=10))+AA[1][1]);
            }
            if(SZ(AA[1])>=1&&SZ(AA[2])>=1){
                maa(dp[nxt][(i+2)%10],dp[now][i]+max(AA[1][0],AA[2][0])*((i+2)>=10)+AA[1][0]+AA[2][0]);
            }
        }
        swap(now,nxt);
    }
    LL an=0;
    REP(i,10)an=max(an,dp[now][i]);
    W(an);
    return 0;
}