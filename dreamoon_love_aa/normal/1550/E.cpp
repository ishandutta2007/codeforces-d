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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<18;
int n,k;
char s[SIZE];
int cnt[17];
int good[SIZE][17];
int dp[1<<17];
int get_bit(int x, int v) { return (x >> v) & 1; }
inline void update(int &x, int v) {
    if(x>v){x=v;}
}
bool valid(int len){
    MS1(good);
    MS0(cnt);
    REP(i,n){
        if(s[i]!='?'){
            cnt[s[i]-'a']++;
        }
        if(i>=len-1){
            int ty=-1;
            REP(j,k){
                if(cnt[j]){
                    if(ty==-1)ty=j;
                    else{
                        ty=-2;
                        break;
                    }
                }
            }
            if(ty>=0){
                good[i][ty]=i;
            }else if(ty==-1){
                REP(j,k)good[i][j]=i;
            }
            if(s[i-len+1]!='?'){
                cnt[s[i-len+1]-'a']--;
            }
        }
    }
    REP(i,k)good[n][i]=n;
    for(int i=n-1;i>=0;i--){
        REP(j,k){
            if(good[i][j]==-1)good[i][j]=good[i+1][j];
        }
    }
    REPP(i,1,1<<k)dp[i]=n+1;
    dp[0]=len-1;
    REP(i,1<<k){
        if(dp[i]>=n){continue;}
        REP(j,k){
            if(get_bit(i,j)){continue;}
            if(good[dp[i]][j]!=n){
                update(dp[i|(1<<j)],min(n,good[dp[i]][j]+len));
            }
        }
    }
    return dp[(1<<k)-1]<=n;
}
void solve() {
    int ll=0,rr=n/k;
    while(ll<rr){
        int mm=(ll+rr+1)/2;
        if(valid(mm))ll=mm;
        else rr=mm-1;
    }
    W(ll);
}
void input() {
    R(n,k);
    RS(s);
}
int main(){
    input();
    solve();
    return 0;
}