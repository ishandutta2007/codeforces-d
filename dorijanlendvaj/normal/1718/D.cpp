//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcountll
#define all(a) begin(a),end(a)
//for kactl
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

template<class T>
vi compress(vector<T>&v)
{
	set<T> s;
	for (auto a: v) s.insert(a);
	vector<T> o(all(s));
	vi nv;
	for (int i=0;i<(int)v.size();++i) nv.pb(lower_bound(all(o),v[i])-o.begin());
	return nv;
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

void ad(int&a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}

void su(int&a,int b)
{
	a-=b;
	if (a<0) a+=MOD;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=1000010,M=1<<20;
int t,n,q,h[N],a[N],l[N],r[N],s[N];
bool imp[N];
vi lin[N];
pii seg1[M*2+10];
array<int,2> seg2[M*2+10];

void upd1(int i,int x)
{
	seg1[i+=M].x=x;
	for (i/=2;i;i/=2) seg1[i]=max(seg1[i*2],seg1[i*2+1]);
}

pii ge1(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg1[i];
	if (lo>=r || hi<=l) return {0,0};
	int mid=(lo+hi)/2;
	return max(ge1(l,r,lo,mid,i*2),ge1(l,r,mid,hi,i*2+1));
}

int rek(int lo,int hi,int mpr=N-5)
{
	if (lo==hi) return 0;
	pii re=ge1(lo,hi);
	int ind=re.y;
	int ma=a[ind],nmpr;
	if (a[ind]) nmpr=min(mpr,a[ind]);
	else nmpr=mpr;
	ma=max(ma,rek(lo,ind,nmpr));
	ma=max(ma,rek(ind+1,hi,nmpr));
	l[ind]=ma;
	r[ind]=nmpr;
	return ma;
}

array<int,2> mer(array<int,2> a,array<int,2> b)
{
	array<int,2> c;
	c[0]=a[0]+b[0];
	c[1]=min(b[1],b[0]+a[1]);
	return c;
}

void upd2(int i,int x)
{
	i+=M;
	seg2[i][0]+=x;
	seg2[i][1]+=x;
	for (i/=2;i;i/=2) seg2[i]=mer(seg2[i*2],seg2[i*2+1]);
}

int firm1()
{
	if (seg2[1][1]>=0) return -1;
	if (seg2[1][1]<=-2) return MOD;
	int i=1;
	array<int,2> vsuf={0,0};
	while (i<M)
	{
		array<int,2> ns=mer(seg2[i*2+1],vsuf);
		if (ns[1]>=0) i=i*2,vsuf=ns;
		else i=i*2+1;
	}
	return i-M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	for (int i=0;i<M;++i) seg1[i+M].y=i;
	cin>>t;
	while (t--)
	{
		cin>>n>>q;
		for (int i=0;i<n;++i) cin>>h[i],upd1(i,h[i]);
		set<int> va;
		va.insert(N-5);
		int k=0;
		for (int i=0;i<n;++i)
		{
			cin>>a[i];
			va.insert(a[i]);
			if (a[i]==0) ++k;
		}
		rek(0,n);
		for (int i=0;i<k-1;++i)
		{
			cin>>s[i];
			va.insert(s[i]);
		}
		for (auto x: va) lin[x].clear(),imp[x]=0;
		int mind=0,maxd=MOD;
		for (int i=0;i<n;++i)
		{
			if (l[i]>r[i]) mind=MOD,maxd=0;
			else if (a[i]==0) lin[r[i]].pb(l[i]);
			//cout<<i<<' '<<l[i]<<' '<<r[i]<<en;
		}
		for (int i=0;i<k-1;++i) imp[s[i]]=1;
		for (auto x: va)
		{
			if (imp[x]) upd2(x,1);
			for (auto y: lin[x]) upd2(y,-1);
			int rr=firm1();
			if (rr!=-1)
			{
				maxd=min(maxd,x);
				mind=max(mind,rr);
			}
		}
		for (auto x: va)
		{
			if (imp[x]) upd2(x,-1);
			for (auto y: lin[x]) upd2(y,1);
		}
		//cout<<mind<<' '<<maxd<<endl;
		for (int i=0;i<q;++i)
		{
			int d;
			cin>>d;
			if (d>=mind && d<=maxd) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}