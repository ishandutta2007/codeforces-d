#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	// in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	#define gc() getchar()
	in int read()
	{
		int x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
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
#define pb push_back
const int N=1e4+5,inf=1e9;
int n,m,pos,a[N],b[N],c[N];
int main()
{
	n=read();m=read();for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(a[i]+a[j]<=n) c[i+j]++;
	for(int i=3;i<=n;i++) c[i]+=c[i-1];if(m>c[n]) return write("-1"),ot(),0;
	for(int i=n;i;i--) if(c[i-1]<m)
	{
		for(int j=1;j<i;j++) for(int k=j+1;k<i;k++) b[j+k]++;
		while(b[a[i]]^(m-c[i-1])) a[i]++;pos=i;break;
	}
	for(int i=n;i>pos;i--) a[i]=inf-(n-i)*(a[pos]+1);
	for(int i=1;i<=n;i++) write(a[i]," \n"[i==n]);
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.