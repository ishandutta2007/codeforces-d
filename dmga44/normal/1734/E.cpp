#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (1e9 + 7);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e6 + 5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            a[i][j] = (a[i][j - 1] + i) % n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        a[0][i] += b[0];

    for (int i = 1; i < n; i++)
    {
        int pos = 0;
        for (int j = 0; j < n; j++)
            if (a[i][j] == b[i])
                pos = j;
        pos = (pos - i + n) % n;
        rotate(a[i].begin(), a[i].begin() + pos, a[i].end());
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " \n"[j == n - 1];

    return 0;
}