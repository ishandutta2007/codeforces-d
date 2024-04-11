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

const int N=1000010;
int t,n;
int a[N],b[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		string x;
		cin>>x;
		for (auto c: x) if (c=='B') ++a[i];
		else ++b[i];
	}
	int lo=0,hi=MOD;
	while (lo<hi)
	{
		int mid=(lo+hi)/2;
		int x1=0,y1=MOD,x2=0,y2=MOD,x3=-MOD,y3=MOD;
		for (int i=0;i<n;++i)
		{
			x1=max(x1,a[i]-mid);
			y1=min(y1,a[i]+mid);
			x2=max(x2,b[i]-mid);
			y2=min(y2,b[i]+mid);
			x3=max(x3,a[i]-b[i]-mid);
			y3=min(y3,a[i]-b[i]+mid);
		}
		bool ok=1;
		if (x1>y1) ok=0;
		if (x2>y2) ok=0;
		if (x3>y3) ok=0;
		int x4=x1-y2,y4=y1-x2;
		if (max(x4,x3)>min(y4,y3)) ok=0;
		//cout<<mid<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<endl;
		if (ok) hi=mid;
		else lo=mid+1;
	}
	cout<<lo<<en;
	int mid=lo;
	int x1=0,y1=MOD,x2=0,y2=MOD,x3=-MOD,y3=MOD;
	for (int i=0;i<n;++i)
	{
		x1=max(x1,a[i]-mid);
		y1=min(y1,a[i]+mid);
		x2=max(x2,b[i]-mid);
		y2=min(y2,b[i]+mid);
		x3=max(x3,a[i]-b[i]-mid);
		y3=min(y3,a[i]-b[i]+mid);
	}
	
	//koristi x1
	//cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<endl;
	for (int i=x2;i<=y2;++i)
	{
		if (x1-i>=x3 && x1-i<=y3)
		{
			if (x1+i==0)
			{
				assert(y1>=1);
				assert(y2>=1);
				++x1;
				++i;
			}
			for (int j=0;j<x1;++j) cout<<'B';
			for (int j=0;j<i;++j) cout<<'N';
			exit(0);
		}
	}
	//koristi x2
	for (int i=x1;i<=y1;++i)
	{
		if (i-x2>=x3 && i-x2<=y3 && x2+i>0)
		{
			if (x2+i==0)
			{
				assert(y1>=1);
				assert(y2>=1);
				++x2;
				++i;
			}
			for (int j=0;j<i;++j) cout<<'B';
			for (int j=0;j<x2;++j) cout<<'N';
			exit(0);
		}
	}
	assert(0);
}