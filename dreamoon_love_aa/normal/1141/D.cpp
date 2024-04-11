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
char s[SIZE];
VPII an;
int main(){
    int n;
    map<char,VI>a,b;
    R(n);
    RS(s);
    REP(i,n){
        a[s[i]].PB(i+1);
    }
    RS(s);
    REP(i,n){
        b[s[i]].PB(i+1);
    }
    VI ra,rb;
    FOR(c,'a','z'){
        auto &aa=a[c];
        auto &bb=b[c];
        int mi=min(SZ(aa),SZ(bb));
        REP(i,mi)an.PB(MP(aa[i],bb[i]));
        REPP(i,mi,SZ(aa))ra.PB(aa[i]);
        REPP(i,mi,SZ(bb))rb.PB(bb[i]);
    }
    VI rb2,ra2;
    {
        auto qq=b['?'];
        int mi=min(SZ(ra),SZ(qq));
        REP(i,mi)an.PB(ra[i],qq[i]);
        REPP(i,mi,SZ(qq))rb2.PB(qq[i]);
    }
    {
        auto qq=a['?'];
        int mi=min(SZ(rb),SZ(qq));
        REP(i,mi)an.PB(qq[i],rb[i]);
        REPP(i,mi,SZ(qq))ra2.PB(qq[i]);
    }
    REP(i,min(SZ(ra2),SZ(rb2))){
        an.PB(MP(ra2[i],rb2[i]));
    }
    W(SZ(an));
    for(auto x:an)W(x);
    return 0;
}