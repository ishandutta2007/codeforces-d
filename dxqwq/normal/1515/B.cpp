// Problem: B. Phoenix and Puzzle
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	bool f=0;
    	if(n%4==0)
    	{
    		int A=n/4;
    		int B=sqrt(A);
    		if(B*B==A) f=1;
    	} 
    	if(n%2==0)
    	{
    		int A=n/2;
    		int B=sqrt(A);
    		if(B*B==A) f=1;
    	} 
    	if(f) puts("YES");
    	else puts("NO");
    }
	return 0;
}