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

void run() {
    fastIO;

    std::string s;
    std::cin >> s;

    int n = (int)s.size();
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            l = i;
            break;
        }
    }    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ')') {
            r = i;
            break;
        }
    }

    if (l == -1 || r == -1 || l > r) {
        printf("0\n");
        return;
    }

    std::vector<int> a;
    while (l < r) {
        a.push_back(l);
        a.push_back(r);

        ++l;
        --r;

        while (l < r && s[l] != '(') {
            ++l;
        }
        while (l < r && s[r] != ')') {
            --r;
        }
    }

    printf("1\n%d\n", (int)a.size());
    std::sort(a.begin(), a.end());

    for (auto i : a) {
        printf("%d ", i + 1);
    }
    printf("\n");
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