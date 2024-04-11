#include <bits/stdc++.h>
using namespace std;

#define jalsol_orz main

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
// What? You wanted to see how this template works?  Check this out:
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

#define defop(type, op) \
    inline friend type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op##= (const type& o) 
template<int mod>
struct modint {
    int x;
    modint(int xx = 0): x(xx) {}
    modint(ll xx) : x(int(xx % mod)) {}
    
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x) ;
    }
    modint pow(ll exp) const {
        modint ans = 1, base = *this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    defop(modint, /) {
        return *this *= o.pow(mod - 2);
    }
    friend print_op(modint) {
        return out << u.x;
    }
};

using mint = modint<(int)1e9 + 7>;

const int maxn = 401010;
mint fac[maxn], ifac[maxn];
mint pw2[maxn];
void precal() {
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn - 1] = mint(1) / fac[maxn - 1];
    for (int i = maxn - 1; i--; ) {
        ifac[i] = ifac[i + 1] * (i + 1);
    }
    pw2[0] = 1;
    rep(i, 1, maxn) pw2[i] = pw2[i - 1] +pw2[i - 1];
}

mint choose(int n, int k) {
    if (k < 0 or n < k) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
}

mint solve(int n, vector<int> a) {
    vector<int> odd, even;
    for (auto i: a) {
        if (i & 1) odd.push_back(i);
        else even.push_back(i);
    }
    
    mint ans = (pw2[sz(odd)] - 1) * pw2[sz(even)];
    
    while (sz(even)) {
        a = even;
        odd.clear();
        even.clear();
        for (auto i: a) {
            i /= 2;
            if (i & 1) odd.push_back(i);
            else even.push_back(i);
        }
        
        auto odd_side = sz(odd) ? pw2[sz(odd) - 1] - 1 : 0;
        auto even_side = pw2[sz(even)];
        auto cur_ans = odd_side * even_side;
        clog << db(even) << db(odd) << db(cur_ans) << endl;
        ans += cur_ans;
    }
    return ans;
}

mint brute(int n, vector<int> a) {
    mint ans = 0;
    rep(mask, 0, (1 << n)) {
        ll sum = 0;
        int g = 0;
        for (int i = 0; i < n; ++i) {
            if (!((mask >> i) & 1)) continue;
            g = __gcd(g, a[i]);
            if (a[i] % 2 == 0) {
                sum += a[i] / 2;
            }
        }
        if (mask == 0) continue;
        if (sum % g == 0) {
            clog << bitset<10>(mask) << endl;
        }
        ans += (sum % g == 0);
    }
    return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void gen() {
    int n = rand() % 5 + 1;
    vector<int> a(n);
    rep(i, 0, n) a[i] = rand() % 32 + 1;
    auto ans = solve(n, a);
    auto exp = brute(n, a);
    if (ans.x == exp.x) {
        cout <<"OK" << endl;
        return ;
    }
    cout << "nope" << endl;
    ofstream inp("main.inp");
    inp << n << endl;
    rep(i, 0, n) inp << a[i] << ' ';
    inp << endl;
    inp << db(ans) << endl;
    inp << db(exp) << endl;
    exit(0);
}

int jalsol_orz() {
    precal();
    // while(1) gen();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    vector<int> a;
    cin >> n;
    a.resize(n);
    for (auto & i: a) cin >> i;
    cout << solve(n, a);
#ifdef LOCAL
    cout << endl << brute(n, a) << endl;
#endif
    
    return 0;
}

// vim: foldmethod=marker