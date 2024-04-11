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
int MOD = 998244353;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
const int MAX_BIT_NUM = 20;
/*  n  a 
 * 
 * 1.  x  v
 * 2.  x 
 * 3.  x  y 
 * 4.  a_i  i  k ()
 * 
 */
struct BIT{
    int _n;
    int bit_num;
    vector<long long> _d;
    //  n  BIT 4  2^x x  2^x > n 
    void init(int __n) {
        _n=__n;
        bit_num = __lg(_n) + 1;
        _d.resize(1 << bit_num);
        memset(_d.data() + 1, 0, sizeof(long long) * (1 << bit_num));
    }
    //  n  BIT
    BIT(int __n) {
        init(__n);
    }
    //  x  v
    void ins(int x, long long v) {
        for(;!(x >> bit_num); x += x & -x) { _d[x] += v; }
    }
    //  x 
    long long qq(int x) {
        if(x <= 0) {
            return 0;
        }
        long long res = 0;
        for(; x; x -= x & -x) { res += _d[x]; }
        return res;
    }
    //  x  y 
    long long qq_range(int x, int y) {
        if(x > y) {
            return 0;
        }
        long long ret = qq(y);
        if(x)ret -= qq(x-1);
        return ret;
    }
    //  k 
    long long k_th(int k){
        int now = 0;
        for(int i = bit_num - 1; i >= 0; i--) {
            if(_d[now + (1 << i)] < k) {
                k -= _d[now + (1 << i)];
                now += 1 << i;
            }
        }
        return now + 1;
    }
}bit(200000);
const int COMBINATION_SIZE = 1<<21;
long long mypow(long long x, long long y, long long mod = MOD){
    long long res=1;
    while(y){
        if(y&1) {
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
struct Combination {
    long long fac[COMBINATION_SIZE], inv[COMBINATION_SIZE];
    bool built = 0;
    void build(){
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
        if(!built) {
            built = 1;
            build();
        }
        return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
    }
} comb;
/*
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", comb.C(a, b));
    }
    return 0;
}
*/
int n,m;
int x[SIZE],y[SIZE];
int pos[SIZE];
void solve() {
    int cnt=0;
    for(int i=m;i>0;i--){
        pos[i]=bit.k_th(y[i]);
        if(bit.qq(pos[i]+1)>y[i])cnt++;
        bit.ins(pos[i],-1);
    }
    W(comb.C(2*n-1-cnt,n));
    FOR(i,1,m){
        bit.ins(pos[i],1);
    }
}
void input() {
    R(n,m);
    FOR(i,1,m)R(x[i],y[i]);
}
int main(){
    FOR(i,1,200000)bit.ins(i,1);
    CASET {
        input();
        solve();
    }
    return 0;
}