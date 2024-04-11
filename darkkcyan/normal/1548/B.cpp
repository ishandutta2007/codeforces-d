#include <bits/stdc++.h>
using namespace std;

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


int l2(int x) {
    return 31 - __builtin_clz(x);
}

struct SparseTable {
    vector<vector<ll>> data;
    SparseTable(const vector<ll>& a) : data(l2(sz(a)) + 1) {
        data[0] = a;
        rep(lv, 1, sz(data)) {
            data[lv].resize(sz(a));
            int f = 1 << (lv - 1);
            rep(i, 0, sz(a) - (1 << lv) + 1) {
                data[lv][i] = gcd(data[lv - 1][i], data[lv - 1][f++]);
            }
            clog << db(lv) << db(data[lv]) << endl;
        }
    }
    
    ll get(int l, int r) {
        ++r;
        r = min(r, sz(data[0]));
        if (r == l) return LLONG_MAX;
        int lv = l2(r - l);
        return gcd(data[lv][l], data[lv][r - (1 << lv)]);
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        int n; cin >> n;
        vector<ll> a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        
        vector<ll> b(n - 1);
        rep(i, 1, n) b[i - 1] = abs(a[i] - a[i - 1]);
        clog <<db(b) << endl;
        SparseTable st(b);
        int r = 0;
        int ans = 0;
        rep(l, 0, n - 1) {
            while (r < n - 1 and st.get(l, r) > 1) {
                ++r;
            }
            ans = max(ans, r - l);
        }
        ++ans;
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker