// Problem: E. Omkar and Forest
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[2003][2003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
		int t=1,g=p-1;
		for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) 
		if(s[i][j]=='#') 
		t=t*2%p;
		else g=0;
		printf("%lld\n",(t+g)%p);
	}
	return 0;
}