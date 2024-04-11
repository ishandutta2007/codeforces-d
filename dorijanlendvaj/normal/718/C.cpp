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

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
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
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<endl;
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

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=10;
		k+=a[i]-'0';
	}
	return k;
}

string its(ll k)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%10)+'0');
		k/=10;
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

const int N=100010,M=1<<17;
int n,q;
array<int,4> coll[N];
bool che;

array<int,4> mu(array<int,4> a,array<int,4> b)
{
	return {(a[0]*1ll*b[0]+a[1]*1ll*b[2])%MOD,
	(a[0]*1ll*b[1]+a[1]*1ll*b[3])%MOD,
	(a[2]*1ll*b[0]+a[3]*1ll*b[2])%MOD,
	(a[2]*1ll*b[1]+a[3]*1ll*b[3])%MOD};
}

array<int,4> ad(array<int,4> a,array<int,4> b)
{
	return {add(a[0],b[0]),add(a[1],b[1]),add(a[2],b[2]),add(a[3],b[3])};
}

array<int,4> ex(ll po)
{
	if (po==0) return {1,0,0,1};
	if (che && po<N) return coll[po];
	auto res=ex(po/2);
	auto r=mu(res,res);
	if (po%2) return mu(r,{1,1,1,0});
	else return r;
}

array<int,4> seg[M*2+10];
array<int,4> pro[M*2+10];
array<int,4> wat;

void pr(int i)
{
	if (pro[i][1]==0) return;
	seg[i]=mu(seg[i],pro[i]);
	if (i<M)
	{
		pro[i*2]=mu(pro[i*2],pro[i]);
		pro[i*2+1]=mu(pro[i*2+1],pro[i]);
	}
	pro[i]={1,0,0,1};
}

void upd(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r)
	{
		pro[i]=mu(pro[i],wat);
		pr(i);
		return;
	}
	pr(i);
	if (lo>=r || hi<=l) return;
	int mid=(lo+hi)/2;
	upd(l,r,lo,mid,i*2);
	upd(l,r,mid,hi,i*2+1);
	seg[i]=ad(seg[i*2],seg[i*2+1]);
}

int get(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=r || hi<=l) return 0;
	pr(i);
	if (lo>=l && hi<=r) return seg[i][0];
	int mid=(lo+hi)/2;
	return add(get(l,r,lo,mid,i*2),get(l,r,mid,hi,i*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for (int i=0;i<N;++i) coll[i]=ex(i);
	che=1;
	for (int i=0;i<n;++i)
	{
		int a;
		cin>>a;
		seg[i+M]=ex(a-1);
	}
	for (int i=0;i<M*2;++i) pro[i]={1,0,0,1};
	for (int i=M-1;i>0;--i) seg[i]=ad(seg[i*2],seg[i*2+1]);
	while (q--)
	{
		int t,l,r;
		cin>>t>>l>>r;
		--l;
		if (t==1)
		{
			int x;
			cin>>x;
			wat=ex(x);
			upd(l,r);
		}
		else
		{
			cout<<get(l,r)<<en;
		}
	}
}