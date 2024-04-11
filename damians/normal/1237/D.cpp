//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define un(x) x.erase(unique(ALL(x)),x.end())
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=1e9+7;//998244353;

#define M (1<<20)
int d[2*M];

void czysc()
{
    memset(d,0,sizeof(d));
}

void ustaw(int pos,int war)
{
    pos+=M;
    d[pos]=war;
    pos/=2;
    while(pos>0)
    {
        d[pos]=min(d[pos*2],d[pos*2+1]);
        pos/=2;
    }
}


int wezmin(int a,int b)
{
    int mx=(1<<30)-2;
    a+=M;
    b+=M;
    while(a<b)
    {
        if (a&1) mx=min(mx,d[a++]);
        if (!(b&1)) mx=min(mx,d[b--]);
        a>>=1;
        b>>=1;
    }
    if (a==b) mx=min(mx,d[a]);
    return mx;
}

int A[500000];
int g[500000];

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	FOR(i,n) {
		int x;cin>>x;
		A[i]=A[i+n]=A[i+2*n]=x;
	}
	FOR(i,3*n) ustaw(i,A[i]);
	FOR(i,3*n) {
		int lo=i,hi=3*n-1,mid;
		while(hi-lo>1) {
			mid=(hi+lo)/2;
			if (wezmin(lo,mid)*2<A[i]) hi=mid;
			else lo=mid;
		}
		g[i]=hi;
	}
	debug()<<range(g,g+3*n);
	czysc();
	FOR(i,3*n) ustaw(i,g[i]);
	FOR(i,n) {
		int lo=i,hi=3*n-1,mid;
		while(hi-lo>1) {
			mid=(hi+lo)/2;
			if (wezmin(i,mid-1)>mid) lo=mid;
			else hi=mid;
		}
		if (hi-i>2*n-1) cout<<-1<<"\n";
		else	cout<<hi-i<<"\n";
	}
	
	


    return 0;
}