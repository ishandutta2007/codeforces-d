#include<bits/stdc++.h>
namespace in{
	#ifdef slow
	inline int getc(){return getchar();}
	#else
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
int t,n;int cnt1,cnt2,sum;
bool f[301];
signed main(){
	in::read(t);
	while(t--){
		in::read(n);int x;cnt1=cnt2=sum=0;
		for(int i=1;i<=n;i++)in::read(x),x==1?cnt1++:cnt2++,sum+=x;
		if(sum&1)puts("NO");
		else{
			memset(f,0,sizeof f);f[0]=true;
			for(int i=1;i<=cnt1;i++)
				for(int j=300;j>=1;j--)
					f[j]|=f[j-1];
			for(int i=1;i<=cnt2;i++)
				for(int j=300;j>=2;j--)
					f[j]|=f[j-2];
			puts(f[sum>>1]?"YES":"NO");
		}
	}
	out::flush();
	return 0;
}