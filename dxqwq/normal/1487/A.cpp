#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003];
signed main()
{
	int T=read();
	while(T--)
	{	int n=read();
		for(int i=1; i<=n; i++) a[i]=read();
		int m=1000000000000000ll;
		for(int i=1; i<=n; i++) m=min(m,a[i]);
		int c=0;
		for(int i=1; i<=n; i++) if(m!=a[i]) ++c;
		printf("%lld\n",c);
	}
	return 0;
}