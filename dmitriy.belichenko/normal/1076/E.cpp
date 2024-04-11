#pragma GCC optimize("Ofast")
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
#include <queue>
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
ll MOD = 998244353;
const int INF = 1e9;
const int MaXN = 105;
const int N = 1e6 + 5;
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

ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
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
    return poww(a , MOD - 2);
}
#define int ll
vector<int> g[N];
vector<pair<int, int> > gr[N];
int s[N], a[N];
int n, m;
void add_f(int p, int x)
{
    for(int i = 0 ;p <= n; p += p & -p)
    {
        s[p] += x;
    }
}
void add_f(int L, int R, int x)
{
    add_f(L, x);
    add_f(R + 1, -x);
}
int get(int p)
{
    int res = 0;
    for(int i = 0; p; p -= p & -p)
    {
        res += s[p];
    }
    return res;
}
void dfs(int u, int d, int p)
{
    for(auto p: gr[u])
    {
        add_f(d, min(d + p.fst, n), p.snd);
    }
    a[u] = get(d);
    //cout << get(d) << "\n";
    for(int v : g[u])
    {
        if(v != p)
        {
            dfs(v, d + 1, u);
        }
    }
    for(auto p: gr[u])
    {
        add_f(d, min(d + p.fst, n), -p.snd);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int v, d, x;
        cin >> v >> d >> x;
        gr[v].pb(mp(d, x));
    }
    dfs(1, 1, 0);
    for(int i = 0; i < n; i++)
    {
        cout << a[i + 1] << " ";
    }
    return 0;
}