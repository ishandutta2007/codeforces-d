/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, ans = 0, x, y, mn = 1000;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		mn = min (mn, y);
		ans += x * mn;
	}
	cout << ans;
}