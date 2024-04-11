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

inline bool ispow(int x) {
    return !(x & (x - 1));
}

inline bool ok(multiset<int> &p) {
    for(auto x: p) {
        if (!ispow(x)) return false;
    }
    return true;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> moves;
        multiset<int> okpow, s;
        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }

        for (int i = 1; i < n + 1; i++) s.insert(i);
        while (s.size()) {
            multiset<int> cr;
            while (s.size()) {
                int v = *prev(s.end());
                s.erase(prev(s.end()));
                int lpow = 1;
                while (lpow < v) lpow <<= 1;
                if (lpow == v) {
                    okpow.insert(v);
                    continue;
                }
                int diff = lpow - v;
                moves.pb(mp(diff, v));
                s.erase(s.find(diff));
                cr.ins(abs(diff - v));
                okpow.insert(diff + v);
            }
            swap(s, cr);
        }

        swap(s, okpow);
        int cur = *prev(s.end());
        s.erase(cur);
        while (s.size()) {
            int fs = *s.begin();
            if (!fs) {
                auto it = s.lower_bound(1);
                if (it == s.end()) {
                    s.erase(s.begin());
                    moves.pb(mp(0, cur));
                } else {
                    moves.pb(mp(0, *it));
                    auto val = *it;
                    s.erase(it); s.erase(s.begin());
                    s.ins(val); s.ins(val);
                }
            } else {
                auto l = s.begin(), r = next(l);
                while (*l != *r) l++, r++;
                int val = *l;
                s.ins(0); s.ins(val << 1);
                moves.pb(mp(val, val));
                s.erase(l);
                s.erase(r);

            }
            s.erase(cur);
        }
        if (!ok(s)) {
            cout << "FUCKED UP\n";
            return 0;
        }
        cout << moves.size() << "\n";
        for (auto move : moves) cout << move.first << " " << move.second << "\n";

    }

}