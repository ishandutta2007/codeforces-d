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

	template<class c, int=0> typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
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
typedef long double ld;

const LL MOD = 998244353;
LL dp[2002][2002];
int minv[2002][2002];
int num[1000006];
int n;
VI pos[502];
int m;

LL DP(int a, int b) {
	if (b < 1 || a > m || a > b) return 1;
	LL& ret = dp[a][b];
	if (ret != -1) return ret;
	int c_val = minv[a][b];
	int c_beg = pos[c_val][0];
	int c_end = pos[c_val].back();

	if (c_beg < a || b < c_end) return ret = 0;
	if (b - a + 1 == pos[num[a]].size()) return 1;

	LL H = 1;
	for (int i = 1; i < pos[c_val].size(); i++) {
		H *= DP(pos[c_val][i - 1] + 1, pos[c_val][i] - 1);
		H %= MOD;
	}

	LL A = 0;
	for (int i = a; i <= c_beg; i++) {
		A += DP(a, i - 1) * DP(i, c_beg - 1);
		A %= MOD;
	}
	LL B = 0;
	for (int j = c_end; j <= b; j++) {
		B += DP(c_end + 1, j) * DP(j + 1, b);
		B %= MOD;
	}
	ret = A * B;
	ret %= MOD;
	ret *= H;
	ret %= MOD;
	return ret;
}

int check() {
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int lo = pos[j][0], hi = pos[j].back();
			for (int x : pos[i]) {
				if (lo <= x && x <= hi) {
					return 1;
				}
			}
		}
	}
	return 0;
}

void solve(int ks) {
	MEM(dp, -1);
	scanf("%d %d", &n, &m);
	VI num2;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &num[i]);
		if (i == 1 || (SZ(num2) && num2.back() != num[i])) {
			num2.push_back(num[i]);
		}
	}
	for (int i = 0; i < SZ(num2); i++) {
		num[i + 1] = num2[i];
	}
	m = SZ(num2);
	for (int i = 1; i <= m; i++) {
		pos[num[i]].push_back(i);
	}
	if (check()) {
		printf("0\n");
		return;
	}
	for (int i = 1; i <= m; i++) {
		minv[i][i] = num[i];
		for (int j = i + 1; j <= m; j++) {
			minv[i][j] = MIN(minv[i][j - 1], num[j]);
		}
	}
	LL ans = DP(1, m);
	printf("%lld\n", ans);
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
		//AIN(T, 1, 25);
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