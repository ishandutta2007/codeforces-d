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
    int d[SIZE],num[SIZE],cnt[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,cnt[i]=0;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        cnt[y]+=cnt[x];
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
VI e[SIZE];
int main(){
    DRII(N,M);
    U.init(N);
    int lt;
    LL self=0;
    REP(i,M){
        DRII(x,y);x--;y--;
        if(x!=y){
            e[x].PB(y);
            e[y].PB(x);
        }
        else self++;
        lt=x;
        U.cnt[U.find(x)]++;
        U.uu(x,y);
    }
    REP(i,N){
        if(U.cnt[U.find(i)]&&U.find(i)!=U.find(lt))return 0*puts("0");
    }
    LL an=self*(M-self)+(self-1)*self/2;
    REP(i,N){
        LL v=SZ(e[i]);
        an+=(v-1)*v/2;
    }
    cout<<an<<endl;
    return 0;
}