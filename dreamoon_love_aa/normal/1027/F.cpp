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
const int SIZE = 2e6+10;
VI AA;
struct Union_Find{
    int d[SIZE],num[SIZE],cc[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,cc[i]=0;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
    bool is_root(int x){return d[x]==x;}
    int uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return x;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        cc[y]+=cc[x];
        d[x]=y;
        return y;
    }
}U;
int a[SIZE],b[SIZE];
bool good(int n,int v){
    U.init(v+1);
    REP(i,n){
        if(a[i]>v&&b[i]>v)return 0;
        if(a[i]>v){
            int x=U.find(b[i]);
            U.cc[x]++;
            if(U.cc[x]>U.num[x])return 0;
        }
        else if(b[i]>v){
            int x=U.find(a[i]);
            U.cc[x]++;
            if(U.cc[x]>U.num[x])return 0;
        }
        else{
            int x=U.uu(a[i],b[i]);
            U.cc[x]++;
            if(U.cc[x]>U.num[x])return 0;
        }
    }
    return 1;
}
int main(){
    int n; R(n);
    REP(i,n){
        R(a[i],b[i]);
        AA.PB(a[i]);
        AA.PB(b[i]);
    }
    SORT_UNIQUE(AA);
    REP(i,n){
        a[i]=GET_POS(AA,a[i]);
        b[i]=GET_POS(AA,b[i]);
    }
    int ll=0,rr=SZ(AA);
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(good(n,mm))rr=mm;
        else ll=mm+1;
    }
    if(ll==SZ(AA))W(-1);
    else W(AA[ll]);
    return 0;
}