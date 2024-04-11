//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include <array>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
	~debug() { cerr << endl; }
	template<class c> typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
		cerr << boolalpha << i; return *this;
	}

	template<class c, int = 0> typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
		return *this << range(begin(i), end(i));
	}

	sim, class b dor(pair < b, c > d) {
		ris << "(" << d.first << ", " << d.second << ")";
	}
	sim dor(rge<c> d) {
		*this << "[";
		for (auto it = d.b; it != d.e; ++it)
			*this << ", " + 2 * (it == d.b) << *it;
		ris << "]";
	}
#else
	sim dor(const c&) { ris; }
#endif
};
#define watch(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LLL;
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PLL > VPL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef long double ld;

#define MAXN 100005
const LL MOD = 1000000007;
//const LL MOD = 998244353;

int u[100005];
int n, m;
set<int> V[100005];
int isBig[100005];

int Parent(int a) {
	if (u[a] == a) return a;
	return u[a] = Parent(u[a]);
}

void Join(int a, int b) {
	a = Parent(a);
	b = Parent(b);
	if (a != b) u[a] = b;
}

void solve(int ks) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) u[i] = i;

	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		V[u].insert(v);
		V[v].insert(u);
	}

	int cand = 1;
	for (int i = 1; i <= n; i++) if (SZ(V[cand]) > SZ(V[i])) cand = i;

	for (int i = 1; i <= n; i++) isBig[i] = 1;
	for (int i : V[cand]) isBig[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (isBig[i]) {
			Join(cand, i);
		}
	}

	VI Rest;
	for (int i = 1; i <= n; i++) {
		if (Parent(i) != Parent(cand)) {
			Rest.push_back(i);
		}
	}

	int big = n - SZ(V[cand]);
	for (int i : Rest) {
		for (int j : Rest) {
			if (i != j) {
				if (V[i].find(j) == V[i].end()) {
					Join(i, j);
				}
			}
		}
	}

	for (int i : Rest) {
		int cnt = 0;
		for (int j : V[i]) {
			cnt += isBig[j];
		}
		if (cnt != big) {
			Join(cand, i);
		}
	}

	int total = 0;
	for (int i = 1; i <= n; i++) {
		if (Parent(i) == i) total++;
	}

	printf("%d\n", total - 1);
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (0) {
		int T;
		scanf("%d", &T);
		AIN(T, 1, 5);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}