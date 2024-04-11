#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 500087, logN = 20, K = 333;

void solve() {
    /*
     * x....a..O..a....X
     * 000
     * 121
     * 321
     * 321
     *
     * 00000
     *
     */
    int n;
    cin >> n;
    vector <lli> a(n * 2);
    for (int i = 0; i < n * 2; ++i) cin >> a[i];
    sort(all(a));
    vector <lli> b;
    for (int i = 0; i < n * 2; i += 2) {
        if (a[i] != a[i + 1] || a[i] % 2 == 1) {
            cout << "NO\n";
            return;
        }
        if (b.size() && b.back() == a[i]) {
            cout << "NO\n";
            return;
        }
        b.pb(a[i]);
    }
    lli al = 0;
    for (int i = 1; i < n; ++i) {
        if ((b[i] - b[i - 1]) % (2 * i) == 0) {
            al += (b[i] - b[i - 1]) / (2 * i) * (n - i) * 2;
        } else {
            cout << "NO\n";
            return;
        }
    }
    if (b[0] > al && (b[0] - al) % (n * 2) == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}