#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=2e5+5;

int n;
int a[N];
int dp[N][2];
vector<int> v[N];

void dfs(int z,int p){
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		dfs(x,z);
		dp[z][0] += dp[x][1];
		dp[z][1] += dp[x][0];
	}
	dp[z][0]++;
}

int ans = 0;
void dfs2(int z,int p){
	for(int x:v[z]){
		if(x == p){
			// consider parent contribution
			int siz = dp[z][0] + dp[z][1];
			int d0 = dp[p][0] - dp[z][1];
			int d1 = dp[p][1] - dp[z][0];
			dp[z][0] += d1;
			dp[z][1] += d0;
			ans += (d1 - d0 + M) % M * siz % M * a[z] % M;
			ans %= M;
			continue;
		}
		int siz = dp[x][0] + dp[x][1];
		siz = n - siz;
		ans += (dp[x][1] - dp[x][0] + M) % M * siz % M * a[z] % M;
		ans %= M;
	}
	// cout << z << " " << dp[z][0] << " " << dp[z][1] << "\n";
	ans += n * a[z] % M;
	ans %= M;
	for(int x:v[z]){
		if(x == p){
			continue;
		}
		dfs2(x,z);
	}
}

void solve(){
	cin >> n;
	rep(i,1,n+1){
		cin >> a[i];
		a[i] = (M + a[i]) % M;
	}
	rep(i,1,n){
		int x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(1,0);
	dfs2(1,0);
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}