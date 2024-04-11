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
#define UnionFindSIZE 1234567
struct Union_Find {
    int d[UnionFindSIZE], num[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i] = i;
            num[i] = 1;
        }
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) { y = d[y]; }
        while(x != y) {
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x) { return d[x] == x; }
    bool uu(int x,int y) {
        x = find(x);
        y = find(y);
        if(x == y) { return 0; }
        if(num[x] > num[y]) { swap(x,y); }
        num[y] += num[x];
        d[x] = y;
        return 1;
    }
}U;
int n,p;
int a[SIZE];
void solve() {
    U.init(n);
    VPII pp;
    REP(i,n){
        pp.PB(MP(a[i],i));
    }
    sort(ALL(pp));
    LL an=0;
    int need=n-1;
    REP(i,n){
        int mm=pp[i].S;
        if(a[mm]>=p)break;
        for(int j=mm+1;j<n&&U.find(j)!=U.find(j-1)&&a[j]%a[mm]==0;j++){
            an+=a[mm];
            U.uu(j,j-1);
            need--;
        }
        for(int j=mm-1;j>=0&&U.find(j)!=U.find(j+1)&&a[j]%a[mm]==0;j--){
            an+=a[mm];
            U.uu(j,j+1);
            need--;
        }
    }
    W(an+(LL)need*p);
}
void input() {
    R(n,p);
    REP(i,n){
        R(a[i]);
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}