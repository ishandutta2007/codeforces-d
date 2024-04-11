/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int n,r,mi_err;
VPII res;
PII d[SIZE];
int dn=0;
void calc(int x,int y){
    if(__gcd(x,y)!=1)return;
    dn=0;
    int tt=0;
    while(x!=0&&y!=0){
        if(x<y){
            if(x==1){
                d[dn++]=MP(1,y-1);
                d[dn++]=MP(0,1);
            }
            else{
                d[dn++]=MP(1,y/x);
            }
            y%=x;
        }
        else{
            if(y==1){
                d[dn++]=MP(0,x-1);
                d[dn++]=MP(1,1);
            }
            else{
                d[dn++]=MP(0,x/y);
            }
            x%=y;
        }
    }
    int err=0;
    REP(i,dn){
        tt+=d[i].S;
        err+=d[i].S-1;
    }
    if(tt==n&&err<mi_err){
        mi_err=err;
        res=VPII(d,d+dn);
    }
}
int main(){
    mi_err=1e9;
    R(n,r);
    if(r==1&&n==1){
        W(0);
        W("T");
        return 0;
    }
    FOR(i,1,r-1){
        calc(i,r);
    }
    if(SZ(res)==0)W("IMPOSSIBLE");
    else{
        W(mi_err);
        for(int i=SZ(res)-1;i>=0;i--){
            cout<<string(res[i].S,(res[i].F==res.back().F)?'T':'B');
        }
        W("");
    }
    return 0;
}