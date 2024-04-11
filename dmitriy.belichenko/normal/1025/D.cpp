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
int x[N];
int parent[N];
void make_set (int v)
{
    parent[v] = v;
}
int find_set (int v)
{
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a , int b)
{
    parent[find_set(a)] = find_set(b);
}
int dp[1000][1000][2];
int g[1000][1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for(int i = 0; i < n + 2; i++)
    {
        dp[i][i][0] = 1;
    }
    for(int i = 0; i < n + 2; i++)
    {
        dp[i][i][1] = dp[i][i][0];
    }
    for(int i = 0; i < n + 2; i++)
    {
        for(int j = 0; j < n + 2; j++)
        {
            g[i][j] = (gcd(x[i] , x[j]) != 1);
            
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i + 1; j++)
        {
            for(int k = j; k < i + j ; k++)
            {
                int flag = 1;
                if(!g[j - 1][k]) flag = 0;
                if(!dp[k + 1][i + j][0]) flag = 0;
                if(!dp[j][k][1]) flag = 0;
                dp[j][i + j][0] = max(flag , dp[j][i + j][0]);
                flag = 1;
                if(!dp[k + 1][i + j][0]) flag = 0;
                if(!dp[j][k][1]) flag = 0;
                if(!g[i + j][k]) flag = 0;
                dp[j][i + j][1] = max(flag , dp[j][i + j][1]);
            }
        }
    }
    bool flag = max(dp[1][n + 1][0] , dp[1][n + 1][1]);
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}