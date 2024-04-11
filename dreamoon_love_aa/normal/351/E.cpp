#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
#define F first
#define S second
using namespace std;
#define SIZE 2222
#define MAX 100000000
int a[SIZE],final[SIZE];
struct data{
    int x,pos;
    data(int _x=0,int _pos=0):x(_x),pos(_pos){}
    bool operator<(const data& b)const{
        return x<b.x||(x==b.x&&pos<b.pos);
    }
}w[SIZE];
int main(){
    DRI(n);
    REPP(i,1,n+1){
        final[i]=MAX;
        RI(a[i]);
        a[i]=abs(a[i]);
        w[i]=data(a[i],i);
    }
    sort(w+1,w+n+1);
    int an=0;
    REPP(i,1,n+1){
        int cnt1=0,cnt2=0;
        REPP(j,1,n+1){
            if(w[i].pos==j)continue;
            if(final[j]==MAX)continue;
            if(j<w[i].pos){
                if(final[j]>w[i].x)cnt1++;
                if(final[j]>-w[i].x)cnt2++;
            }
            else{
                if(final[j]<w[i].x)cnt1++;
                if(final[j]<-w[i].x)cnt2++;
            }
        }
        an+=min(cnt1,cnt2);
        if(cnt2<=cnt1)final[w[i].pos]=-w[i].x;
        else final[w[i].pos]=w[i].x;
    }
    printf("%d\n",an);
    return 0;
}