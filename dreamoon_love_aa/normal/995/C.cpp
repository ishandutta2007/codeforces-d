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
const int SIZE = 1e6+10;
const int MASK = (1<<30)-1;
#include<time.h>
int myrand(){
    return (((LL)rand()<<16)^(LL)rand())&MASK;
}
const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    LL x,y;
    Point(LL x=0,LL y=0):x(x),y(y){}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b)const{return Point(x+b.x,y+b.y);}
    Point operator*(const LL v)const{return Point(x*v,y*v);}
    LL operator*(const Point& b)const{return x*b.y-y*b.x;}
    LL operator^(const Point& b)const{return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
    double angle()const{return atan2(y,x);}
    double dis2()const{return x*x+y*y;}
    void scan(){R(x,y);}
    void print(){W(x,y);}
}p[SIZE][2];
int d[SIZE];
void my_shuffle(int n){
    REPP(i,1,n){
        int id=myrand()%(i+1);
        if(i!=id)swap(d[i],d[id]);
    }
}
int res[SIZE];
int get(int v){
    if(v==0)return 1;
    return -1;
}
int main(){
    srand(time(NULL));
    int n; R(n);
    REP(i,n)d[i]=i;
    Point O(0,0);
    REP(i,n){
        p[i][0].scan();
        p[i][1]=O-p[i][0];
    }
    while(1){
        my_shuffle(n);
        Point me{0,0};
        int AA[2]={0,1};
        REP(i,n){
            if(rand()&1)swap(AA[0],AA[1]);
            Point nxt;
            bool suc=0;
            LL v[2];
            REP(j,2){
                nxt=me+p[d[i]][AA[j]];
                v[j]=nxt.dis2();
                if(v[j]<=2250000000000LL){
                    res[d[i]]=get(AA[j]);
                    suc=1;
                    break;
                }
            }
            if(!suc){
                if(v[0]<v[1]){
                    res[d[i]]=get(AA[0]);
                    nxt=me+p[d[i]][AA[0]];
                }
                else{
                    res[d[i]]=get(AA[1]);
                    nxt=me+p[d[i]][AA[1]];
                }
            }
            me=nxt;
        }
        if(me.dis2()<=2250000000000LL){
            W(VI(res,res+n));
            return 0;
        }
    }
    return 0;
}