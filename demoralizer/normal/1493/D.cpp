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

int lp[N+1];
vector<int> pr;
#define SIEVE
void sieve(){
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}

multiset<int> mn[N];
int ans = 1;

map<int, int> a[N];

void solve(){
	int n,q;
	cin >> n >> q;
	
	rep(i,0,n){
		int x;
		cin >> x;
		while(x != 1){
			int p = lp[x];
			if(a[i][p] == 0){
				mn[p].insert(0);
			}
			int best = *mn[p].begin();
			mn[p].erase(mn[p].find(a[i][p]));
			a[i][p]++;
			mn[p].insert(a[i][p]);
			if(sz(mn[p]) == n && best < *mn[p].begin()){
				ans = ans * p % M;
			}
			x /= p;
		}
	}
	
	rep(z,0,q){
		int i,x;
		cin >> i >> x;
		i--;
		while(x != 1){
			int p = lp[x];
			if(a[i][p] == 0){
				mn[p].insert(0);
			}
			int best = *mn[p].begin();
			mn[p].erase(mn[p].find(a[i][p]));
			a[i][p]++;
			mn[p].insert(a[i][p]);
			if(sz(mn[p]) == n && best < *mn[p].begin()){
				ans = ans * p % M;
			}
			x /= p;
		}
		cout << ans << "\n";
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
	//cin>>t;
	while(t--) solve();
	return 0;
}