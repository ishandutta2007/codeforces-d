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

int main(){
    LL a1,b1,a2,b2;
    cin>>a1>>b1;
    cin>>a2>>b2;
    DRII(L,R);
    if(a1>a2){
        swap(a1,a2);
        swap(b1,b2);
    }
    REP(i,a1){
        if((b2-b1)%a1==0)break;
        b2+=a2;
        if(b2>R)return 0*puts("0");
    }
    if((b2-b1)%a1)puts("0");
    else{
        L=max(L,(int)b1);
        LL qq=a1/__gcd(a1,a2)*a2;
        if(b2<L){
            b2+=(L-b2+qq-1)/qq*qq;
        }
        LL an=0;
        if(b2<=R)an=(R-b2)/qq+1;
        cout<<an<<endl;
    }
    return 0;
}