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

int n;
vector<int> adj[MAXN];
int depth[MAXN], ans;
int rt;

void dfs(int v, int p = -1, int de = 0) {
	depth[v] = de;
	int cnt = 0, cnt2 = 0;
	for (int u: adj[v])
		if (u^p) {
			dfs(u, v, de + 1);
			cnt += (int)adj[u].size() == 1;
			cnt2++;
		}
	ans += cnt2 - cnt;
	if (cnt)
		ans++;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int v = 0; v < n; v++)
		if ((int)adj[v].size() == 1) {
			rt = v;
			break;
		}
	dfs(rt);
	int mask = 0, flag = 0;
	for (int v = 0; v < n; v++)
		if ((int)adj[v].size() == 1) {
			mask |= 1<<(depth[v]&1);
			if (depth[v] == 2)
				flag = 1;
		}
	ans -= flag;
	if (mask != 3)
		cout << "1 ";
	else
		cout << "3 ";
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