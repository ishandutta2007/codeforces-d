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
 
const int N=1000010,M=1<<21,NN=21;
//const int N=110,NN=4,M=1<<NN;
int n,h[N],ans;
pii a[M],F[M];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
 
void add(pii&a,pii b)
{
	if (b.x>a.x) a.x=b.x;
	if (a.x>a.y) swap(a.x,a.y);
	if (b.y>a.x) a.x=b.y;
	if (a.x>a.y) swap(a.x,a.y);
}
 
void pri(pair<int,int> a)
{
	cout<<a.x<<' '<<a.y<<en;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n;
	for (int i=0;i<M;++i) a[i]={-1,-1};
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		//h[i]=rand()%M;
		add(a[M-1-h[i]],{-1,i});
	}
	for(int i = 0; i<(1<<NN); ++i)
		F[i] = a[i];
	/*for (int i=0;i<M;++i)
	{
		cout<<F[M-i-1].x<<' '<<F[M-i-1].y<<en;
	}
	cout<<en;*/
	for(int i = 0;i < NN; ++i) for(int mask = 0; mask < (1<<NN); ++mask){
		if(mask & (1<<i))
			add(F[mask], F[mask^(1<<i)]);
	}
	for (int i=0;i<M;++i)
	{
		//cout<<F[M-i-1].x<<' '<<F[M-i-1].y<<en;
	}
	for (int k=M/2;k>=1;k/=2)
	{
		bool flag=0;
		int des=ans+k;
		for (int i=0;i<n-2;++i)
		{
			int an=des&(M-1-h[i]);
			if (F[M-1-an].x>=i) flag=1;
		}
		if (flag) ans+=k;
	}
	cout<<ans;
}