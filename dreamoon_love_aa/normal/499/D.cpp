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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
double dp[5001][5001];
int p[5001],t[5001];
double mypow(double x,int y){
    double res=1;
    while(y){
        if(y&1)res*=x;
        x*=x;
        y>>=1;
    }
    return res;
}
int main(){
    int n,T;
    RII(n,T);
    dp[0][0]=1;
    REP(i,n)
        RII(p[i],t[i]);
    double ans=0;
    REP(i,n){
        double pp=p[i]*0.01;
        double now=0;
        double r=mypow(1-pp,t[i]-1)*pp;
        double r2=mypow(1-pp,t[i]-1);
        REP(j,T){
            now*=(1-pp);
            now+=dp[i][j]*pp;
            if(j+1>=t[i]){
                now-=dp[i][j+1-t[i]]*r;
                dp[i+1][j+1]=now+dp[i][j+1-t[i]]*r2;
            }
            else{
                dp[i+1][j+1]=now;
            }
        }
        REP(j,T+1)ans+=dp[i+1][j];
    }
    printf("%.12f\n",ans);
    return 0;
}