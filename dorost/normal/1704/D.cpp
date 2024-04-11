/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	int in = 0;
	int mn = LLONG_MAX, mx = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		int wef = 0, x;
		for (int j = 0; j < m; j++)
			cin >> x, wef += x * j;
		mn = min(mn, wef);
		if (wef > mx) {
			mx = wef;
			in = i + 1;
		}
	}
	cout << in << ' ' << mx - mn << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}