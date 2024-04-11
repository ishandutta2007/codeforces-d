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
#include<iomanip>
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
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
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
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int n,m;
int x[SIZE],p[SIZE];
LL dp_l[SIZE],dp_r[SIZE];
void solve() {
    vector<VL>AA;
    REP(i,n){
        AA.PB({x[i]-p[i],1,p[i]-x[i]});
        AA.PB({x[i],-2,2*x[i]});
        AA.PB({x[i]+p[i],1,-x[i]-p[i]});
    }
    sort(ALL(AA));
    PLL now{0,0};
    VPLL gg{{0,0}};
    for(int i=0,j;i<SZ(AA);i=j){
        for(j=i;j<SZ(AA)&&AA[j][0]==AA[i][0];j++){
            now.F+=AA[j][1];
            now.S+=AA[j][2];
        }
        if(AA[i][0]*now.F+now.S>m){
            gg.PB(MP(AA[i][0],AA[i][0]*now.F+now.S-m));
        }
    }
    if(SZ(gg)==1){
        W(string(n,'1'));
        return;
    }
    dp_l[0]=-1e18;
    REPP(i,1,SZ(gg)){
        dp_l[i]=max(dp_l[i-1],gg[i].S-gg[i].F);
    }
    dp_r[SZ(gg)]=-1e18;
    for(int i=SZ(gg)-1;i>0;i--){
        dp_r[i]=max(dp_r[i+1],gg[i].S+gg[i].F);
    }
    string an;
    REP(i,n){
        int pos=lower_bound(gg.begin()+1,gg.end(),MP((LL)x[i],0LL))-gg.begin();
        if(pos==SZ(gg)){
            if(p[i]-x[i]>=dp_l[pos-1]){
                an+='1';
            }else{
                an+='0';
            }
        }else if(gg[pos].F==x[i]){
            if(p[i]-x[i]>=dp_l[pos]&&p[i]+x[i]>=dp_r[pos]){
                an+='1';
            }else{
                an+='0';
            }
        }else{
            if(p[i]-x[i]>=dp_l[pos-1]&&p[i]+x[i]>=dp_r[pos]){
                an+='1';
            }else{
                an+='0';
            }
        }
    }
    W(an);
}
void input() {
    R(n,m);
    REP(i,n)R(x[i],p[i]);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    CASET {
        input();
        solve();
    }
    return 0;
}