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

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    
    int n ;cin >> n;
    string pref = "";
    vector<string> ans;
    while (n--) {
        DB();
        clog << db(n) << endl;
        string s; cin >> s;
        clog << db(s) << endl;
        clog << db(pref) << endl;
        clog << db(ans) << endl;
        if (sz(s) < sz(pref)) {
            cout << "NO";
            return 0;
        }
        
        if (sz(s) > sz(pref)) {
            rep(i, 0, sz(s)) {
                if (s[i] != '?') continue;
                if (i == 0) s[i] = '1';
                else s[i] = '0';
            }
        } else {
            vector<int> ques_pos;
            rep(i, 0, sz(s)) {
                if (s[i] == '?') ques_pos.push_back(i);
            }
            
            clog << db(ques_pos) << endl;
            ll l = 0, r = 1;
            rep(i, 0, sz(ques_pos)) r *= 10;
            --r;
            ll mx = r;
            
            auto do_insert = [&](ll num) {
                auto sm = to_string(num);
                while (sz(sm) < sz(ques_pos)) sm = '0' + sm;
                auto x = s;
                rep(i, 0, sz(ques_pos)) {
                    x[ques_pos[i]] = sm[i];
                }
                return x;
            };
            
            while (l < r) {
                ll mid = (l + r) / 2;
                if (do_insert(mid) > pref) r = mid;
                else l = mid + 1;
            }
            clog << db(l) << db(r) << db(mx) << endl;
            s = do_insert(l);
            clog << db(s) << db(pref) << endl;
            if (s <= pref) {
                cout << "NO";
                return 0;
            }
        }
        
        ans.push_back(s);
        pref = s;
    }
    cout << "YES\n";
    for (auto i: ans) cout << i << '\n';
    
    return 0;
}

// vim: foldmethod=marker