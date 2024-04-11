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
struct Union_Find{
    int d[SIZE],num[SIZE];
    LL sum[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,sum[i]=0;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        sum[y]+=sum[x];
        return 1;
    }
}U;
int a[SIZE],p[SIZE];
bool u[SIZE];
LL ma,an[SIZE];
int main(){
    DRI(n);
    U.init(n+1);
    REPP(i,1,n+1)RI(a[i]);
    REP(i,n)RI(p[i]);
    for(int i=n-1;i>0;i--){
        int x=p[i];
        u[x]=1;
        U.sum[x]=a[x];
        if(u[x-1])U.uu(x-1,x);
        if(u[x+1])U.uu(x+1,x);
        if(ma<U.sum[U.find(x)]){
            ma=U.sum[U.find(x)];
        }
        an[i-1]=ma;
    }
    REP(i,n)printf("%I64d\n",an[i]);
    return 0;
}