#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

// Returns a random integer from the range [l, r].
LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; // Deterministic on the local machine.
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    // #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////



bool make_question(int n, vector<int> vec) {
    cout << "? " << vec.size() << " ";
    for (int x: vec) cout << x << " ";
    cout << endl;
    string ans;
    cin >> ans;
    return ans == "YES";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n;
    cin >> n;

    vector<int> good;
    vector<int> bad;
    for (int i = 1; i <= n; i++) good.push_back(i);
    while (1) {
        int gs = good.size();
        int bs = bad.size();
        if (gs + bs <= 2) break;
        vector<int> vec;

        int gs2 = gs/2;
        int bs2 = bs/2;
        if (gs % 2) gs2++;

        if (gs == 2 and bs == 1) gs2 = 0, bs2 = 1;
        
        for (int i = 0; i < gs2; i++) vec.push_back(good[i]);
        for (int i = 0; i < bs2; i++) vec.push_back(bad[i]);
        bool ans = make_question(n, vec);
        vector<int> good2;
        vector<int> bad2;
        if (ans) {
            for (int i = 0; i < gs2; i++) good2.push_back(good[i]);
            for (int i = gs2; i < gs; i++) bad2.push_back(good[i]);
            for (int i = 0; i < bs2; i++) good2.push_back(bad[i]); 
        } else {
            for (int i = 0; i < gs2; i++) bad2.push_back(good[i]);
            for (int i = gs2; i < gs; i++) good2.push_back(good[i]);
            for (int i = bs2; i < bs; i++) good2.push_back(bad[i]);
        }
        good = good2;
        bad = bad2;
        // dbg(good, bad);
    }
    
    for (int x: bad) good.push_back(x);
    assert(good.size() <= 2);
    for (int x: good) {
        cout << "! " << x << endl;
        string ans;
        cin >> ans;
        if (ans == ":)") {
            return 0;
        }
    }
}