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

const int MAXN = 1e3 + 10;

int n;
string s;

void solve() {
	cin >> s; n = s.size();
	vector<int> vec;
	int r = n;
	for (int i = 0; i < r; i++)
		if (s[i] == ')') {
			continue;
		} else {
			r--;
			while (r > i && s[r] != ')') r--;
			if (r > i)
				vec.push_back(i+1), vec.push_back(r+1);
			else
				break;
		}
	if (vec.empty())
		cout << "0\n";
	else {
		cout << "1\n";
		cout << vec.size() << "\n";
		sort(vec.begin(), vec.end());
		for (auto x: vec)
			cout << x << " ";
		cout << "\n";
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