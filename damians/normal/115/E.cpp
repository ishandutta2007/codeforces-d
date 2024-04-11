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

#define INF (1LL<<60)
#define M (1<<18)

struct elem {//element of a monoid M
	ll mx;
	elem(ll _mx=-INF){mx=_mx;}
	//friend ostream& operator<<(ostream& os, const elem& a) { os<<1;return os; }
};


struct oper {//element of set F of operations
	ll v;
	oper(ll _v=0){v=_v;}
};

elem neutral_elem() {
	return elem();
}

oper neutral_oper() {
	return oper();
}

elem combine_elems(const elem& a,const elem& b) {
	return elem(max(a.mx,b.mx));
}

oper combine_opers(const oper& frst, const oper& sec) {
	//sec is the oper in parent node (higher), frst is child (deeper)
	return oper(frst.v+sec.v);
}
 
elem d[2*M];
oper daux[2*M];

bool apply_oper_to_elem(const oper& f,elem& a) {
	a.mx+=f.v;
	return true;
}

void recalc_node(int l,int r,int k,bool aux_only=0) {
	if (l<r && !aux_only) d[k]=combine_elems(d[2*k],d[2*k+1]);
	apply_oper_to_elem(daux[k],d[k]);
	if (l==r) daux[k]=neutral_oper();
}
	
	
bool apply_if_possible(int l,int r,int k,const oper& f) {
	if (apply_oper_to_elem(f,d[k])) {
		daux[k]=f;
		if (l==r) daux[k]=neutral_oper();
		return true;
	} 
	return false;
}
	

void combine_aux_from_parent(int l,int r,int pl, int pr,int k) {
	int pk=k/2;
	daux[k]=combine_opers(daux[k], daux[pk]);
	recalc_node(l,r,k);
}

void pushdown_aux(int l,int r,int k) {
	//possible optimization: return if daux[k] is neutral oper
	if (daux[k].v==0) return;
	assert(l<r);
	combine_aux_from_parent(l,(l+r)/2,l,r,k*2);
	combine_aux_from_parent((l+r)/2+1,r,l,r,k*2+1);
	daux[k]=neutral_oper();
}
	
	

void modify(int li,int ri,const oper& f,int l=0,int r=M-1,int k=1) {
	if (r<li || ri<l) return;
	if (l<r) pushdown_aux(l,r,k);
	if (li<=l && r<=ri && apply_if_possible(l,r,k,f)) return;
	//the operations in recursive calls might be different ->f_left, f_right
	modify(li,ri,f,l,(l+r)/2,k*2);
	modify(li,ri,f,(l+r)/2+1, r, k*2+1);
	recalc_node(l,r,k);
}

void set_elem(int pos,elem a,int l=0,int r=M-1,int k=1) {
	if (l<r) pushdown_aux(l,r,k);
	else { //l==r==pos
		d[k]=a;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) set_elem(pos,a,l,mid,k*2);
	else set_elem(pos,a,mid+1,r,k*2+1);
	recalc_node(l,r,k);
}


elem query(int li,int ri,int l=0,int r=M-1,int k=1) {
	if (r<li || ri<l) return neutral_elem();
	if (li<=l && r<=ri) return d[k];
	pushdown_aux(l,r,k);
	return combine_elems(query(li,ri,l,(l+r)/2,k*2),query(li,ri,(l+r)/2+1,r,k*2+1));
}

int cost[1<<18];
vector<pii> races[1<<18];
	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n,m;cin>>n>>m;
	FOR(i,n) cin>>cost[i];
	FOR(i,m) {
		int a,b,v;
		cin>>a>>b>>v;a--;b--;
		races[b].pb({a,v});
	}
	set_elem(n,elem(0));
	int start=n;
	FOR(k,n) {
		ll best=query(start,start+k).mx;
		//debug()<<imie(best);
		start--;
		set_elem(start,elem(best));
		modify(start+1,start+1+k,oper((-1)*cost[k]));
		for (auto race: races[k]) {
			//debug()<<imie(k)<<imie(race);
			modify(start+1+k-race.st, start+1+k, oper(race.nd));
		}
	}
	cout<<d[1].mx<<endl;
	
	//initialize all in linear time
	//REPD(i,M-1,1) d[i]=combine_elems(d[2*i],d[2*i+1]);



    return 0;
}