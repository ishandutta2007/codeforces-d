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
#define FN 500010
#define FM 2000010
#define INF 1000000000000000LL
struct E {
    int k;
    LL c;
    E(){}
    E( int _k, LL _c ):k(_k),c(_c){}
} es[FM];

struct Flow {
    int n,m,dis[FN];
    int qq[FN],qr,ql;
    int ptr[FN];
    vector<int> e[FN];
    void init( int _n ) {
        n=_n; m=0;
        for ( int i=0; i<n; i++ ) {
            vector<int>tmp;
            e[i].swap(tmp);
        }
    }
    void add_edge( int a, int b, LL c ) {
        e[a].push_back(m); es[m]=E(b,c); m++;
        e[b].push_back(m); es[m]=E(a,0); m++;
    }
    bool BFS() {
        memset(dis,-1,n*sizeof(int));
        ql=qr=0;
        qq[qr++]=0;
        dis[0]=0;
        while ( ql!=qr && dis[n-1]==-1 ) {
            int p=qq[ql++];
            for(auto& it:e[p]) {
                E ee=es[it];
                if ( ee.c==0 || dis[ee.k]!=-1 ) continue;
                dis[ee.k]=dis[p]+1;
                qq[qr++]=ee.k;
            }
        }
        return dis[n-1]!=-1;
    }
    LL go( int p, LL c ) {
        if ( p==n-1 ) return c;
        LL ret=0,tmp;
        for(int &i=ptr[p];i<SZ(e[p]);i++){
            auto it=e[p][i];
            E &ee=es[it];
            if ( ee.c==0 || dis[p]+1!=dis[ee.k] ) continue;
            tmp=go(ee.k,min(c-ret,(LL)ee.c));
            ret+=tmp; ee.c-=tmp; es[it^1].c+=tmp;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    LL maxflow() {
        LL ret=0;
        while ( BFS() ) {
            memset(ptr,0,n*sizeof(int));
            ret+=go(0,1LL<<60);
        }
        return ret;
    }
} flow;
int x[51][2],y[51][2];
int a[121][121];
int main(){
    int n,m;
    R(n,m);
    if(!m){
        W(0);
        return 0;
    }
    VI xx,yy;
    REP(i,m){
        R(x[i][0],y[i][0],x[i][1],y[i][1]);
        xx.PB(x[i][0]);
        xx.PB(x[i][1]+1);
        yy.PB(y[i][0]);
        yy.PB(y[i][1]+1);
    }
    SORT_UNIQUE(xx);
    SORT_UNIQUE(yy);
    REP(k,m){
        int st_i=GET_POS(xx,x[k][0])+1,ed_i=GET_POS(xx,x[k][1]+1)+1;
        int st_j=GET_POS(yy,y[k][0])+1,ed_j=GET_POS(yy,y[k][1]+1)+1;
        REPP(i,st_i,ed_i)REPP(j,st_j,ed_j){
            a[i][j]=1;
        }
    }
    flow.init(SZ(xx)+SZ(yy));
    REPP(i,1,SZ(xx))flow.add_edge(0,i,xx[i]-xx[i-1]);
    REPP(i,1,SZ(yy))flow.add_edge(SZ(xx)+i-1,flow.n-1,yy[i]-yy[i-1]);
    REPP(i,1,SZ(xx))REPP(j,1,SZ(yy)){
        if(a[i][j])flow.add_edge(i,SZ(xx)+j-1,INF);
    }
    W(flow.maxflow());
    return 0;
}