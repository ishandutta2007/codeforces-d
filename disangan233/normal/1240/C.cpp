#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {re a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
#define eb emplace_back
#define pii pair<int,int>
const int N=5e5+5;
int t,n,k,vis[N];
ll f[N][2];
vector<pii>g[N];
in void add(re x,re y,re z) {g[x].eb(y,z);g[y].eb(x,z);}
void dfs(re u,re fa)
{
	for(auto x:g[u]) if(x.first^fa)
	{
		re v=x.first,w=x.second;f[v][1]+=w;dfs(v,u);
	}
	sort(g[u].begin(),g[u].end(),[](pii a,pii b){return f[a.first][1]-f[a.first][0]>f[b.first][1]-f[b.first][0];});
	re i=0;
	for(re j=0;j<k&&i<g[u].size();i++) if(g[u][i].first^fa)
	{
		re v=g[u][i].first;if(f[v][0]>=f[v][1]) break;
		f[u][0]+=f[v][1];(j<k-1)?f[u][1]+=f[v][1]:f[u][1]+=f[v][0];
		j++;
	}
	for(;i<g[u].size();i++) if(g[u][i].first^fa)
	{
		re v=g[u][i].first;f[u][0]+=f[v][0];f[u][1]+=f[v][0];
	}
}
int main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(re i=1;i<=n;i++) vis[i]=f[i][0]=f[i][1]=0,g[i].clear();
		for(re i=1,u,v,w;i<n;i++) u=read(),v=read(),w=read(),add(u,v,w);
		dfs(1,0);write(f[1][0],'\n');
	}
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.