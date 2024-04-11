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

const int SIZE = 1<<20;
const int MAX_M = 400010;
int n,m;
string s[MAX_M];
VI ids[MAX_M];
int lt[MAX_M];
int a[MAX_M];
int col_cnt[MAX_M];
int target[MAX_M];
VI e[MAX_M];
void add_edge(int x, int y){
    e[x].PB(y);
}
int nxt[MAX_M];
int pre[MAX_M];
bitset<MAX_M> visited;
void dfs(int x){
    if(visited[x])return;
    visited[x]=1;
    for(int y:e[x]){
        dfs(y);
    }
}
int far[MAX_M];
void solve() {
    int need=0;
    REP(i,m){
        need+=a[i];
    }
    if(!need){
        W(0);
        return;
    }
    {
        int rr=0;
        REP(i,m){
            if(lt[i]==n){continue;}
            int st=ids[lt[i]][i];
            dfs(st);
            while(rr<m&&(!a[rr]||visited[ids[target[rr]][rr]])){rr++;}
            nxt[i]=rr;
        }
    }
    visited.reset();
    {
        int ll=m-1;
        for(int i=m-1;i>=0;i--){
            if(lt[i]==n){continue;}
            int st=ids[lt[i]][i];
            dfs(st);
            while(ll>=0&&(!a[ll]||visited[ids[target[ll]][ll]])){ll--;}
            pre[i]=ll;
        }
    }
    REP(i,m){
        far[pre[i]+1]=max(far[pre[i]+1],nxt[i]-1);
    }
    int now=0;
    int an=0;
    int ma=-1;
    REP(i,m){
        ma=max(ma,far[i]);
        if(i==now){
            an++;
            now=ma+1;
        }
    }
    W(an);
}
void input() {
    R(n,m);
    int num=0;
    REP(i,n){
        R(s[i]);
        ids[i].resize(m,-1);
        REP(j,m){
            if(s[i][j]=='#'){
                ids[i][j]=num++;
            }
        }
    }
    REP(i,m)R(a[i]);
    REP(i,m)lt[i]=n;
    for(int i=n-1;i>=0;i--){
        REP(j,m){
            if(s[i][j]=='#'){
                for(int k=j-1;k<=j+1;k+=2){
                    if(k<0||k>=m){continue;}
                    if(s[i][k]=='#'){
                        add_edge(ids[i][j],ids[i][k]);
                        continue;
                    }
                    if(lt[k]<n){
                        add_edge(ids[i][j],ids[lt[k]][k]);
                    }
                }
                if(lt[j]<n){
                    add_edge(ids[i][j],ids[lt[j]][j]);
                }
                if(i&&s[i-1][j]=='#'){
                    add_edge(ids[i][j],ids[i-1][j]);
                }
            }
        }
        REP(j,m){
            if(s[i][j]=='#'){
                lt[j]=i;
                col_cnt[j]++;
                if(col_cnt[j]==a[j]){
                    target[j]=i;
                }
            }
        }
    }
}
int main(){
    input();
    solve();
    return 0;
}