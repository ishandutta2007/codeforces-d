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
const int SIZE = 1e6+1010;
int dp[SIZE];
int a[SIZE];
void mii(int&x,int v){
    if(x==-1||x>v)x=v;
}
int main(){
    DRII(n,k);
    REP(i,n)RI(a[i]);
    sort(a,a+n);
    int base=a[0];
    REPP(i,1,n)a[i]-=base;
    MS1(dp);
    dp[0]=0;
    int up=0;
    REP(i,1000000){
        if(dp[i]==-1)continue;
        REPP(j,1,n){
            mii(dp[i+a[j]],dp[i]+1);
        }
    }
    REP(i,1000000)
        if(dp[i]!=-1&&dp[i]<=k)printf("%d ",i+base*k);
    return 0;
}