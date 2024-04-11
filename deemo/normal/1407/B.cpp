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

const int MAXN = 1e6 + 10;

int n, a[MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    vector<bool> del(n, false);
    del[0] = true;
    int cur = a[0];
    cout << cur << " ";
    for (int i = 0; i < n-1; i++) {
        int ind = -1;
        for (int j = 0; j < n; j++)
            if (!del[j])
                if (ind == -1 || __gcd(a[ind], cur) < __gcd(a[j], cur))
                    ind = j;
        del[ind] = true;
        cout << a[ind] << " ";
        cur = __gcd(cur, a[ind]);
    }
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}