//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <random>
#include <chrono>
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
#include <complex>
#include<iomanip>
using namespace std;

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

typedef long long int LL;
//typedef __int128 LLL;
typedef long long LLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PLL> VPL;
typedef vector<PII> VP;
typedef vector<double> VD;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef long double ld;
typedef unsigned long long ULL;

//#define MAXN 1000
//#define MAXN2 MAXN*MAXN
#define MAXN 100

//const LL MOD[2] = { 87420317, 1000000007 };
//const LL MOD = 1000000007;
const LL MOD = 998244353;
//const LL MOD = 547892069;
//const LL INF = 2000000000000000001LL; //2e18 + 1
int K[103], H[103];

void solve(int ks) {
	int n;
	scanf("%d", &n);
	FORN(i, n) {
		scanf("%d", &K[i]);
	}
	FORN(i, n) {
		scanf("%d", &H[i]);
	}
	VP V;
	V.push_back({ K[0] - H[0] + 1, K[0] });
	FORAB(i, 1, n - 1) {
		while (!V.empty() && V.back().first > K[i] - H[i] + 1) V.pop_back();
		V.push_back({ K[i] - H[i] + 1, K[i]});
	}
	auto SUM = [](LL a, LL b) -> LL {
		return (a + b) * (b - a + 1) / 2;
	};
	LL ans = 0;
	LL before = 0;
	LL last = 0;
	for (auto p : V) {
		if (p.first <= before) {
			ans += SUM(last + 1, last + p.second - before);
			last += p.second - before;
			before = p.second;
		}
		else {
			before = p.second;
			last = p.second - p.first + 1;
			ans += SUM(1, last);
		}
	}
	printf("%lld\n", ans);
}

void gen() {
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\Contests\\F\\sample.in", "r", stdin);
	//freopen("C:\\Home\\Contests\\F\\0.out", "w", stdout);
#endif

	gen();

	if (1) {
		int T;
		scanf("%d", &T);
		//AIN(T, 1, 10);
		for (int ks = 1; ks <= T; ks++) {
			solve(ks);
			//if (ks % 1 == 0) fprintf(stderr, "%d done\n", ks);
		}
	}
	else {
		solve(1);
	}

	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
	return 0;
}