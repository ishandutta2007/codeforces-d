#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,Ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;Ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)Ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*Ny;
	}
	in db gf() {int a=read(),y=Ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
};
using namespace fast_io;
#define pb push_back
const int N=1e6+5;
int n,fa[N],siz[N],dep[N],son[N],top[N],a[N],cnt[N],tot,mn=1,mx;
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
void dfs1(int u,int f)
{
	siz[u]=1;
	for(int v:e[u]) if(v^f) {fa[v]=u,dep[v]=dep[u]+1,dfs1(v,u);if(siz[v]>siz[son[u]])son[u]=v;}
	if(e[u].size()==1) a[++tot]=u;
}
void dfs2(int u,int tp)
{
	top[u]=tp;if(son[u]) dfs2(son[u],tp);
	for(int v:e[u]) if(v^fa[u]&&v^son[u]) dfs2(v,v);
} 
in int lca(int u,int v)
{
	for(;top[u]^top[v];u=fa[top[u]]) if(dep[top[u]]<dep[top[v]]) swap(u,v);
	return dep[u]<dep[v]?u:v;
}
in int dis(int u,int v) {return dep[u]+dep[v]-2*dep[lca(u,v)];}
int main()
{
	n=read();mx=n-1;for(int i=1;i<n;i++) add(read(),read());
	dfs1(1,0);dfs2(1,1);a[++tot]=a[1];
	for(int i=1;i<tot;i++) if(dis(a[i],a[i+1])&1) mn=3;
	for(int i=1;i<=n;i++) 
	{
		for(int j:e[i]) cnt[i]+=e[j].size()==1;
		if(cnt[i]>1) mx-=cnt[i]-1;
	}
	write(mn,' '),write(mx,'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.