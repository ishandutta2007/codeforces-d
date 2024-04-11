#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 131072;
const int MOD = 100000;
const int INF = 1034567890;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-6;

ll C[1050][1050];
int main() {
	int i, j;
	C[0][0] = 1;
	for (i = 1; i <= 1000; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j <= i-1; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}

	scanf("%d", &i);

	ll ans = 0;
	ans += (i - 3) * 9 * (1ll << (2 * i - 8));
	ans += 6 * (1ll << (2 * i - 6));
	ans *= 4;
	printf("%lld\n", ans);
	return 0;
}