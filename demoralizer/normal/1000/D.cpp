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
const int32_t M=998244353;

const int N=1e3+5;

int dp[N][N];
int a[N];

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
	dp[0][0] = 1;
	if(a[0] > 0 && a[0] < N){
		dp[0][a[0]] = 1;
	}
	rep(i,1,n){
		rep(j,0,N-3){
			dp[i][j] = (dp[i-1][j+1] + dp[i-1][j]) % M;
		}
		if(a[i] > 0 && a[i] < N){
			dp[i][a[i]] += dp[i-1][0];
			dp[i][a[i]] %= M;
		}
	}
	cout << (dp[n-1][0] + M - 1) % M;
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