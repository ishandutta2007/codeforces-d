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
const int SIZE = 1024;
int n,m;
char s[SIZE][SIZE];
int dp[26][SIZE][SIZE],lt[SIZE];
int get(int c,int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[c][x1][y1]+dp[c][x2][y2]-dp[c][x1][y2]-dp[c][x2][y1];
}
bool good(int x1,int x2,int y){
    if(x1<1||x2>n)return 0;
    return get(s[x1][y],x1,y,x2,y)==x2-x1+1;
}
int main(){
    R(n,m);
    FOR(i,1,n)RS(s[i]+1);
    FOR(i,1,n)FOR(j,1,m){
        s[i][j]-='a';
        dp[(int)s[i][j]][i][j]=1;
    }
    REP(k,26){
        FOR(i,1,n)FOR(j,1,m){
            dp[k][i][j]+=-dp[k][i-1][j-1]+dp[k][i][j-1]+dp[k][i-1][j];
        }
    }
    LL an=0;
    REPP(i,2,n){
        int cnt=0;
        FOR(j,1,m){
            if(s[i][j]!=s[i-1][j])lt[j]=i-1;
            int h=i-lt[j];
            if(s[i][j]!=s[i+1][j]){
                if(good(i-2*h+1,i-h,j)&&good(i+1,i+h,j)){
                    if(s[i][j]==s[i][j-1]&&s[i+1][j]==s[i+1][j-1]&&s[i-h][j]==s[i-h][j-1]&&s[i-h+1][j]==s[i-h+1][j-1])cnt++;
                    else cnt=1;
                }
                else cnt=0;
            }
            else cnt=0;
            an+=cnt;
        }
    }
    W(an);
    return 0;
}