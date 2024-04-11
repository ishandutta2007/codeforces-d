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
char s[555][555];
int n,m,k;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
void dfs(int x,int y){
    if(!k)return;
    s[x][y]='.';
    k--;
    REP(r,4){
        int nx=x+dx[r];
        int ny=y+dy[r];
        if(Out(nx,ny))continue;
        if(s[nx][ny]=='X'){
            dfs(nx,ny);
        }
    }
}
int main(){
    RIII(n,m,k);
    int ee=0;
    int x,y;
    REP(i,n){
        RS(s[i]);
        REP(j,m)
            if(s[i][j]=='.'){
                ee++;
                s[i][j]='X';
                x=i;
                y=j;
            }
    }
    k=ee-k;
    dfs(x,y);
    REP(i,n)puts(s[i]);
    return 0;
}