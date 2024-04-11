#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

bool vis[1002];

int main () {
   wez(n);
   FOR(i,n) vis[n] = true;
   int l = 1, p = 0;
   vis[0] = true;
   do {
      p = (p+l)%n;
      vis[p] = true;
      l = (l+1)%n;
   } while (p != 0 || l != 0);
   FOR(i,n) if (!vis[i]) {
      printf("NO\n");
      return 0;
   }
   printf("YES\n");
}