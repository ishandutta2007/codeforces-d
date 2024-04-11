// Problem: CF1106D Lunar New Year and a Wander
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1106D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=1e5+100;
int n,m;vector<int>e[N];
bool vis[N];priority_queue<int,vector<int>,greater<int>>q;
signed main(){
	read(n,m);
	for(int i=1,u,v;i<=m;i++){
		read(u,v);e[u].pb(v),e[v].pb(u);
	}
	auto ins=[&](int u){
		if(vis[u])return;
		write(u);putchar(' ');vis[u]=1;
		for(auto v:e[u])if(!vis[v])
			q.push(v);
	};
	ins(1);
	while(q.size()){
		int x=q.top();q.pop();
		ins(x);
	}
}