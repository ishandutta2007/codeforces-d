#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <pii> Vp;
int ch(pii a, pii b) {
	if (a.first + b.first > a.second + b.second) return 1;
	else return -1;
}
char in[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	scanf("%s", in);

	int x = 0, y = 0;
	Vp.emplace_back(x, y);
	for (i = 1; i <= N; i++) {
		if (in[i-1] == 'U') y++;
		else x++;
		Vp.emplace_back(x, y);
	}
	//for (auto it : Vp) printf("(%d, %d)\n", it.first, it.second);

	int ans = 0;
	for (i = 1; i < N; i++) {
		if (ch(Vp[i - 1], Vp[i]) != ch(Vp[i], Vp[i + 1])) ans++;
	}
	return !printf("%d\n", ans);
}