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
VPII d[SIZE];
int ll[SIZE],rr[SIZE];
int an[SIZE];
struct BIT{
    int _n;
    LL _d[SIZE];
    void init(int __n){
        _n=__n;
        FOR(i,1,_n)_d[i]=_n+1;
    }
    void ins(int x,LL v){
        for(;x<=_n;x+=x&-x)_d[x]=min(_d[x],v);
    }
    LL qq(int x){
        LL res=_n+1;
        for(;x;x-=x&-x)res=min(res,_d[x]);
        return res;
    }
}bit;
int id[SIZE];
int main(){
    int n;
    R(n);
    REP(i,n){
        int l,r;
        R(l,r);
        ll[i]=l;
        rr[i]=r;
        d[l].PB(MP(r,i));
    }
    priority_queue<PII,VPII,greater<PII>>pq;
    FOR(i,1,n){
        for(auto x:d[i]){
            pq.push(x);
        }
        if(!pq.empty()&&pq.top().F>=i){
            an[pq.top().S]=i;
            id[i]=pq.top().S;
            pq.pop();
        }
    }
    bit.init(n);
    for(int i=n;i>0;i--){
        if(bit.qq(rr[id[i]])<=i){
            FOR(j,i+1,n){
                if(ll[id[j]]<=i){
                    W("NO");
                    W(VI(an,an+n));
                    swap(an[id[i]],an[id[j]]);
                    W(VI(an,an+n));
                    return 0;
                }
            }
        }
        bit.ins(i,ll[id[i]]);
    }
    W("YES");
    W(VI(an,an+n));
    return 0;
}