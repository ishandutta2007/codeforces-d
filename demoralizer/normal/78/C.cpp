#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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



void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	if(n%2==0 || k>=m){
		cout<<"Marsel";
		return;
	}
	if(m%2==0 && k<=m/2){
		cout<<"Timur";
		return;
	}
	vector<int> d,s;
	for(int i=1;i*i<=m;i++){
		if(m%i)continue;
		if(i>=k)d.pb(i);
		if(m/i != i && m/i>=k)d.pb(m/i);
	}
	sort(all(d));
	s.resize(sz(d));
	rep(i,0,sz(d)){//cout<<d[i]<<" ";
		int ans=0;
		rep(j,0,i){
			if(d[i]%d[j]==0 && s[j]==0)ans=1;
		}
		s[i]=ans;
	}
	if(s.back()){
		cout<<"Timur";
	}
	else{
		cout<<"Marsel";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}