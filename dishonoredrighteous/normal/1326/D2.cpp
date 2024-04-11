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

template<class V, class W>
std::ostream& operator<<(std::ostream& out, const std::pair<V, W>& data) {
    out << data.first << ' ' << data.second << '\n';
    return out;
}

std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// std::mt19937 rnd(238);

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 1000100;
const int MODS[3] = {(int)1e9 + 7, (int)1e9 + 9, 998244353};
const int PS[3] = {239, 661, 127};
const int MOD = 998244353;

int add(int a, int b, int mod = MOD) {
    if (a + b >= mod) {
        return a + b - mod;
    }
    return a + b;
}

int sub(int a, int b, int mod = MOD) {
    if (a - b < 0) {
        return a - b + mod;
    }
    return a - b;
}

int mul(int a, int b, int mod = MOD) {
    return (int)(1ll * a * b % mod);
}

int binpow(int a, int n, int mod = MOD) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return binpow(mul(a, a, mod), n / 2, mod);
    } else {
        return mul(binpow(a, n - 1, mod), a, mod);
    }
}

int rev(int a, int mod = MOD) {
    return binpow(a, mod - 2, mod);
}

int P, MOD1, MOD2;

int n;
char s[N];
int z[N];
int hash1[N], revhash1[N], p1[N];
int hash2[N], revhash2[N], p2[N];

void buildZ() {
    int l = 0, r = 1;
    for (int i = 1; i < 2 * n + 1; ++i) {
        if (i < r) {
            z[i] = std::min(z[i - l], r - i);
        }
        while (i + z[i] < 2 * n + 1 && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] >= r) {
            l = i;
            r = i + z[i];
        }
    }
}

void precalc() {
    p1[0] = 1;
    p2[0] = 1;

    for (int i = 1; i <= n; ++i) {
        p1[i] = mul(p1[i - 1], P, MOD1);
        p2[i] = mul(p2[i - 1], P, MOD2);
    }

    hash1[0] = s[0];
    hash2[0] = s[0];

    revhash1[0] = s[n - 1];
    revhash2[0] = s[n - 1];

    for (int i = 1; i < n; ++i) {
        hash1[i] = add(mul(hash1[i - 1], P, MOD1), s[i], MOD1);
        hash2[i] = add(mul(hash2[i - 1], P, MOD2), s[i], MOD2);

        revhash1[i] = add(mul(revhash1[i - 1], P, MOD1), s[n - i - 1], MOD1);
        revhash2[i] = add(mul(revhash2[i - 1], P, MOD2), s[n - i - 1], MOD2);
    }
}

std::pair<int, int> substrHash(int l, int r) {
    if (l > r) {
        return std::make_pair(0, 0);
    }

    int h1 = hash1[r];
    int h2 = hash2[r];

    if (l != 0) {
        h1 = sub(h1, mul(hash1[l - 1], p1[r - l + 1], MOD1), MOD1);
        h2 = sub(h2, mul(hash2[l - 1], p2[r - l + 1], MOD2), MOD2);
    }

    return std::make_pair(h1, h2);
}

std::pair<int, int> substrRevHash(int l, int r) {
    if (l > r) {
        return std::make_pair(0, 0);
    }

    int h1 = revhash1[r];
    int h2 = revhash2[r];

    if (l != 0) {
        h1 = sub(h1, mul(revhash1[l - 1], p1[r - l + 1], MOD1), MOD1);
        h2 = sub(h2, mul(revhash2[l - 1], p2[r - l + 1], MOD2), MOD2);
    }

    return std::make_pair(h1, h2);
}

std::pair<int, int> mergeHashes(std::pair<int, int> h1, std::pair<int, int> h2, int pefLen) {
    std::pair<int, int> newHash;

    newHash.first = add(mul(h1.first, p1[pefLen], MOD1), h2.first, MOD1);
    newHash.second = add(mul(h1.second, p2[pefLen], MOD2), h2.second, MOD2);

    return newHash;
}

int palLen[N];

std::string solveCase() {
    precalc();
    for (int i = 0; i <= n; ++i) {
        palLen[i] = 0;
    }

    std::string copyS;
    for (int i = 0; i < n; ++i) {
        copyS.push_back(s[i]);
    }

    if (substrHash(0, n - 1) == substrRevHash(0, n - 1)) {
        std::string ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(s[i]);
        }
        return ans;
    }

    for (int i = n / 2 + 1; i < n; ++i) {
        palLen[i] = std::min(i, palLen[i - 1] + 2);

        while (substrHash(i - palLen[i], i) != substrRevHash(n - i - 1, n - (i - palLen[i]) - 1)) {
            --palLen[i];
        }
    }

    int maxPalLen = palLen[n - 1] + 1;
    int bestPref = 0;

    for (int i = 0; i < n - i - 2; ++i) {
        if (copyS[i] != copyS[n - i - 1]) {
            break;
        }

        if (maxPalLen < 2 * i + 3 + palLen[n - i - 2]) {
            maxPalLen = 2 * i + 3 + palLen[n - i - 2];
            bestPref = i + 1;
        }
    }

    std::string shit1 = copyS.substr(n - bestPref - palLen[n - bestPref - 1] - 1, n - (n - bestPref - palLen[n - bestPref - 1] - 1));
    std::string shit2 = copyS.substr(0, bestPref);

    return shit2 + shit1;
} 

void solve() {
    P = PS[rnd() % 3];
    MOD1 = MODS[rnd() % 3];
    MOD2 = MODS[rnd() % 3];

    while (MOD1 == MOD2) {
        MOD2 = MODS[rnd() % 3];
    }

    scanf("\n%s", s);
    n = strlen(s);

    auto ans1 = solveCase();
    std::reverse(s, s + n);
    auto ans2 = solveCase();

    if (ans1.size() > ans2.size()) {
        printf("%s\n", ans1.c_str());
    } else {
        printf("%s\n", ans2.c_str());
    }
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