#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// #define int long long
// #define INV_F
#define INV_E
// #define INV_S
#define PRE_RUN 10010
inline long long LL(int x) { return static_cast<long long> (x); }
namespace MOD_BASE {
const int Dollar1 = 998244353;
inline int up(int x) { return x >= Dollar1 ? x - Dollar1 : x; }
inline int down(int x) { return x < 0 ? x + Dollar1 : x ; }
inline int & add(int & x, const int y) { x += y; if (x >= Dollar1) x -= Dollar1; return x; }
inline int & dec(int & x, const int y) { x -= y; if (x < 0) x += Dollar1; return x; }
inline int mul(int x, int y) { return LL(x) * y % Dollar1; }
inline int fastpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = LL(res) * a % Dollar1;
        a = LL(a) * a % Dollar1;
        b >>= 1;
    }
    return res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int exgcd(int a, int b, int & x, int & y) {
    if (!b) { x = 1; y = 0; return a; }
    int res = exgcd(b, a % b, y, x); y -= a / b * x; return res;
}
#ifdef INV_F
inline int INV(int x) { return fastpow(x, Dollar1 - 2); }
#endif
#ifdef INV_E
inline int INV(int a) {
    int x, y;
    exgcd(a, Dollar1, x, y);
    return down(x);
}
#endif
#ifdef INV_S
int INV(int x) { return x == 1 ? 1 : LL(INV(Dollar1 % x)) * (Dollar1 - Dollar1 / x) % Dollar1; }
#endif
#ifdef PRE_RUN
int fac[PRE_RUN], inv[PRE_RUN], invfac[PRE_RUN];
inline int C(int a, int b) { if (a < 0 || b < 0 || b > a) return 0; return LL(fac[a]) * invfac[b] % Dollar1 * invfac[a - b] % Dollar1; }
inline int lucas(int a, int b) { if (a < Dollar1 && b < Dollar1) return C(a, b); return LL(lucas(a % Dollar1, b % Dollar1)) * lucas(a / Dollar1, b / Dollar1) % Dollar1; }
int RUN_INIT() {
    invfac[0] = invfac[1] = inv[0] = inv[1] = fac[0] = fac[1] = 1;
    for (int i = 2; i != PRE_RUN; ++i) {
        fac[i] = LL(fac[i - 1]) * i % Dollar1;
        inv[i] = LL(inv[Dollar1 % i]) * (Dollar1 - Dollar1 / i) % Dollar1;
    }
    for (int i = 2; i != PRE_RUN; ++i) invfac[i] = mul(invfac[i - 1], inv[i]);
    return 0;
}
int FIRSTRUN = RUN_INIT();
#endif
}
using namespace MOD_BASE;
#define MAXN 1010
int n, t, f[MAXN][MAXN];
int main() {
	scanf("%d", &n);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t);
		if (t > 0 && t <= n) add(f[i][t], f[i - 1][0]);
		for (int j = 1; j <= n; ++j) add(f[i][j - 1], f[i - 1][j]);
		for (int j = 0; j <= n; ++j) add(f[i][j], f[i - 1][j]);
	}
	printf("%d\n", f[n][0] - 1);
	return 0;
}