#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
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
const double PI = acos(-1);
const int N = 2e5 + 7;
ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MAXN = 26;
const int maxlog = 18;
const int maxn = 1 << maxlog;
ld eps = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
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
    ll res = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (res < 0) {
        res += MOD;
    }
    if (res >= MOD) {
        res -= MOD;
    }
    return res;
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
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = mult(a, res);
        a = mult(a, a);
        b >>= 1;
    }
    return res % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}
int dp[N * 10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    for(int i = 0; i < 10 * N; i++)
    {
        dp[i] = INF;
    }
    for(int i = 0; i < 5; i++)
    {
        dp[i + 1] = 1;
    }
    for(int i = 1; i <= 1e6; i++)
    {
        for(int j = 1; j < 6; j++)
        {
            dp[i + j] = min(dp[i + j] , dp[i] + 1);
        }
    }
    int x;
    cin >> x;
    cout << dp[x] << "\n";
    return 0;
}