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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
const int COMBINATION_SIZE = 1<<21;
long long mypow(long long x, long long y, long long mod = MOD){
    x %= MOD;
    long long res=1;
    while(y) {
        if(y & 1) {
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
struct Combination {
    long long fac[COMBINATION_SIZE], inv[COMBINATION_SIZE];
    void build() {
        static bool built = 0;
        if(built) { return; }
        built = 1;
        assert(MOD >= COMBINATION_SIZE);
        fac[0] = 1;
        for(int i = 1; i < COMBINATION_SIZE; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[COMBINATION_SIZE - 1] = mypow(fac[COMBINATION_SIZE - 1], MOD - 2);
        for(int i = COMBINATION_SIZE - 2; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }
    long long C(int x, int y){
        if(y < 0 || y > x) {
            return 0;
        }
        build();
        return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
    }
} comb;
//1-base
struct Difference {
    LL a[SIZE], cc[SIZE];
    int n;
    void build(LL _a[],int _n){
        comb.build();
        n = _n;
        for(int i = 1; i <= n; i++) { a[i] = _a[i]; }
        for(int i = 1; i <= n; i++) {
            cc[i] = mypow(comb.fac[i - 1] * comb.fac[n - i], MOD - 2) * a[i] % MOD;
            if((n - i) % 2 == 1) {
                cc[i] = (MOD - cc[i]) % MOD;
            }
        }
    }
    LL get(LL x) {
        x %= MOD;
        if(x <= n) { return a[x]; }
        LL an = 0;
        LL tmp = 1;
        for(int i = 1; i <= n; i++) { tmp = tmp * (x - i) % MOD; }
        for(int i = 1; i <= n; i++) {
            ADD(an,tmp * mypow(x - i, MOD - 2) % MOD * cc[i]);
        }
        return an;
    }
} D;
int n,k;
LL dp[600][201];
void solve() {
    dp[0][0] = 1;
    FOR(i,1, k * 2 + 5){
        FOR(j,0,k){
            ADD(dp[i][j], dp[i-1][j]);
            for(int r = 2; r <= i&& r - 1 <= j; r++) {
                ADD(dp[i][j], dp[i-r][j-r+1] * comb.C(i-1,r-1) %MOD*comb.fac[r-1]);
            }
        }
    }
    FOR(i,1,k * 2 + 5){
        FOR(j,2,k){
            ADD(dp[i][j],dp[i][j-2]);
        }
    }
    LL a[601];
    FOR(i,1,k){
        FOR(j,1,k * 2 + 5){
            a[j]=dp[j][i];
        }
        D.build(a,k * 2 + 5);
        W(D.get(n));
    }
}
void input() {
    R(n,k);
}
int main(){
    input();
    solve();
    return 0;
}