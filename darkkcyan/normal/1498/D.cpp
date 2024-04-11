#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define be(a) (a).begin(), (a).end()
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

const int maxn = 202;
const int maxm = 101010;
const int inf = maxm * 2;
const ll dem = (ll)1e5;
int n, m;

int ans[maxm];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fill(ans, ans + m + 1, inf);
    ans[0] = 0;
    
    vector<int> cur_vals = {0};
    rep1(i, n) {
        DB();
        int t, y; ll x; cin >> t >> x >> y;
        auto next = [&](int cur) -> ll { 
            if (t == 1) return (dem * cur + x + dem - 1) / dem;
            else return (1ll * cur * x + dem - 1) / dem;
        };
        
        clog << db(cur_vals) << endl;
        vector<int> next_vals;
        vector<int> dist(m + 1, inf);
        queue<int> qu;
        for (auto u: cur_vals) {
            qu.push(u);
            dist[u] = 0;
        }
        
        for (; qu.size(); qu.pop()) {
            int u = qu.front();
            next_vals.push_back(u);
            ans[u] = min(ans[u], i);
            if (dist[u] == y) continue;
            auto v = next(u);
            if (v < 0 or v > m) continue;
            if (dist[v] != inf) continue;
            dist[v] = dist[u] + 1;
            qu.push((int)v);
        }
        cur_vals = next_vals;
    }
    
    rep1(i, m) {
        if (ans[i] == inf) cout << -1 << ' ';
        else cout << ans[i] << ' ';
    }
    
    return 0;
}

// vim: foldmethod=marker