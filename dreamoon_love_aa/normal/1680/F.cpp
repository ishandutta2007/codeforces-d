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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
// CSES 2133 Dynamic Connectivity (https://cses.fi/problemset/task/2133/)
#define UnionFindSIZE SIZE
pair<int*, int> rollback[UnionFindSIZE * 30];
int d[UnionFindSIZE], num[UnionFindSIZE];
int n,m;
int u[SIZE], v[SIZE], dif[SIZE];
struct Union_Find {
    int gn;
    int rn;
    void save(int &v) {
        rollback[rn++] = MP(&v, v);
    }
    void back_to(int pos) {
        while(rn > pos) {
            rn--;
            *rollback[rn].first = rollback[rn].second;
        }
    }
    void init(int n){
        rn = 0;
        gn = n;
        for(int i = 0; i < n; i++) {
            d[i] = i;
            num[i] = 1;
        }
    }
    bool is_root(int x) { return d[x] == x; }
    bool uu(int x,int y, int v = 1) {
        while(x != d[x]) {
            v ^= dif[x];
            x = d[x]; 
        }
        while(y != d[y]) {
            v ^= dif[y];
            y = d[y];
        }
        if(x == y) { 
            if(v) return 0;
            return 1;
        }
        if(num[x] > num[y]) { swap(x,y); }
        save(gn);
        gn--;
        save(num[y]);
        num[y] += num[x];
        save(d[x]);
        d[x] = y;
        dif[x] = v;
        return 1;
    }
}U;
struct SegmentTree{
    bool dfs(int L, int R) {
        if(L==R){
            if(U.uu(u[L], v[L], 0)) {
                W("YES");
                string an(n,'0');
                int me=u[L];
                int exp=0;
                while(me!=d[me]){
                    exp^=dif[me];
                    me=d[me];
                }
                REP(i,n){
                    int x=i;
                    int v=0;
                    while(x!=d[x]){
                        v^=dif[x];
                        x=d[x];
                    }
                    if(v==exp){
                        an[i]='1';
                    }
                }
                W(an);
                return 1;
            }else if(U.uu(u[L], v[L])) {
                W("YES");
                string an(n,'0');
                int me=u[L];
                int exp=0;
                while(me!=d[me]){
                    exp^=dif[me];
                    me=d[me];
                }
                REP(i,n){
                    int x=i;
                    int v=0;
                    while(x!=d[x]){
                        v^=dif[x];
                        x=d[x];
                    }
                    if(v==exp){
                        an[i]='1';
                    }
                }
                W(an);
                return 1;
            }
            return 0;
        }
        int t = U.rn;
        int mm = (L + R) / 2;
        bool err=0;
        FOR(i,mm+1,R){
            if(!U.uu(u[i],v[i])){
                err=1;
                break;
            }
        }
        if(!err){
            if(dfs(L, mm))return 1;
        }
        U.back_to(t);
        err=0;
        FOR(i,L,mm){
            if(!U.uu(u[i],v[i])){
                err=1;
                break;
            }
        }
        if(!err){
            if(dfs(mm + 1, R))return 1;
        }
        U.back_to(t);
        return 0;
    }
} seg;
void solve() {
    U.init(n);
    if(!seg.dfs(0,m-1)){
        W("NO");
    }
}
void input() {
    R(n,m);
    REP(i,m){
        R(u[i],v[i]);
        u[i]--;
        v[i]--;
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}