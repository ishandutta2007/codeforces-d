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
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> inline ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.sz)s<<t[i]<<" ";return s; }
inline void pisz(int n) { printf("%d\n",n); }
#define pll pair<int,ll>
vector<pii> adj[100002];

ll d[100002];

void bfs (int n) {
      vector<bool> odwiedzony(n+1,false);
      deque<pll > kol;
      kol.pb(mp(1,0));
      while (!kol.empty()) {
         int v = kol.front().first;
         ll odl = kol.front().second;
         kol.pop_front();
         
         if (odwiedzony[v]) continue;
         odwiedzony[v] = true;
         // odwiedzamy wierzcholek
         d[v] = odl;
         
         for (vector<pii>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
            int dokad = it->first;
            ll dld = it->second;
            kol.pb(mp(dokad,dld+odl));
         }
      }
   
}


int main () {
   wez(n)
   ll suma = 0;
   FOR(i,n-1) {
      wez3(x,y,w)
      adj[x].pb(mp(y,w));
      adj[y].pb(mp(x,w));
      d[i+1] = 0;
      suma += w;
   }
   
   bfs(n);
   ll max = 0;
   FORI(i,n) {if (max < d[i]) max = d[i];}
   printf("%I64d\n",2*suma-max);
}