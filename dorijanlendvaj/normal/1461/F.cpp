//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define all(a) begin(a),end(a)

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

void compress(vi&v)
{
	set<int> s;
	for (auto a: v) s.insert(a);
	vi o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
}

void compress(vl&v)
{
	set<ll> s;
	for (auto a: v) s.insert(a);
	vl o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
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
const int N=300010;
int t,n,h[N];
string s;

void solve(vi v)
{
	int st=0;
	int sz=v.size();
	while (st<sz && v[st]==1) ++st;
	for (int i=0;i<st;++i)
	{
		cout<<v[i];
		if (i<sz-1) cout<<'+';
	}
	if (st==sz) return;
	int kr=sz-1;
	while (v[kr]==1) --kr;
	ll pr=1;
	for (auto a: v)
	{
		pr*=a;
		if (pr>=5*sz+15)
		{
			for (int i=st;i<=kr;++i)
			{
				cout<<v[i];
				if (i<kr) cout<<'*';
			}
			for (int i=kr+1;i<sz;++i) cout<<"+1";
			return;
		}
	}
	vector<pii> v1;
	pr=1;
	int c22=0;
	for (int i=st;i<=kr;++i)
	{
		if (v[i]==1)
		{
			v1.eb(pr,c22);
			pr=1;
			c22=1;
		}
		else
		{
			if (pr==1 && i>st) v1.eb(pr,c22),c22=0;
			pr*=v[i];
			++c22;
		}
	}
	ll la=pr;
	int cn=0;
	pii lp={-1,-1};
	vector<pair<pii,int>> v2;
	for (auto a: v1)
	{
		if (a.x==1) ++cn;
		else
		{
			if (cn)
			{
				assert(lp!=mp(-1,-1));
				v2.eb(lp,cn);
				cn=0;
			}
			lp=a;
		}
	}
	if (cn) v2.eb(lp,cn);
	/*for (auto a: v2) cout<<a.x.x<<' '<<a.x.y<<' '<<a.y<<en;
	cout<<la<<' '<<c22<<en;*/
	reverse(all(v2));
	int kak=-1,ma=0;
	for (int b=0;b<(1<<((int)v2.size()));++b)
	{
		ll cu=la,s=0;
		for (int i=0;i<(int)v2.size();++i)
		{
			if (b&(1<<i))
			{
				cu*=v2[i].x.x;
			}
			else
			{
				s+=cu;
				s+=v2[i].y;
				cu=v2[i].x.x;
			}
		}
		s+=cu;
		if (s>ma)
		{
			ma=s;
			kak=b;
		}
	}
	string s;
	for (int i=0;i<c22-1;++i) s.pb('*');
	for (int i=0;i<(int)v2.size();++i)
	{
		for (int j=0;j<=v2[i].y;++j) if (kak&(1<<i)) s.pb('*');
		else s.pb('+');
		for (int j=0;j<v2[i].x.y-1;++j) s.pb('*');
	}
	reverse(all(s));
	cout<<v[st];
	for (int i=st+1;i<=kr;++i)
	{
		cout<<s[i-st-1]<<v[i];
	}
	for (int i=kr+1;i<sz;++i) cout<<"+1";
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	cin>>s;
	sort(all(s));
	if (s.size()==1 || s=="+-")
	{
		for (int i=0;i<n-1;++i) cout<<h[i]<<s[0];
		cout<<h[n-1]<<en;
		exit(0);
	}
	if (s=="*-")
	{
		int p0=n;
		for (int i=n-1;i>=0;--i) if (h[i]==0) p0=i;
		for (int i=1;i<n;++i)
		{
			cout<<h[i-1];
			if (i==p0) cout<<'-';
			else cout<<'*';
		}
		cout<<h[n-1]<<en;
		exit(0);
	}
	vi v;
	for (int i=0;i<n;++i)
	{
		if (h[i]==0)
		{
			if (v.size()) solve(v),v.clear();
			if (i && h[i-1]) cout<<'+';
			cout<<0;
			if (i<n-1) cout<<'+';
		}
		else v.pb(h[i]);
	}
	if (v.size()) solve(v);
}