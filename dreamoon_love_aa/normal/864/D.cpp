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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int cnt[SIZE],a[SIZE],use[SIZE];
int main(){
    DRI(n);
    int an=n;
    REPP(i,1,n+1){
        RI(a[i]);
        cnt[a[i]]++;
        if(cnt[a[i]]==1)an--;
    }
    printf("%d\n",an);
    set<int>not_used;
    REPP(i,1,n+1)
        if(!cnt[i])not_used.insert(i);
    REPP(i,1,n+1){
        if(use[a[i]]){
            cnt[a[i]]--;
            int x=*not_used.begin();
            a[i]=x;
            not_used.erase(x);
            use[x]=1;
        }
        else{
            if(cnt[a[i]]==1){
                use[a[i]]=1;
            }
            else{
                int x=*not_used.begin();
                if(x<a[i]){
                    cnt[a[i]]--;
                    use[x]=1;
                    cnt[x]=1;
                    not_used.erase(x);
                    a[i]=x;
                }
                else{
                    use[a[i]]=1;
                }
            }
        }
        printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}