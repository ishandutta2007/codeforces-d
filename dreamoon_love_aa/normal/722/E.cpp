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
#define x first
#define y second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL fac[SIZE],inv[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void build(){
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
LL dp[2016][21];
PII p[2016];
void ADD(LL&x,LL v){
    x=(x+v)%MOD;
    if(x<0)x+=MOD;
}
int main(){
    build();
    DRII(n,m);
    DRII(K,S);
    REPP(i,1,K+1)RII(p[i].x,p[i].y);
    sort(p+1,p+K+1);
    K++;
    p[K]=MP(n,m);
    p[0]=MP(1,1);
    dp[0][0]=1;
    REPP(i,1,K+1){
        REP(j,21){
            ADD(dp[i][j],C(p[i].x+p[i].y-2,p[i].x-1));
            REP(k,i)ADD(dp[i][j],-dp[k][j]*C(p[i].x+p[i].y-p[k].x-p[k].y,p[i].x-p[k].x));
        }
        for(int j=20;j>0;j--)ADD(dp[i][j],-dp[i][j-1]);
    }
    LL an=0,sum=0;
    REPP(i,1,21){
        ADD(an,S*dp[K][i]);
        ADD(sum,dp[K][i]);
        S=(S+1)/2;
    }
    ADD(an,C(n+m-2,n-1)-sum);
    printf("%I64d\n",an*mypow(C(n+m-2,n-1),MOD-2)%MOD);
    return 0;
}