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

const int maxn = 101010;
int n, m;
vector<int> gr[maxn];
int color[maxn];
int cnt[maxn * 2];

int bfs(int u, int comp_id) {
    queue<int> qu;
    int cnt_vis = 0;
    for (qu.push(u), color[u] = comp_id << 1; qu.size(); qu.pop()) {
        u = qu.front();
        ++cnt_vis;
        cnt[color[u]]++;
        for (auto v: gr[u]) {
            if (color[v] != -1) {
                if (color[u] == color[v]) {
                    cout << "0 1";
                    exit(0);
                }
                continue;
            }
            color[v] = color[u] ^ 1;
            qu.push(v);
        }
    }
    return cnt_vis;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    if (m == 0) {
        cout << 3 << ' ' << 1ll * n * (n - 1) * (n - 2) / 6;
        return 0;
    }
    
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    fill_n(color, n + 1, -1);
    int max_vis = 0;
    int cur_comp = 0;
    rep(i, 1, n + 1) {
        if (color[i] != -1) continue;
        max_vis = max(max_vis, bfs(i, cur_comp++));
    }
    if (max_vis == 2) {
        ll ans = 0;
        rep(i, 1, n + 1) {
            if (gr[i].size() and gr[i][0] < i) {
                ans += n - 2;
            }
        }
        cout << "2 " << ans;
        return 0;
    }
    
    
    ll ans = 0; 
    rep(i, 0, cur_comp * 2) {
        ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << "1 " << ans;
    
    return 0;
}

// vim: foldmethod=marker