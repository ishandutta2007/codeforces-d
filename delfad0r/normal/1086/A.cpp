#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector> 
#include <tuple>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> II;
typedef pair<int, LL> ILL;
typedef pair<LL, int> LLI;
typedef pair<LL, LL> LLLL;

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

template<typename I>
class iter_type {
    public:
    const I b, e;
    iter_type(I b, I e) : b(b), e(e) { }
};

template<typename I>
iter_type<I> iter(I b, I e) {
    return iter_type<I>(b, e);
}

template<typename T>
auto iter(T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v));
}

template<typename I>
ostream& operator << (ostream& out, const iter_type<I>& x) {
    out << "[";
    for(I it = x.b; it != x.e; ++it) {
        out << *it;
        if(next(it) != x.e) {
            out << ", ";
        }
    }
    return out << "]";
}

template<typename I>
istream& operator >> (istream& in, const iter_type<I>& x) {
    for(I it = x.b; it != x.e; ++it) {
        in >> *it;
    }
    return in;
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    return out << iter(v);
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    return in >> iter(v);
}
template<typename T>
ostream& operator << (ostream& out, const set<T>& v) {
    return out << iter(v);
}
template<typename S, typename T>
ostream& operator << (ostream& out, const map<S, T>& v) {
    return out << iter(v);
}
template<typename T>
ostream& operator << (ostream& out, const unordered_set<T>& v) {
    return out << iter(v);
}
template<typename S, typename T>
ostream& operator << (ostream& out, const unordered_map<S, T>& v) {
    return out << iter(v);
}


//////////////////////
// HAPPY CODING  :) //
//////////////////////

set<II> get_path(int x1, int y1, int x2, int y2, int dir) {
    if(dir) {
        set<II> ans;
        for(int x = x1; x != x2; x += ((x1 < x2) ? (1) : (-1))) {
            ans.emplace(x, y1);
        }
        for(int y = y1; y != y2; y += ((y1 < y2) ? (1) : (-1))) {
            ans.emplace(x2, y);
        }
        ans.emplace(x2, y2);
        return ans;
    } else {
        return get_path(x2, y2, x1, y1, 1);
    }
}

int main() {
    // remove in interactive problems
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //
    
    vector<int> X(3), Y(3);
    for(int n = 0; n < 3; ++n) {
        cin >> X[n] >> Y[n];
    }
    set<II> ans;
    for(int i = 0; i < 3; ++i) {
        for(int u = 0; u <= 1; ++u) {
            for(int v = 0; v <= 1; ++v) {
                auto s1 = get_path(X[0], Y[0], X[1], Y[1], u);
                auto s2 = get_path(X[0], Y[0], X[2], Y[2], v);
                //cerr << s1 << endl << s2 << endl << endl;
                s1.insert(s2.begin(), s2.end());
                if(ans.empty() or s1.size() < ans.size()) {
                    ans = s1;
                }
            }
        }
        rotate(X.begin(), X.begin() + 1, X.end());
        rotate(Y.begin(), Y.begin() + 1, Y.end());
    }
    
    cout << ans.size() << "\n";
    for(auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}