#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
	I void writeln() {pc('\n');}
}using namespace FastIO;
int n,a[N+5],b[N+5],p[N+5],w[N+5];vector<int> g[N+5];
int main()
{
	RI Tt,i,j,z;read(Tt);W(Tt--)
	{
		for(read(n),i=0;i<=n;++i) p[i]=0,g[i].clear();
		for(i=1;i<=n;++i) read(a[i]),g[a[i]].push_back(i);
		for(i=1;i<=n;++i) for(z=g[i].size(),j=0;j^z;++j) p[j]?b[p[j]]=i:w[j]=i,p[j]=g[i][j];
		for(i=0;p[i];++i) b[p[i]]=w[i];
		for(i=1;i<=n;++i) write(b[i]);writeln();
	}return clear(),0;
}