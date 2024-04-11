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

struct node{
	node* next[2];
}
ns[31*N];
int cnt = 1;
node* make(){
	return (ns + cnt++);
}
void insert(int n){
	node *root = ns;
	for(int i = 29; i >= 0; i--){
		int d = n >> i & 1;
		if(!root -> next[d]){
			root -> next[d] = make();
		}
		root = root -> next[d];
	}
}

int ans = 0;

int dfs(node *root,int d = 29){
	if(d < 0) return 1;
	int a = 0, b = 0;
	if(root -> next[0])
		a = dfs(root -> next[0], d - 1);
	if(root -> next[1])
		b = dfs(root -> next[1], d - 1);
	int tmp = max(a,b);
	tmp += (a && b);
	amax(ans, tmp);
	return tmp;
}

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		int a;
		cin >> a;
		insert(a);
	}
	dfs(ns);
	cout << n - ans;
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