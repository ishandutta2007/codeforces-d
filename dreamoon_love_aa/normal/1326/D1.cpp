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
char a[SIZE];
int odd[SIZE],even[SIZE];
void parallel(int n) {
    //odd
    int rr = 0, mm = 0;
    for(int i=0;i<n;i++) {
        if(i>=rr || odd[2*mm-i]+i>=rr) {
            for(odd[i]=rr-i;i+odd[i]<n && i >= odd[i] && a[i-odd[i]] == a[i+odd[i]];odd[i]++);
            rr = i+odd[i];
            mm = i;
        } 
        else{
            odd[i] = odd[2*mm-i];
        }
    }
    //even
    rr = 1, mm = 0;
    for(int i=1;i<n;i++) {
        if(i>=rr || even[2*mm-i]+i>=rr) {
            for(even[i]=max(0,rr-i);i+even[i]<n&&i-even[i]-1>=0&&a[i+even[i]]==a[i-1-even[i]];even[i]++);
            rr = i+even[i];
            mm = i;
        } else{
            even[i] = even[2*mm-i];
        }
    }
}
bool update(int &x,int v){
    if(x<v){
        x=v;
        return 1;
    }
    return 0;
}
void solve(){
    RS(a);
    int n=LEN(a);
    parallel(n);
    int k=0;
    while(a[k]==a[n-1-k]&&k<n-1-k)k++;
    if(k>=n-1-k){
        W(a);
        return;
    }
    int an=0;
    PII ans;
    REPP(i,k,n-k){
        if(i-odd[i]<=k-1&&k*2+(i-k)*2+1<=n){
            if(update(an,k*2+(i-k)*2+1)){
                ans=MP(an-k,k);
            }
        }
        if(i+odd[i]>=n-k&&k*2+(n-k-i-1)*2+1<=n){
            if(update(an,k*2+(n-k-i-1)*2+1)){
                ans=MP(k,an-k);
            }
        }
    }
    REPP(i,k+1,n-k){
        if(i-even[i]<=k){
            int v=k*2+(i-k)*2;
            if(v<=n){
                if(update(an,v)){
                    ans=MP(an-k,k);
                }
            }
        }
        if(i+even[i]>=n-k){
            int v=k*2+(n-k-i)*2;
            if(v<=n){
                if(update(an,v)){
                    ans=MP(k,an-k);
                }
            }
        }
    }
    W(string(a,a+ans.F)+string(a+n-ans.S,a+n));
}
int main(){
    CASET{solve();}
    return 0;
}