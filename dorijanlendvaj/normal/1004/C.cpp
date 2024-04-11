/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=1000000007;
const int MOD2=998244353;
const int BASE1=292375;
const int BASE2=187641;
const int BASE3=872149;
const int BASE4=127819;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}

ll raand()
{
	ll a=rand();
	a*=RAND_MAX;
	a+=rand();
    return a%(MOD-7);
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

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

ll mult(ll a,ll b)
{
	return (a*b)%MOD;
}

ll pot(ll n,ll k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

ll divide(ll a,ll b)
{
	return mult(a,pot(b,MOD-2));
}

ll sub(ll a,ll b)
{
	return (a-b+MOD)%MOD;
}

ll add(ll a,ll b)
{
	return (a+b)%MOD;
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

pair<int,int> has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (auto a: x)
	{
		h1*=BASE1;
		h1+=a-'a';
		h1%=MOD;
		h2*=BASE2;
		h2+=a-'a';
		h2%=MOD2;
	}
	return {h1,h2};
}

const int N=300010;
int n,h[N];
ll rj;
set<pair<int,int> > mu;
bool bio[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void add1(int i)
{
	auto it=mu.lower_bound({i,0});
	if (it==mu.end() || it->first!=i) mu.insert({i,1});
	else
	{
		int os=it->second;
		mu.erase(it);
		mu.insert({i,os+1});
	}
}

void remove1(int i)
{
	auto it=mu.lower_bound({i,0});
	if (it->second==1) mu.erase(it);
	else
	{
		int os=it->second;
		mu.erase(it);
		mu.insert({i,os-1});
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=1;i<n;++i) add1(h[i]);
	for (int i=0;i<n-1;++i)
	{
		if (bio[h[i]])
		{
			remove1(h[i+1]);
			continue;
		}
		bio[h[i]]=1;
		rj+=mu.size();
		//cout<<mu.size()<<' ';
		remove1(h[i+1]);
	}
	cout/*<<endl*/<<rj;
}