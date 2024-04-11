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

int IT_MAX = 1 << 17;
const int MOD = 10007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

ldb in[15][15];
int main() {
	int N, T, i, j;
	scanf("%d %d", &N, &T);

	in[1][1] = T;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			if (in[i][j] >= 1) {
				in[i + 1][j] += (in[i][j] - 1) / 2;
				in[i + 1][j + 1] += (in[i][j] - 1) / 2;
				in[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for (i = 1; i <= N; i++) for (j = 1; j <= i; j++) if (in[i][j] >= 1 - ERR) ans++;
	return !printf("%d\n", ans);
}