// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=6e5+5;
int n,q,T,sum[N];
string s; 
vector<int> v[N];

inline void solve(int l,int r){cout<<*lb(v[(sum[r]-sum[l-1]+(sum[r]-sum[l-1]>0?1:-1))/2+sum[l-1]+n].begin(),v[(sum[r]-sum[l-1]+(sum[r]-sum[l-1]>0?1:-1))/2+sum[l-1]+n].end(),l)<<endl;}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>q>>s;s=" "+s;
		for(re i=0;i<=n*2;++i) v[i].clear();
		for(re i=1;i<=n;++i){
			if((i&1)&&s[i]=='+'||(i%2==0)&&s[i]=='-') sum[i]=sum[i-1]+1;
			else sum[i]=sum[i-1]-1;
			v[sum[i]+n].pb(i);
		}
		while(q--){
			int l,r;cin>>l>>r;
			if((r-l)%2==0) cout<<1<<endl,solve(l,r);
			else if(sum[r]-sum[l-1]==0) cout<<0<<endl;
			else cout<<2<<endl<<l<<' ',solve(l+1,r);
		}
	}
	return 0;
}

// ---------- Main ---------- //