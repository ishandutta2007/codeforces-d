#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

const int maxn = 1010101;
int dp[maxn][2][2];

int mark[maxn], timer = 0;

bool valid(int len, bool head, bool tail) {
    if (len == 0) return head == tail;
    return true;
}

int cal_dp(int len, bool head, bool tail) {
    if (len == 0) return 0;
    int& ans = dp[len][head][tail];
    if (ans != -1) return ans;
#define cal_if_valid(l, h, t, fallback) (valid(l, h, t) ? cal_dp(l, h, t) : fallback)
    
    rep(pos, 0, len) {
        cal_if_valid(pos, head, 0, 0);
        cal_if_valid(pos, head, 1, 0);
        cal_if_valid(len - 1 - pos, 0, tail, 0);
        cal_if_valid(len - 1 - pos, 1, tail, 0);
    }
    
    ++timer;
    rep(pos, 0, len) {
        rep(cur, 0, 2) {
            if (!valid(pos, head, cur) or !valid(len - 1 - pos, cur, tail)) continue;
            mark[cal_dp(pos, head, cur) ^ cal_dp(len - 1 - pos, cur, tail)] = timer;
        }
    }
    
    ans = 0;
    while (mark[ans] == timer) ++ans;
    return ans;
}

void brute(int n) {
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n + 1) {
        DB();
        clog << db(i) << endl;
        rep(head, 0, 2) rep(tail, 0, 2) 
            clog << db(head) << db(tail) << db(cal_dp(i, head, tail)) << endl;
    }
}

template<int mod>
struct mod_int {
    int x;
    mod_int(int a = 0): x(a) {}
    mod_int(ll a): x((int)(a % mod)) {}
    
#define op(p) friend mod_int operator p(mod_int u, mod_int v)
    op(+) {
        u.x += v.x;
        if (u.x >= mod) u.x -= mod;
        return u;
    }
    
    op(-) {
        u.x -= v.x;
        if (u.x < 0) u.x += mod;
        return u;
    }
    
    op(*) {
        return 1ll * u.x * v.x;
    }
    
    mod_int pow(ll exp) const {
        mod_int base = *this, ans = 1;
        for (; exp > 0; exp >>= 1, base = base* base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
    
    op(/) {
        return u * v.pow(mod - 2);
    }
};

using mint = mod_int<(int)1e9 + 7>;

mint fac[maxn], ifac[maxn];

void precal() {
    fac[0] = 1;
    rep(i, 1, maxn) fac[i] = fac[i - 1] * i;
    ifac[maxn - 1] = 1 / fac[maxn - 1];
    for (int i = maxn - 1; i--; ) 
        ifac[i] = ifac[i + 1] * (i + 1);
}

mint choose(int n, int k) {
    if (n < k or n < 0 or k < 0) return 0;
    return fac[n] * ifac[n - k] * ifac[k];
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // brute(100); 
    
    int n; cin >> n;
    --n;
    mint ans = 0;
    for (int cnt_pick = n; cnt_pick > 0; --cnt_pick) {
        int cnt_group = n - cnt_pick + 1;
        if (cnt_group <= 0) continue;
        if ((n - cnt_group) & 1) continue;
        int cnt_positive = max(cnt_group - 2, 0);
        auto cnt_config = choose(cnt_pick + cnt_group - cnt_positive - 1, cnt_group - 1);
        auto cnt_way = cnt_config * fac[cnt_pick];
        clog << db(cnt_pick) << db(cnt_group) << db(cnt_positive) << db(cnt_config.x) << db(cnt_way.x) << endl;
        ans = ans + cnt_way;
    }
    ans = ans * 2 * (n + 1);
    cout << ans.x;
    
    return 0;
}

// vim: foldmethod=marker