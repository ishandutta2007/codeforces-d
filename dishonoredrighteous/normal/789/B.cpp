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
    int b1, q, l, m;
    scanf("%d%d%d%d", &b1, &q, &l, &m);

    if (abs(b1) > l) {
    	printf("0\n");
    	return;
    }

    std::unordered_set<int> bad;
    while (m--) {
    	int cur;
    	scanf("%d", &cur);
    	bad.insert(cur);
    }

    if (q == 1) {
    	if (bad.find(b1) != bad.end()) {
    		printf("0\n");
    	} else {
    		printf("inf\n");
    	}
    	return;
    }
    if (q == -1) {
    	if (bad.find(b1) != bad.end() && bad.find(-b1) != bad.end()) {
    		printf("0\n");
    	} else {
    		printf("inf\n");
    	}
    	return;
    }
    if (b1 == 0) {
    	if (bad.find(0) == bad.end()) {
    		printf("inf\n");
    	} else {
    		printf("0\n");
    	}
    	return;
    }

    if (q == 0) {
    	int ans = 0;
    	if (bad.find(0) == bad.end()) {
    		printf("inf\n");
    	} else {
    		if (bad.find(b1) == bad.end()) {
    			printf("1\n");
    		} else {
    			printf("0\n");
    		}
    	}
    	return;
    }

    int cnt = 0;
    ll cur = b1;
    while (true) {
    	if (llabs(cur) > l) {
    		break;
    	}
    	if (bad.find(cur) == bad.end()) {
    		++cnt;
    	}
    	cur *= q;
    }

    printf("%d\n", cnt);
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