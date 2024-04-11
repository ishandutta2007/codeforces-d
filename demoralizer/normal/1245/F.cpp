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

const int N=0;

int a[33];
int b[33];
int dp[33][2][2][2]; // pos,small,big,nonzero

int calc(int pos,int small,int big,int nonzero){
	if(pos < 0){
		return nonzero;
	}
	int &ans = dp[pos][small][big][nonzero];
	if(ans != -1){
		return ans;
	}
	
	ans = 0;
	// bigger, smaller
	// 0 0, 1 0, 0 1
	
	// 0 0
	if(big || a[pos] == 0){
		ans += calc(pos-1,(small || b[pos]),big,nonzero);
	}
	
	// 1 0
	if((small || b[pos] == 1) && (big || a[pos] == 0)){
		ans += calc(pos-1,small,big,1);
	}
	
	// 0 1
	if(nonzero){
		ans += calc(pos-1,(small || b[pos]),(big || a[pos] == 0),nonzero);
	}
	
	return ans;
}

void solve(){
	mem1(dp);
	int l,r;
	cin >> l >> r;
	
	rep(i,0,30){
		a[i] = l >> i & 1;
		b[i] = r >> i & 1;
	}
	
	int ans = calc(29,0,0,0) * 2 + (l == 0);
	cout << ans << "\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}