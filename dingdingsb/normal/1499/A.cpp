#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int t,n,k1,k2,w,b;
signed main(){
	read(t);
	while (t--){
		read(n,k1,k2,w,b);
		int wmx=min(k1,k2)+abs(k1-k2)/2;
		int bmx=min(n-k1,n-k2)+abs(k1-k2)/2;
		if (wmx>=w&&bmx>=b)puts("YES");
		else puts("NO");
	}
	return 0;
}