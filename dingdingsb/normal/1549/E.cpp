// Problem: E. The Three Little Pigs
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/E
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    modint<mod> &operator ^=(int b){
        modint<mod> a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint<mod> &operator /=(modint<mod> o){return *this *=o^=mod-2;}
    modint<mod> &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint<mod> &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint<mod> &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint<mod> &operator /=(int o){return *this *= ((modint<mod>(o))^=mod-2);}
    template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
    template<class I>friend modint<mod> operator /(modint<mod> a,I b){return a/=b;}
    friend modint<mod> operator ^(modint<mod> a,int b){return a^=b;}
    friend bool operator ==(modint<mod> a,int b){return a.x==b;}
    friend bool operator !=(modint<mod> a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint<mod> operator - () {return x?mod-x:0;}
    modint<mod> &operator++(int){return *this+=1;}
};
typedef modint<1000000007>mint;
const int N=3000100;
int n,m;mint fac[N],ifac[N],f[N],g[N];
mint C(int n,int m){
	if(n<m)return 0;
	return fac[n]*ifac[m]*ifac[n-m];
}
signed main(){
	read(n,m);
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
	ifac[N-1]=1/fac[N-1];for(int i=N-1;i;i--)ifac[i-1]=ifac[i]*i;
	for(int i=0;i<=3*n+3;i++)f[i]=C(3*n+3,i)-C(3,i);
	for(int i=0;i<=3*n+3;i++)f[i]=f[i+1];
	for(int i=3*n+3;~i;i--){
		g[i]=f[i+2];
		f[i+2]-=g[i];
		f[i+1]-=3*g[i];
		f[i]-=3*g[i];
	}
	assert(f[0]==0);
	assert(f[1]==0);
	assert(f[2]==0);
	while(m--){
		int x;read(x);write(g[x].x);putchar('\n');
	}
}