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
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
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

const int mod = 1000000007;
ll same[100007], notsame[100007];

int minimalPeriod (const string &s) {
   REP(per,1,SZ(s)) {
      bool ok = 1;
      FOR(i,SZ(s)) {
         if (s[i] != s[(i+per) % SZ(s)]) {
            ok = 0;
            break;
         }
      }
      if (ok) return per;
   }
}

int offset (const string &s, const string &t) {
   FOR(per,SZ(s)) {
      bool ok = 1;
      FOR(i,SZ(s)) {
         if (s[i] != t[(i+per) % SZ(t)]) {
            ok = 0;
            break;
         }
      }
      if (ok) return per;
   }
   return -1;
}

int main () {
   string start, end;
   cin >> start >> end;
   int n = SZ(start);
   int k;
   cin >> k;
   int x = minimalPeriod(start);
   if (minimalPeriod(end) != x) {
      pisz(0);
      return 0;
   }
   
   int of = offset(start, end);
   if (of == -1) {
      pisz(0);
      return 0;
   }
   
   ll g = n/x;
   
   notsame[0] = 0;
   same[0] = 1;
   REP(i,1,k) {
      same[i] = (g-1) * same[i-1] + g * (x-1) * notsame[i-1];
      notsame[i] = g * same[i-1] + (g*x - g - 1) * notsame[i-1];
      same[i] %= mod;
      notsame[i] %= mod;
   }
   pisz((of % x == 0) ? same[k] : notsame[k]);
}