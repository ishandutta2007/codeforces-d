#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
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
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

multiset<int> vals;
multiset<int> diffs;
void add(int num) {
    auto it = vals.insert(num);
    if (it != vals.begin() and next(it) != vals.end()) {
        auto u = prev(it), v = next(it);
        diffs.erase(diffs.find(*v - *u));
    }
    
    if (it != vals.begin()) {
        diffs.insert(num - *prev(it));
    }
    if (next(it) != vals.end()) {
        diffs.insert(*next(it) - num);
    }
}

void rem(int num) {
    auto it = vals.find(num);
    
    if (it != vals.begin() and next(it) != vals.end()) {
        auto u = prev(it), v = next(it);
        diffs.insert(*v - *u);
    }
    
    if (it != vals.begin()) {
        diffs.erase(diffs.find(num - *prev(it)));
    }
    if (next(it) != vals.end()) {
        diffs.erase(diffs.find(*next(it) - num));
    }
    
    vals.erase(it);
}

llong get_ans() {
    if (len(vals) < 2) return 0;
    else {
        llong dist = *vals.rbegin() - *vals.begin();
        llong mx_skip = *--diffs.end();
        return dist - mx_skip;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    rep(i, n) {
        int num; cin >> num;
        add(num);
    }
    
    cout << get_ans() << '\n';
    
    while (q--) {
        int type, x; cin >> type >> x;
        if (type) add(x);
        else rem(x);
        cout << get_ans() << '\n';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker