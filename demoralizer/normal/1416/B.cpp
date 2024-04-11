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

const int N=1e4+5;

int a[N];

void solve(){
	int n;
	cin >> n;
	int sum = 0;
	rep(i,1,n+1){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n){
		cout << "-1\n";
		return;
	}
	
	if(n == 1){
		cout << "0\n";
		return;
	}
	
	sum /= n;
	
	vector<pair<pii, int>> pr;
	
	rep(i,2,n+1){
		int tmp = (i - a[i] % i)%i;
		if(tmp){
			pr.pb({{1,i},tmp});
			a[1] -= tmp;
			a[i] += tmp;
		}
		pr.pb({{i,1},a[i]/i});
		a[1] += a[i];
		a[i] = 0;
	}
	rep(i,2,n+1){
		pr.pb({{1,i},sum});
	}
	assert(sz(pr) <= 3 * n);
	cout << sz(pr) << "\n";
	for(auto x:pr){
		cout << x << "\n";
	}
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