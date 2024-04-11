#pragma GCC optimize("Ofast,no-stack-protector")
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
#define PB emplace_back
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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch)) ch = gc();
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
    }
} using io::read;
/* case 1: begin with 2 of more P. PPPPPPPPCCCCCCCCC 
 * case 2: begin with 1 P. (P)CCCCCCCCPCPCPCPCPPPPPPP(C)
 * case 3: begin with C. CCCCCCPCPCPCPCPPPPPPPC
 */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<LL,int>,null_type,less<pair<LL,int>>,rb_tree_tag,tree_order_statistics_node_update> set_t;
LL an;
LL get(LL dp[], int l, int r){
    if(l>r)return 0;
    return dp[r] - dp[l-1];
}
void solve(int a[], LL dp[], int n, LL P_add){
    set_t AA[2];
    AA[1].insert(MP(0,0));
    LL now=0;
    LL record[2]={};
    REPP(i,1,n){
        if(i&1){
            now+=a[i];
            an+=AA[i&1].order_of_key(MP(get(dp,i+1,n)-now+P_add,-1));
            record[i&1]+=a[i];
            AA[1^(i&1)].insert(MP(record[i&1]*2,i));
        }else{
            now-=a[i];
            an+=AA[i&1].order_of_key(MP(get(dp,i+1,n)+now+P_add,-1));
            record[i&1]+=a[i];
            AA[1^(i&1)].insert(MP(record[i&1]*2,i));
        }
    }
}
LL dp[SIZE];
int a[SIZE];
int n;
void solve() {
    if(n==1){
        W(1);
        return;
    }
    an=0;
    FOR(i,1,n){
        dp[i]=dp[i-1]+a[i];
    }
    FOR(i,1,n){
        if(get(dp,1,i)>get(dp,i+1,n)){
            an++;
        }
    }
    solve(a,dp,n,0);
    solve(a+1,dp+1,n-1,a[1]);
    solve(a+1,dp+1,n-2,a[1]-a[n]);
    solve(a,dp,n-1,-a[n]);
    W(an%MOD);
}
void input() {
    read(n);
    FOR(i,1,n)read(a[i]);
}
int main(){
    int T;
    read(T);
    while(T--){
        input();
        solve();
    }
    return 0;
}