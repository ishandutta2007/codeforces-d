/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105;
int a[N], cnt[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < N; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]]++;
	for (int i = 0; i < N; i++) {
		if (cnt[i]) {
			cout << i << ' ';
			cnt[i]--;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < cnt[i]; j++)
			cout << i << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}