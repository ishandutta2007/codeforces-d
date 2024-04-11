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

#define MAXN 1000000
const LL MOD = 1000000007;
//const LL MOD = 998244353;

int n, m;
char board[3000][3000];
int rStone[3000][3000], dStone[3000][3000];
LL dpRight[3000][3000], dpDown[3000][3000];

void solve(int ks) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", board[i] + 1);
	}

	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			dStone[i][j] = rStone[i][j] = board[i][j] == 'R';
			dStone[i][j] += dStone[i + 1][j];
			rStone[i][j] += rStone[i][j + 1];
		}
	}

	if (board[n][m] == '.') {
		dpDown[n][m] = 1;
		dpRight[n][m] = 1;
	}
	LL ans = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			int down = dStone[i + 1][j];
			int right = rStone[i][j + 1];
			int k;

			k = n - i - down;
			if (k) {
				dpDown[i][j] = (dpRight[i + 1][j] - dpRight[i + k + 1][j] + MOD) % MOD;
			}
			k = m - j - right;
			if (k) {
				dpRight[i][j] = (dpDown[i][j + 1] - dpDown[i][j + k + 1] + MOD) % MOD;
			}

			if (i == 1 && j == 1) {
				ans = (dpRight[1][1] + dpDown[1][1]) % MOD;
			}
			dpRight[i][j] += dpRight[i + 1][j];
			dpRight[i][j] %= MOD;
			dpDown[i][j] += dpDown[i][j + 1];
			dpDown[i][j] %= MOD;
		}
	}

	if (n == 1 && m == 1) ans = 1;
	printf("%I64d\n", ans);
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