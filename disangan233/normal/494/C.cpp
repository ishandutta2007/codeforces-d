#pragma GCC optimize(2,3,"Ofast","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define ld long db
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
#define pb push_back
const int N=1e5+5,M=5e3+5,K=1e2+5;
int n,m,a[N],lg[N],f[N][K];db g[M][M];
vector<int>e[M];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);} 
struct did{int l,r,mx;db p;in bool operator<(did a)const{return l^a.l?l<a.l:r>a.r;}}b[M];
in int ask(int l,int r) {int k=lg[r-l+1];return max(f[l][k],f[r-(1<<k)+1][k]);}
void dfs(int u)
{
	for(int v:e[u]) dfs(v); g[u][0]=1-b[u].p;
	for(int v:e[u]) g[u][0]*=g[v][b[u].mx-b[v].mx];
	for(int i=1;i<=m;i++)
	{
		db p1=1,p2=1;
		for(int v:e[u]) p1*=g[v][min(i-b[v].mx+b[u].mx-1,m)],p2*=g[v][min(i-b[v].mx+b[u].mx,m)];
		g[u][i]=b[u].p*p1+(1-b[u].p)*p2;
	}
} 
int main()
{
	n=read(),m=read();int mx=-1e9;
	for(int i=1;i<=n;i++) mx=max(mx,a[i]=read());
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	for(int j=1;j<=lg[n];j++) for(int i=1;i<=n-(1<<j)+1;i++) f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=m;i++) b[i].l=read(),b[i].r=read(),b[i].p=gf(),b[i].mx=ask(b[i].l,b[i].r);
	b[++m]={1,n,ask(1,n),0};sort(b+1,b+m+1);
	for(int i=2;i<=m;i++) for(int j=i-1;j;j--) if(b[j].l<=b[i].l&&b[i].r<=b[j].r) {e[j].pb(i);break;}
	dfs(1);db ans=0;for(int i=0;i<=m;i++) ans+=(i+mx)*(g[1][i]-(!i?0:g[1][i-1]));
	printf("%.9lf",ans); 
	return ot(),0;
}
//Author: disangan233