#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[500001],m;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+n+1);
		int flag=0;
		for(int i=2;i<=n;++i)
			if(a[i]==a[i-1])
			{
				flag=1;
				break;
			}
		if(!flag)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}