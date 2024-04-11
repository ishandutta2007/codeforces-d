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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 1000007
void add (int *a, int n, int x) { // val[n] += x
   for (; n < N; n |= n+1) a[n] += x;
}
int sum (int *a, int n) { // val[0] + val[1] + ... + val[n]
   int s = 0;
   while (n >= 0) {
      s += a[n];
      n = (n&(n+1))-1;
   }
   return s;
}
int sumbetween (int *a, int le, int ri) { return sum(a,ri) - sum(a,le-1); } // ok dla le=0

// returns min p st sum[0,p] > s (or N if no such p exists)
int lowerBound (int *a, int s) {
   int pos = -1;
   for (int bs = 1 << (31 - __builtin_clz(N)); bs != 0; bs /= 2) {
      int next = pos + bs;
      if (next < N && s >= a[next]) {
         s -= a[next];
         pos = next;
      }
   }
   return pos + 1;
}

int fen[N];
int el[N];
int a[N];

int main () {
   wez2(q,m)
   FORI(i,m) scanf("%d", a+i);
   int nxt = 0;
   while (q--) {
      wez(x)
      if (x == -1) {
         FORI(i,m) {
            int pos = lowerBound(fen, a[i] - i);
            if (pos == N) break;
            add(fen, pos, -1);
         }
      } else {
         el[nxt] = x;
         add(fen,nxt,1);
         ++nxt;
      }
   }
   string res;
   FOR(i,nxt) if (sumbetween(fen,i,i) == 1) res += '0' + el[i];
   if (res.empty()) printf("Poor stack!");
   else printf("%s", res.c_str());
}