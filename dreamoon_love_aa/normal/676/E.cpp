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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
LL v[SIZE];
void YY(){puts("Yes");exit(0);}
void NN(){puts("No");exit(0);}
int main(){
    DRII(n,k);
    int qq=0;
    REP(i,n+1){
        char s[12];
        RS(s);
        if(s[0]=='?')v[i]=INF,qq++;
        else v[i]=atoi(s);
    }
    if(!k){
        if(v[0]==0)YY();
        else if(v[0]!=INF)NN();
        else{
            if((n+1-qq)%2==1)YY();
            else NN();
        }
        return 0;
    }
    if(!qq){
        LL now=0;
        for(int i=n;i>=0;i--){
            now*=k;
            now+=v[i];
            if(abs(now)>=1e14){
                NN();
                return 0;
            }
        }
        if(!now)YY();
        else NN();
    }
    else{
        if((n+1)%2==0)YY();
        else NN();
    }
    return 0;
}