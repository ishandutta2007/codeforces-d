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

const int MAXN = 1e5 + 10;

bool can[MAXN];

void solve() {
    vector<int> vec {11, 111, 1111, 11111};
    can[0] = true;
    for (int i = 1; i < MAXN; i++)
        for (auto x: vec)
            if (i-x >= 0)
                can[i] |= can[i-x];
    int te; cin >> te;
    while (te--){
        int x; cin >> x;
        int ans = 0;
        if (x < MAXN)
            ans = can[x];
        else
            ans = 1;
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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