#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL BIT[SIZE];
void ins(int x,LL v){
    for(;x<SIZE;x+=x&-x)BIT[x]=max(BIT[x],v);
}
LL qq(int x){
    LL res=-1e18;
    for(;x;x-=x&-x)res=max(res,BIT[x]);
    return res;
}
int dp[SIZE];
int main(){
    VI d;
    DRI(n);
    REP(i,n){DRI(x);d.PB(x);}d.PB(0);
    reverse(ALL(d));
    REP(i,SIZE)BIT[i]=-1e18;
    REPP(i,1,n+1)dp[i]=d[i]+dp[i-1];
    LL an=0;
    ins(1,dp[n]);
    an=dp[n];
    REPP(i,2,n){
        int now=dp[n]-dp[i-1];
        LL me=now-qq(i-1);
        an=max(an,me);
        if(i==n)return 0*printf("%I64d\n",me);
        ins(i,me);
    }
    cout<<an<<endl;
    return 0;
}