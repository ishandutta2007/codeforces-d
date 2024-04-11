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

int n, k, a[MAXN];

ll sec[MAXN]; int sz;
ll get(ll mid){
	sz = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < mid)
			sec[sz++] = mid - a[i];
	reverse(sec, sec + sz);
	ll ret = 0;
	for (int i = 0; sz-i > n/2; i++)
		ret += sec[i];
	return ret;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	ll lo = 0, hi = (ll)2e9 + 3;
	while (hi-lo>1){
		ll mid = hi+lo>>1;
		if (get(mid) <= k)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << "\n";
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