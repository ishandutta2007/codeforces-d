/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (is_sorted(a, a + n)) {
		cout << 0 << '\n';
		return;
	} else if (a[0] == 1 || a[n - 1] == n) {
		cout << 1 << '\n';
	} else if (a[0] == n && a[n - 1] == 1) {
		cout << 3 << '\n';
	} else {
		cout << 2 << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}