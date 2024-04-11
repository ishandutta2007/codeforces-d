#pragma ("fastmath")
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
#include <valarray>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int N = 2e5 + 5;
const int maxlog = 18;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
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
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll calc( ll i,  ll n)
{
    ll j = i;
    ll t = 0;
    while (j <= n)
    {
        t += n / j;
        j *= i;
    }
    return t;
}
ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
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
    return poww(a , MOD - 2);
}
int n , k, m = 0;
ll dp[N * 10];
ll ans = 0;
set<int> p;
pair<int, int> a[N * 10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    p.insert(n);
    p.insert(-1);
    for (int i = 1; i <= n; i++)
    {
        if ((i - 1) % (k - 1) == 0)
        {
            m++;
        }
        dp[i] = dp[i - 1] + m;
    }
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        a[i] = mp(u , i);
    }
    sort(a , a + n);
    reverse(a, a + n);
    for (auto e : a)
    {
        auto it = p.lower_bound(e.second);
        ll val = 0;
        sum(val , dp[(*it) - (*prev(it)) - 1]);
        sum(val , -1);
        sum(val , -dp[e.second - (*prev(it)) - 1]);
        sum(val , -dp[(*it) - e.second - 1]);
        val = mult(val, e.first);
        sum(ans , val);
        p.insert(e.second);
    }
    cout << ans << "\n";
    return 0;
}