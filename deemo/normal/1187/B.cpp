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

int n, pt[MAXN][C];
string s;
int cnt[26];

bool check(int mid){
	for (int w = 0; w < C; w++)
		if (pt[mid][w] < cnt[w])
			return false;
	return true;
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		for (int w = 0; w < C; w++)
			pt[i+1][w] = pt[i][w] + int(s[i] - 'a' == w);

	int q; cin >> q;
	while (q--){
		string t; cin >> t;
		memset(cnt, 0, sizeof(cnt));
		for (char c: t)
			cnt[c-'a']++;
		int lo = 0, hi = s.size();
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (check(mid))
				hi = mid;
			else
				lo = mid;
		}
		cout << hi << "\n";
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