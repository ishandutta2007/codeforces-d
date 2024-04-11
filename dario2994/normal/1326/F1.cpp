#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

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
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 15;
vector<LL> din[1<<MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<string> aa(N);
    for (int i = 0; i < N; i++) {
        cin >> aa[i];
    }
    for (int bb = 1; bb < (1<<N); bb++) {
        int l = __builtin_popcount(bb);
        if (l <= 1) {
            for (int i = 0; i < N; i++) din[bb][i] = {1};
            continue;
        }
        for (int i = 0; i < N; i++) {
            if ((bb&(1<<i)) == 0) continue;
            din[bb][i].resize(1<<(l-1), 0ll);
            for (int j = 0; j < N; j++) {
                if (i == j or (bb&(1<<j)) == 0) continue;
                int val = aa[i][j] == '1';
                const auto& vec = din[bb^(1<<i)][j];
                for (int s = 0; s < (1<<(l-2)); s++) din[bb][i][val + 2*s] += vec[s];
            }
        }
    }
    vector<LL> res(1<<(N-1));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < (1<<(N-1)); k++) res[k] += din[(1<<N)-1][i][k];
    }
    // cout << res[0] << " " << res[431] << endl;
    for (LL x: res) cout << x << " ";
    cout << "\n";
}