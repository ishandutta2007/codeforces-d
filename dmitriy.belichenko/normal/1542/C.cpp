#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
int MOD = 1'000'000'007;
const int INF = 1e5;
const int MaXN = 150;
const int N = 1e5 + 22;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
typedef uint64_t ull;
uniform_int_distribution<ull> nextRand(0, (1LL << 62) - 1);
template<class A, class B>
void sum(A &a, B b)
{
	a += b;
	if (a < 0LL) a += MOD;
	if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	return a;

}
int to_i(char c)
{
	return c - 'a';
}
ll mult(ll a, ll b) {
	ll val = a * b - (ll)((ld)a * b / MOD) * MOD;
	if (val < 0) {
		val += MOD;
	}
	if (val >= MOD) {
		val -= MOD;
	}
	return val;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll gcd_eu(ll a, ll b, ll & x, ll & y)
{
	if (a == 0)
	{
		x = 0LL; y = 1LL;
		return b;
	}
	ll x1, y1;
	ll d = gcd_eu(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
long long poww(long long a, long long b)
{
	long long val = 1;
	a %= MOD;
	while (b > 0)
	{
		if (b % 2) val = mult(a, val);
		a = mult(a, a);
		b >>= 1;
	}
	return val % MOD;
}
ll inv(ll a)
{
	return poww(a, MOD - 2);
}
int gcd(ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1 = 0, y1 = 0;
	ll d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
ll pre[500];
#define int ll
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	int p = 1;
	pre[1] = 1;
	int it = 2;
	while (p < 10000000000000001LL) {
		p = p * it / gcd(it, p);
		pre[it] = p;
		it++;
	}

	while (t--) {
		ll n;
		cin >> n;
		ll ans = n % MOD;
		for (int i = 1; i < it; i++) sum(ans, n / pre[i]);
		cout << ans % MOD << "\n";
	}

}