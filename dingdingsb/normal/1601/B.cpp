// Problem: B. Frog Traveler
// Contest: Codeforces - Codeforces Round #751 (Div. 1)
// URL: https://codeforces.com/contest/1601/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=3e5+100;
int n,a[N],b[N];
vector<int>can[N];
set<pair<int,int>>st;
void add(int u){
	for(auto v:can[u])
		if(st.find(mp(v,u))!=st.end())
			st.erase(mp(v,u));
}
int lst[N],fr[N];
//lst
//fr
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]),can[i+b[i]].pb(i),st.insert(mp(i,i+b[i]));
	add(n);queue<int>q;q.push(n);
	while(q.size()){
		int u=q.front();q.pop();
		if(u-a[u]<=0){
			vector<int>ans;ans.pb(0);
			while(u!=n)ans.pb(fr[u]),u=lst[u];
			reverse(ans.begin(),ans.end());
			write(ans.size());pc('\n');
			for(auto x:ans)write(x),pc(' ');
			return 0;
		}
		int l=u-a[u],r=u;
		while(1){
			auto it=st.lower_bound(mp(l,0));
			if(it==st.end())break;
			if(it->first>r)break;
			fr[it->second]=it->first;
			lst[it->second]=u;q.push(it->second);
			add(it->second);
		}
	}
	puts("-1");
}