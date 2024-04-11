// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 100100;

int a[N], b[N];
std::string s;
int ptr = 0;

bool checkOk(int l, int r) {
    if (r - l <= 1) {
        return true;
    }

    int m = (l + r) / 2;
    bool isOk = true;
    isOk &= checkOk(l, m);
    isOk &= checkOk(m, r);

    int i = l, j = m;
    while (i < m && j < r) {
        if (ptr >= (int)s.size()) {
            isOk = false;
            break;
        }
        if (s[ptr] == '0') {
            ++i;
        } else {
            ++j;
        }
        ++ptr;
    }

    return isOk;
}

void mergeSort(int l, int r) {
    if (r - l <= 1) {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m, r);

    int i = l, j = m;
    int k = l;
    while (i < m && j < r) {
        assert(ptr < (int)s.size());
        if (s[ptr] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
        ++ptr;
    }
    while (i < m) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }

    for (i = l; i < r; ++i) {
        a[i] = b[i];
    }
}

int getN() {
    int l = 0, r = N;
    while (r - l > 1) {
        int mid = (l + r) / 2;

        ptr = 0;
        bool res = checkOk(0, mid);

        if (!res) {
            r = mid;
        } else {
            l = mid;
        }
    }

    // std::cout << l << ' ' << r << std::endl;

    ptr = 0;
    bool res = checkOk(0, l);
    assert(res && ptr == (int)s.size());

    return l;
}

void run() {
    fastIO;

    std::cin >> s;

    // int n = 1;
    // for (n = 1; n < 100; ++n) {
    //     ptr = 0;
    //     if (!checkOk(0, n)) {
    //         continue;
    //     }
    //     if (ptr != (int)s.size()) {
    //         continue;
    //     }
    //     std::cout << n << ' ';
    //     // break;
    // }

    // return;

    int n = getN();

    ptr = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    mergeSort(0, n);

    for (int i = 0; i < n; ++i) {
        b[a[i]] = i;
    }

    std::cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << b[i] + 1 << ' ';
    }
    std::cout << '\n';
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}