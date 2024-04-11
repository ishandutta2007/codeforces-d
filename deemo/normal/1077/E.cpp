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
map<int, int> cnt;
int sec[MAXN], sz;

int go(int f, int b = 0) {
    int p = lower_bound(sec + b, sec + sz, f) - sec;
    if (p == sz) return 0;
    return f + go(f<<1, p + 1);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (auto x: cnt)
        sec[sz++] = x.S;
    sort(sec, sec + sz);

    int ans = 0;
    for (int f = 1; f <= n; f++)
        ans = max(ans, go(f));
    cout << ans << "\n";
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