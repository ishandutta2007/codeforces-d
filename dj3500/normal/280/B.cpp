#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int LOGN = 17, N = 1<<LOGN; // mozna zmniejszyc N
int rm[LOGN][N]; // rm[k][i] = max(tab[i], ..., tab[i + 2^k - 1])
void init (int *tab, int n) { // tab[0..n-1]
   FOR(i,n) rm[0][i] = tab[i];
   REP(k,1,LOGN-1) REP(i,0,n-(1<<k)) rm[k][i] = max(rm[k-1][i], rm[k-1][i+(1<<(k-1))]);
}
int query (int a, int b) { // a <= b bo inaczej segfault
   int k = 31 - __builtin_clz(b-a+1);
   return max(rm[k][a], rm[k][b-(1<<k)+1]);
}


int a[N];

int main () {
   wez(n)
   FORI(i,n) scanf("%d", a+i);
   a[0] = a[n+1] = INF;
   int res = 0;
   init(a,n+2);
   FORI(i,n) {
      // szukamy min x in [i+1,n+1] tze max a[i+1..x] > a[i]
      {
         int best = n+1, from = i+1, to = n;
         while (from <= to) {
            int m = (from + to) / 2;
            if (query(i+1,m) > a[i]) {
               best = m;
               to = m-1;
            } else {
               from = m+1;
            }
         }
         
         if (best < n+1) {
            REMAX(res, a[best] ^ a[i]);
         }
      }
      {
         // szukamy max x in [0,i-1] tze max a[x..i-1] > a[i]
         int best = 0, from = 1, to = i-1;
         while (from <= to) {
            int m = (from + to) / 2;
            if (query(m,i-1) > a[i]) {
               best = m;
               from = m+1;
            } else {
               to = m-1;
            }
         }
         
         if (best > 0) {
            REMAX(res, a[best] ^ a[i]);
         }
      }
   }
   pisz(res);
}