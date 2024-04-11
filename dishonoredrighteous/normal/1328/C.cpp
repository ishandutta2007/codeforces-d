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

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 50100;

char a[N], b[N], c[N];

// b > c, b -> min
void solve() {
    int n;
    scanf("%d\n%s", &n, a);

    bool eq = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') {
            b[i] = '0';
            c[i] = '0';
        } else if (a[i] == '1') {
            if (eq) {
                b[i] = '1';
                c[i] = '0';
            } else {
                b[i] = '0';
                c[i] = '1';
            }

            eq = false;
        } else {
            if (eq) {
                b[i] = '1';
                c[i] = '1';
            } else {
                b[i] = '0';
                c[i] = '2';
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%c", b[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%c", c[i]);
    }
    printf("\n");
}

void run() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
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