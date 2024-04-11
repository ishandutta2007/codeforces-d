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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

ll in[100050];

ll u[100050];
int main() {
	int N, S, i;
	scanf("%d %d", &N, &S);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	ll st = 1, en = N, mi, rv = 0, ans = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		for (i = 1; i <= N; i++) u[i] = in[i] + (ll)mi * i;
		sort(u + 1, u + N + 1);

		ll s = 0;
		for (i = 1; i <= mi; i++) s += u[i];
		if (s <= S) {
			rv = mi;
			st = mi + 1;
			ans = s;
		}
		else en = mi - 1;
	}
	return !printf("%lld %lld\n", rv, ans);
}