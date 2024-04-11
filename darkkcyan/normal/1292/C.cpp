// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

/*{{{*/
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int debug = 1;
#define DB(...) stringstream CONCAT(ss, __LINE__); CONCAT(ss, __LINE__) << __VA_ARGS__; debug_block CONCAT(dbbl, __LINE__)(CONCAT(ss, __LINE__).str())
#else
int debug = 0;
#define DB(...)
#endif
int __db_level = 0;
#define clog if (debug) cerr << string(__db_level * 2, ' ')
struct debug_block {
    string name;
    debug_block(const string& name_): name(name_) { clog << "{ " << name << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << name << endl; }
};
#define deb(...) "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]"
#define debln(...)  clog << "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]" << endl
#define _ << ", " <<
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first _ p.second << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t) _ get<1>(t) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t) _ get<1>(t) _ get<2>(t) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out _ container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }
/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

#define maxn 3030

int n;
vector<int> gr[maxn];

int parent[maxn][maxn];
int dist[maxn][maxn];
int cnt_child[maxn][maxn];

void pre_dfs(int u, int p, int root) {
    parent[u][root] = p;
    dist[u][root] = dist[p][root] + 1;
    cnt_child[u][root] = 1;
    for (auto v: gr[u]) {
        if (v == p)  continue;
        pre_dfs(v, u, root);
        cnt_child[u][root] += cnt_child[v][root];
    }
}

llong dp[maxn][maxn];

llong cal_dp(int u, int v) {
    llong& ans = dp[u][v];
    if (ans != -1) return ans;
    ans = 0;
    for (auto nxt:gr[u]) {
        if (parent[u][v] == nxt) continue;
        ans = max(ans, cal_dp(nxt, v));
    }

    for (auto nxt: gr[v]) {
        if (parent[v][u] == nxt) continue;
        ans = max(ans, cal_dp(u, nxt));
    }

    ans += 1ll * cnt_child[u][v] * cnt_child[v][u];
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    rep1(i, n) {
        dist[i][i] = -1;
        cnt_child[i][i] = 0;
        pre_dfs(i, i, i);
    }

    memset(dp, -1, sizeof(dp));

    llong ans = 0;
    rep1(u, n) {
        for (auto v: gr[u]) ans = max(ans, cal_dp(u, v));
    }
    cout << ans;

    return 0;
}