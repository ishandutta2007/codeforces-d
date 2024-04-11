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


const int MOD = 1000000007;

ll powe (ll x, ll p) {
	if (p == 0) return 1;
	ll w = powe((x*x)%MOD, p/2);
	if (p & 1) w = (w*x)%MOD;
	return w;
}

ll modinv (ll i) {
   return powe(i,MOD-2);
}

ll a[2005], x[2005], r[2005];

int main () {
	wez2(n,k)
	FOR(i,n) { wez(x) a[i] = x; }
	if (k == 0) {
		FOR(i,n) printf("%d ", (int)a[i]);
	} else {
		x[0] = 1;
		REP(i,0,n-1) x[i+1] = (((x[i] * (k+i)) % MOD) * modinv(i+1)) % MOD;
		//DBG(vector<ll>(x,x+n))
		FOR(i,n) r[i] = 0;
		FOR(i,n) {
			REP(j,i,n-1) r[j] += (x[j-i] * a[i]) % MOD;
		}
		FOR(i,n) {
			r[i] %= MOD;
			if (r[i] < 0) r[i] += MOD;
			printf("%d ", (int)r[i]);
		}
	}
}