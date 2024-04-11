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
int a[SIZE],b[SIZE],d[SIZE];
VI pos[SIZE];
void solve() {
    int n,x,y;
    R(n,x,y);
    FOR(i,1,n){
        R(b[i]);
        d[i]=b[i];
    }
    sort(d+1,d+n+1);
    VI u(n+2);
    FOR(i,1,n)u[b[i]]=1;
    int v=0;
    FOR(i,1,n+1){
        if(!u[i]){
            v=i;
            break;
        }
    }
    if(x==y){
        FOR(i,1,n){
            if(i<=x)a[i]=b[i];
            else a[i]=v;
        }
    } else if(y==x+1) {
        if(y==n){
            W("NO");
            return;
        }
        if(count(b+1,b+n+1,b[1])==n){
            W("NO");
            return;
        }
        int sp=-1;
        FOR(i,2,n){
            if(b[i] != b[1]) {
                sp=i;
                break;
            }
        }
        FOR(i,1,n){
            if(i==sp)a[i]=b[1];
            else if(i==1)a[i]=v;
            else{
                if(x>0){
                    a[i]=b[i];
                    x--;
                } else{
                    a[i]=v;
                }
            }
        }
    } else if(d[1]==d[n]){
        if(x==y){
            FOR(i,1,n){
                if(i<=x)a[i]=b[i];
                else a[i]=v;
            }
        }
        else {
            W("NO");
            return;
        }
    } else {
        int two=1;
        FOR(i,1,n){
            if(d[i]!=d[1]&&d[i]!=d[n]){
                two=0;
            }
        }
        if(two){
            int cc[2]={};
            FOR(i,1,n){
                if(d[i]==d[1])cc[0]++;
                else cc[1]++;
            }
            if(min(cc[0],cc[1])*2<y-x){
                W("NO");
                return;
            }
            if((y-x)%2&&y==n){
                W("NO");
                return;
            }
            FOR(i,1,n)a[i]=0;
            int least=(y-x+1)/2;
            int gg[2]={};
            int odd=(y-x)%2;
            FOR(i,1,n){
                if(b[i]==d[1]){
                    if(gg[0]<least){
                        gg[0]++;
                        a[i]=d[n];
                    }
                }else{
                    if(gg[1]<least){
                        gg[1]++;
                        if(odd&&gg[1]==least){
                            a[i]=v;
                        }
                        else a[i]=d[1];
                    }
                }
                if(!a[i]){
                    if(x>0){
                        a[i]=b[i];
                        x--;
                    }
                    else{
                        a[i]=v;
                    }
                }
            }
        } else{
            FOR(i,1,n+1)pos[i].clear();
            FOR(i,1,n)pos[b[i]].PB(i);
            int need=y-x;
            int half=(y-x)/2;
            VI AA;
            FOR(i,1,n+1){
                REP(j,min(SZ(pos[i]),half)){
                    AA.PB(pos[i][j]);
                    if(SZ(AA)==need)break;
                }
                if(SZ(AA)==need)break;
            }
            if(SZ(AA)<need) {
                W("NO");
                return;
            }
            FOR(i,1,n)a[i]=0;
            REP(i,SZ(AA)){
                a[AA[i]]=b[AA[(i+half)%SZ(AA)]];
            }
            FOR(i,1,n){
                if(a[i])continue;
                if(x>0){
                    a[i]=b[i];
                    x--;
                }
                else a[i]=v;
            }
        }
    }
    W("YES");
    W(VI(a+1,a+n+1));
}
int main(){
#define MULTITEST 1
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}