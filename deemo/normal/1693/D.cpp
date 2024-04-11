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

int n, p[2][MAXN];
int ex[2][MAXN], ot[2][2][MAXN];

void go(int w, int i) {
    assert(i);
    if (p[w][i-1] > p[w][i]) {
        int pos = ot[w][1][i] - 1;
        if (pos == -1 || p[w][pos] > p[w][i])
            ex[w][i] = pos + 1;
        else
            ex[w][i] = ex[!w][pos+1];
    } else {
        int pos = ot[w][0][i];
        ex[w][i] = min(ex[w][i], ex[w][pos]);
        int pos2 = ot[w][1][pos];
        if (pos2 == pos) return;

        ex[w][i] = min(ex[w][i], pos2);
        if (p[w][pos2] < p[w][pos+1])
            ex[w][i] = min(ex[w][i], ex[!w][pos]);
        else if (pos2 - 1 >= 0 && p[w][pos2-1] < p[w][pos+1]) {
            ex[w][i] = min(ex[w][i], ex[!w][pos2]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[0][i];
        p[1][i] = -p[0][i];
        ex[0][i] = ex[1][i] = ot[0][0][i] = ot[0][1][i] = ot[1][0][i] = ot[1][1][i] = i;
    }

    for (int w = 0; w < 2; w++)
        for (int i = 0; i < n; i++) {
            if (i && p[w][i-1] < p[w][i])
                ot[w][0][i] = ot[w][0][i-1];
            if (i && p[w][i-1] > p[w][i])
                ot[w][1][i] = ot[w][1][i-1];
        }

    for (int i = 1; i < n; i++) {
        go(0, i);
        go(1, i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = min(ex[0][i], ex[1][i]);
        ans += i - tmp + 1;
    }
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