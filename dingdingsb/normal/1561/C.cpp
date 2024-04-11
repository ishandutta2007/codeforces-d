// Problem: C. Deep Down Below
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int N=1e5+100;
int t,n;int k,a[N];
vector<pair<int,int>>now;//first= second=
signed main(){
	read(t);while(t--){
		read(n);
		now.clear();
		while(n--){
			read(k);
			int mn=-1;
			for(int i=1;i<=k;i++){
				//mn>=a[i]+1-(i-1)
				read(a[i]);
				chkmx(mn,a[i]+1-(i-1));
			}
			now.pb(mp(mn,k));
		}
		sort(now.begin(),now.end());
		int st=now.front().first,val=now.front().first;
		for(auto[mn,add]:now){
			if(val<mn)st+=mn-val,val=mn;
			val+=add;
		}
		write(st);putchar('\n');
	}
	return 0;
}