#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 120000;

int N, B, D;
int ll[MAXN], rr[MAXN];
int a[MAXN], a_orig[MAXN];

bool works(int errors) {
    for (int i = 1; i <= N; i++) a[i] = a_orig[i];
    int it = 1;
    for (int x = errors+1; x + errors <= N; x++) {
        if (it < ll[x]) it = ll[x];
        int sum = 0;
        while (sum < B) {
            if (it > rr[x]) return false;
            if (sum + a[it] <= B) {
                sum += a[it];
                a[it] = 0;
            }
            else {
                a[it] -= B-sum;
                sum = B;
                break;
            } 
            it++;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N >> D >> B;
    for (int i = 1; i <= N; i++) cin >> a_orig[i];
    for (int x = 1; x <= N; x++) {
        LL t = min(x, N+1-x);
        ll[x] = max(1ll, (LL)x-((LL)D)*t);
        rr[x] = min((LL)N, (LL)x+((LL)D)*t);
    }
    int low = 0;
    int high = (N+1)/2;
    while (low < high) {
        int m = (low+high)/2;
        if (works(m)) high = m;
        else low = m+1;
    }
    cout << low << "\n";
}