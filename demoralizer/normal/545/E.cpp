#include <bits/stdc++.h>
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

const int N=3e5+5;

int w[N],vis[N];
vector<pii> v[N];

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,m+1){
		int x,y;
		cin>>x>>y>>w[i];
		v[x].pb({y,i});
		v[y].pb({x,i});
	}
	int u,ans=0;
	cin>>u;
	
	set<pair<pii, pii>> s;
	set<int> kept;
	s.insert({{0,0},{u,0}});
	while(sz(s)){
		int ver = s.begin()->sc.fr;
		int dis = s.begin()->fr.fr;
		int id = s.begin()->sc.sc;
		s.erase(s.begin());
		if(vis[ver]){
			continue;
		}
		vis[ver]=1;
		if(id)kept.insert(id),ans+=w[id];
		for(auto x:v[ver]){
			s.insert({{dis+w[x.sc],w[x.sc]},x});
		}
	}
	cout<<ans<<"\n";
	for(int x:kept){
		cout<<x<<" ";
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