#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,w[1010];

void solve(){
	n=read();
	rep(i,1,n) w[i]=read();
	printf("%d\n",3*n);
	rep(i,1,n) if (i&1){
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
		printf("2 %d %d\n",i,i+1);
		printf("1 %d %d\n",i,i+1);
	}
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}