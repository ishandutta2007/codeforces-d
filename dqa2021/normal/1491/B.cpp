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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,A,B;
int a[110];
void solve(){
	n=read(),A=read(),B=read();
	rep(i,1,n) a[i]=read();
	rep(i,2,n) if (abs(a[i]-a[i-1])>1) return puts("0"),void();
	bool f=1;
	rep(i,2,n) f=f&&a[i]==a[i-1];
	if (f) printf("%d\n",B+min(A,B));
	else printf("%d\n",min(A,B));
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}