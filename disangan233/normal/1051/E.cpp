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
	in db find() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e6+5,p=998244353;
int n,f[N],g[N];char a[N],l[N],r[N];
struct exkmp
{
	int n,z[N],p[N];char t[N];
	in void build(char *s)
	{
		n=strlen(s+1);z[1]=n,t[1]=s[1];
		for(int i=2,l=0,r=0;i<=n;i++)
		{
			t[i]=s[i];if(i<=r) z[i]=min(z[i-l+1],r-i+1);
			while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1]) z[i]++;
			if(i+z[i]-1>r) r=i+z[i]-1,l=i; 
		}
	}
	in void get_lcp(char *s)
	{
		int m=strlen(s+1);
		for(int i=1,l=0,r=0;i<=m;i++)
		{
			if(i<=r) p[i]=min(z[i-l+1],r-i+1);
			while(i+p[i]<=m&&s[i+p[i]]==t[p[i]+1]) p[i]++;
			if(i+p[i]-1>r) r=i+p[i]-1,l=i;
		}
	}
}L,R;
in void M(int &x) {x-=p;x+=x>>31&p;}
in int chk(int x,int l)
{
	int p=L.p[x],f1=0,f2=0;
	if(L.n<l||p==L.n||L.t[p+1]<a[x+p]) f1=1; p=R.p[x];
    if(R.n>l||p==R.n||R.t[p+1]>a[x+p]) f2=1; return f1&&f2;
}
int main()
{
	n=gs(a+1);gs(l+1);gs(r+1);f[0]=1;
	L.build(l),R.build(r),L.get_lcp(a),R.get_lcp(a);
	for(int i=0;i<=n;i++)
	{
		if(i) M(g[i]+=g[i-1]),M(f[i]+=g[i]);
		if(a[i+1]=='0')
		{
			if(L.n==1&&L.t[1]=='0') M(f[i+1]+=f[i]);
			continue;
		}
		if(L.n<R.n) M(g[i+L.n+1]+=f[i]),M(g[i+R.n]+=p-f[i]);
		if(chk(i+1,L.n)) M(f[i+L.n]+=f[i]);
		if(L.n^R.n&&chk(i+1,R.n)) M(f[i+R.n]+=f[i]);
	}
	write(f[n],'\n');
	return ot(),0;
}
//Author: disangan233