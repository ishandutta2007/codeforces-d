# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


long long h, a[200005];
long long n;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> h >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        if (-a[i] >= h) {
            cout << i << '\n';
            return 0;
        }
    }
    if (a[n] >= 0) {
        cout << "-1\n";
        return 0;
    }
    long long c = -a[n];
    long long ans = 2e18;
    for (int i = 1; i <= n; ++i) if (a[i] < 0) {
        long long hh = h + a[i];
        long long cur = i;
        cur += ((hh + c - 1ll) / c) * n;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}