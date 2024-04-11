#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
const int N=2e5+100;
int n,a[N],deg[N];
priority_queue<int,vector<int>,greater<int>>q;
signed main(){
	read(n);
	for(int i=1;i<n;i++)read(a[i]),deg[a[i]]++;
	write(a[1]);pc('\n');
	for(int i=1;i<=n;i++)if(deg[i]==0)q.push(i);
	for(int i=n-1;i;i--){
		writeln(a[i],q.top());q.pop();
		deg[a[i]]--;if(deg[a[i]]==0)q.push(a[i]);
	}
}