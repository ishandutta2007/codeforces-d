#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
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
const int N=1e6+5;
int n,m,k,a[N],dis[N],vis[N],mn,mx;
vector<int>e[N],E[N];in void add(int u,int v) {e[u].push_back(v);e[v].push_back(u);}
struct node{int a,b;bool operator <(node x) const {return a>x.a;}};
priority_queue<node>q;
in void dijkstra(int s)
{
	for(int i=1;i<=n;i++) dis[i]=1e9;
	memset(vis,0,sizeof(vis));q.push({dis[s]=0,s});
	while(!q.empty())
	{
		int u=q.top().b;q.pop();if(vis[u]) continue;vis[u]=1;
		for(int v:e[u]) if(!vis[v]&&dis[v]>dis[u]+1)
		dis[v]=dis[u]+1,q.push({dis[v],v});
	}
}
int main()
{
	n=read();m=read();for(int i=1,u,v;i<=m;i++) u=read(),v=read(),e[v].push_back(u),E[u].push_back(v);
	k=read();for(int i=1;i<=k;i++) a[i]=read();
	dijkstra(a[k]);
	for(int i=1;i<k;i++) if(dis[a[i+1]]+1!=dis[a[i]]) mn++;
	for(int i=1;i<k;i++) for(int v:E[a[i]])
	if(v^a[i+1]&&dis[v]+1==dis[a[i]]) {mx++;break;}
	write(mn,' ');write(mx,'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.