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
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

using ans_type = llong; 
constexpr bool print_case = false;

void print_ans(const ans_type& ans) {
    cout << ans << '\n';
}

ans_type solve() {
    int n;
    llong required, l1, r1, l2, r2; cin >> n >> required >> l1 >> r1 >> l2 >> r2;
    
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    
    llong useless = 0;
    llong usefull = 0;
    if (r1 >= r2) {
        usefull = r1 - r2 + l2 - l1;
        required -= n * (r2 - l2);
    } else if (r1 > l2) {
        usefull = l2 - l1 + r2 - r1;
        required -= (r1 - l2) * n;
    } else {
        useless = l2 - r1;
        usefull = r2 - l1;
    }
    if (required <= 0) return 0;
    
    deb(usefull, useless);
    
    llong ans = LLONG_MAX;
    rep1(i, n) {
        llong cur_ans = useless * i;
        if (usefull * i > required) cur_ans += required;
        else {
            cur_ans += usefull * i;
            llong rest = required - usefull * i;
            cur_ans += rest * 2;
        }
        deb(i, cur_ans);
        ans = min(ans, cur_ans);
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        DB(""; deb(testcase));
        if (print_case) cout << "Case #" << testcase << ": ";
        print_ans(solve());
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker