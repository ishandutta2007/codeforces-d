#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

vector<tuple<int, int, int>> proc(const string& s) {
    int x = 0;
    int mi = 0, ma = 0;
    vector<tuple<int, int, int>> ans = {{0, 0, 0}};
    for (auto ch: s) {
        if (ch == '+') ++x;
        else --x;
        mi = min(mi, x);
        ma = max(ma, x);
        ans.emplace_back(x, mi, ma);
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB("test");
        int n, q; cin >> n >> q;
        string s; cin >> s;
        
        auto ford = proc(s);
        reverse(s.begin(), s.end());
        for (auto& ch: s) ch ^= '+' ^ '-';
        auto back = proc(s);
        while (q--) {
            int l, r; cin >> l >> r;
            DB(db(l)<<db(r));
            --l;
            r = n - r;
            clog<<db(l)<<db(r) << endl;
            auto [fx, fmi, fma] = ford[l];
            auto [bx, bmi, bma] = back[r];
            int end = fx - bx;
            clog << db(end) << endl;
            int mi = min(fmi, end + bmi);
            int ma = max(fma, end + bma);
            clog << db(fx)<<db(fmi)<<db(fma) << endl;
            clog << db(bx)<<db(bmi)<<db(bma) << endl;
            clog << db(mi)<<db(ma) << endl;
            cout << ma - mi + 1 << '\n';
        }
    }
    
    return 0;
}

// vim: foldmethod=marker