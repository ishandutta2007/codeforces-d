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
const int SIZE = 112345;
int d[SIZE];
struct data{
    int ty,l,c,x;
}a[SIZE];
int main(){
    DRI(m);
    int now=1;
    REP(i,m){
        RI(a[i].ty);
        if(a[i].ty==1){
            RI(a[i].x);
            if(now<SIZE)d[now++]=a[i].x;
            a[i].l=1;a[i].c=1;
        }
        else{
            RII(a[i].l,a[i].c);
            for(int j=1;j<=a[i].c&&now<SIZE;j++)
                for(int k=1;k<=a[i].l&&now<SIZE;k++){
                    d[now++]=d[k];
                }
        }
    }
    DRI(n);
    int idx=0;
    long long pre=0;
    REP(i,n){
        if(i)putchar(' ');
        long long id;
        cin>>id;
        while(pre+a[idx].l*a[idx].c<id){
            pre+=a[idx].l*a[idx].c;
            idx++;
        }
        if(a[idx].ty==1)cout<<a[idx].x;
        else cout<<d[(id-pre-1)%a[idx].l+1];
    }
    puts("");
    return 0;
}