#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
inline char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
int n,k,a[1005];
inline ll qpow(ll a,ll b,ll p,ll c=1ll)
{
	a%=p-1;
	for(;b;b>>=1,a=a*a%p) if(b&1) c=a*c%p;
	return c;
}
inline int calc(re x)
{
	re tot=0;
	while(x) tot+=x%10,x/=10;
	return tot;
}
int main()
{
	re t=read();
	while(t--)
	{
		n=read();k=read();
		for(re i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		if(a[n]-a[1]<=2*k) cout<<a[1]+k<<endl;
		else puts("-1");
	}
}