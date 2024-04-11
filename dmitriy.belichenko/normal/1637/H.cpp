#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
const double PI = acos(-1);
// = 5e5 + 17;
const int MOD1 = 998244353;
const int MOD = 1000000007;
const int INF = 1e9;
const int MaXN = 150;
const int N = 1e8 + 1000;
const int LOG = 25;
const int FACT = 120;

mt19937 rng(239);
typedef uint64_t ull;
uniform_int_distribution<ull> nextRand(0, (1LL << 62) - 1);
int root = 3;

template<class A, class B>
void sum(A &a, B b) {
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}

ll add(ll a, ll b) {
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;

}

int to_i(char c) {
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

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll gcd_eu(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0LL;
        y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll poww(ll a, ll b) {
    ll val = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}

ll inv(ll a) {
    return poww(a, MOD - 2);
}

int gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1 = 0, y1 = 0;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int n, logn = 0;

void upd(vector<int> &fen, int u, int x) {
    for(; u < n; u = (u | (u + 1))) fen[u] += x;
}

int get_sm(vector<int> &fen, int u) {
    int l = 0, s = 0;
    for (l = u; l >= 0; l = (l & (l + 1)) - 1) {
        s += fen[l];
    }
    return s;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        while((1 << logn) < n + 1) logn++;
        vector<int> fen(n, 0), a(n), val;
        for (auto &x : a) cin >> x;
        ll sm = 0;
        int cnt = 0;
        for (auto &x : a) {
            sm += get_sm(fen, --x) - get_sm(fen, n - 1);
            upd(fen, x, 1);
            val.pb(2 * x - cnt);
            cnt++;
        }
        cnt = 0;
        sort(all(val));
        sm *= -1;
        cout << sm << " ";
        for (auto x: val) {
            sm += x - cnt++;
            cout << sm << " ";
        }
        cout << "\n";
    }

    return 0;
}