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
const int N=1e6+5,p=1e9+7; 
int n,k,ans,a[N],mx[N],s[N];
in void M(int &x) {x-=p;x+=x>>31&p;}
void solve(int l,int r)
{
	if(r-l+1<k) return;int m=(l+r)>>1;mx[m]=a[m],s[m]=s[l-1]=0;
	for(int i=m-1;i>=l;i--) mx[i]=max(mx[i+1],a[i]),s[i]=0;
	for(int i=l;i<=m;i++)
	{
		int x=i-k+1;if(x>=l) s[i]=s[x];
		M(s[i]+=mx[i]);
	}
	for(int i=m+1,j=m,Mx=a[i];i<=r;Mx=max(Mx,a[++i]))
	{
		if(i-l+1<k) continue;while(j>=l&&mx[j]<Mx) j--;
		int x=i-j,t=(x-1)/(k-1),u=t+1;t-=(i-m-1)/(k-1);
		M(ans+=1ll*Mx*t%p);M(ans+=s[max(i-u*(k-1),l-1)]);
	}
	solve(l,m);solve(m+1,r);
}
int main()
{
	n=read(),k=read();for(int i=1;i<=n;i++) a[i]=read();
	solve(1,n);write(ans,'\n');
	return ot(),0;
}
//Author: disangan233