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
VI AA;
#include<time.h>
int n;
int my_rand(int lb, int ub) {
    LL x=((LL)rand()<<14)^rand();
    return lb+x%(ub-lb+1);
}
int res[2049][2049];
int qq(int x,int y){
    if(!res[x][y]){
        W("?",x,y);
        fflush(stdout);
        int v;
        R(v);
        if(v==-1)exit(0);
        res[x][y]=res[y][x]=v;
        return v;
    }
    else {
        return res[x][y];
    }
}
void my_shuffle(){
    REPP(i,1,SZ(AA)){
        int x=my_rand(0,i);
        if(x!=i)swap(AA[x],AA[i]);
    }
}
int get(int id){
    my_shuffle();
    int me=2047;
    REP(i,min(15,n)){
        if(AA[i]==id)continue;
        me&=qq(id,AA[i]);
    }
    return me;
}
void solve() {
    srand(time(NULL));
    R(n);
    FOR(i,1,n)AA.PB(i);
    if(n*(n-1)/2<=4269){
        FOR(i,1,n){
            FOR(j,i+1,n){
                qq(i,j);
            }
        }
        FOR(i,1,n){
            VI gg;
            FOR(j,1,n){
                if(i==j)continue;
                gg.PB(qq(i,j));
            }
            sort(ALL(gg));
            bool err=0;
            REP(j,SZ(gg)){
                if(gg[j]!=j+1)err=1;
            }
            if(!err){
                VI an(n);
                FOR(j,1,n){
                    if(i!=j)an[j-1]=qq(i,j);
                }
                W("!",an);
                return;
            }
        }
    }
    else {
        VI an(n);
        int it=1;
        int lt=2047;
        while(1){
            if(!(lt&(lt-1)))an[it-1]=0;
            else an[it-1]=get(it);
            lt=an[it-1];
            if(!an[it-1]){
                FOR(i,1,n){
                    if(i==it)continue;
                    an[i-1]=qq(it,i);
                }
                W("!",an);
                fflush(stdout);
                return;
            }
            for(int j=it+1;j<=n;j++){
                int v=qq(it,j);
                if(an[it-1]==v){
                    it=j;
                    break;
                }
            }
        }
    }
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}