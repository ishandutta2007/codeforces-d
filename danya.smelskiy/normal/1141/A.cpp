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


long long x, y;



int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> x >> y;
    if (y % x) {
        cout << "-1\n";
        return 0;
    }
    int res = 0;
    y /= x;
    while (y > 1) {
        if (y % 3 == 0) {
            ++res;
            y /= 3;
        } else
        if (y % 2 == 0) {
            ++res;
            y /= 2;
        } else {
            cout << "-1\n";
            return 0;
        }
    }
    cout << res << '\n';
    return 0;
}