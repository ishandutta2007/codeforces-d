#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 2e5 + 10;

int n, a[MAXN];

void solve() {
	cin >> n;
	int mx = -1;
	for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
	int ind = 0;
	while (a[ind] != mx) ind++;
	for (int i = 0; i + 1 < ind; i++)
		if (a[i+1] < a[i]){
			cout << "NO\n";
			return;
		}
	for (int i = n-1; i - 1 > ind; i--)
		if (a[i] > a[i-1]){
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}