#include<bits/stdc++.h>
using namespace std;
#define re register int
#define un unsigned
#define ll un long long
#define ak *
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
inline ll qpow(ll x,ll y,ll p,ll z=1)
{
 	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(x*z)%p:z;
	return z;
}
int n,m,k,a[5000005],l,r,ans;
int main()
{
	n=read(),m=read();k=1e9;
	for(re i=1;i<=n;i++)
	{
		re x=read(),y=read(),now;
		if(x>=m) now=x-m;
		else now=ceil(1.0*(m-x)/y)*y+x-m;
		if(now<k) ans=i,k=now;
	}
	cout<<ans;
	return 0;
}