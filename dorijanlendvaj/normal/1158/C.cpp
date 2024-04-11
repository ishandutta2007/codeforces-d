#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

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

ll has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (char a: x)
	{
		h1*=bases[0];
		h1+=a-'a';
		h1%=bases[3];
		h2*=bases[1];
		h2+=a-'a';
		h2%=bases[4];
	}
	return h1*(MOD+13893829)+h2;
}

const int N=500010;
int t,n,h[N],a[N],k[N];
vector<int> c[N],mi1;
set<int> aa;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back((rand()%MOD+13893829)%MOD);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n+1;++i) c[i].clear();
		mi1.clear();
		for (int i=1;i<=n;++i)
		{
			int a;
			cin>>a;
			if (a==-1)
			{
				if (i==1) a=n+1;
				else if (k[i-1]==i) a=i+1;
				else a=k[i-1];
			}
			k[i]=a;
			{
				c[a].pb(i);
			}
		}
		aa.clear();
		for (auto a: c[n+1]) aa.insert(a);
		for (auto a: mi1) aa.insert(a);
		for (int j=n;j>=1;--j)
		{
			int po=*aa.begin();
			aa.erase(aa.begin());
			h[po]=j;
			for (auto a: c[po]) aa.insert(a);
		}
		stack<pii> s;
		for (int i=1;i<=n;++i)
		{
			while (s.size() && s.top().x<h[i])
			{
				a[s.top().y]=i;
				s.pop();
			}
			s.push({h[i],i});
		}
		while (s.size())
		{
			a[s.top().y]=n+1;
			s.pop();
		}
		bool flag=1;
		for (int i=1;i<=n;++i) if (a[i]!=k[i] && k[i]!=-1)
		{
			cout<<-1<<en;
			//for (int i=1;i<=n;++i) cout<<h[i]<<' ';
			//cout<<en<<en;
			flag=0;
			break;
		}
		if (flag)
		{
			for (int i=1;i<=n;++i) cout<<h[i]<<' ';
			cout<<en;
			//cout<<en;
		}
		/*for (int i=1;i<=n;++i)
		{
			int a;
			cin>>a;
			if (a>0) h[i]=a-1;
			else
			{
				if (i==1) h[i]=1;
				else if (i==n) h[i]=n;
				else
				{
					if (h[i-1]==i-1) h[i]=i;
					else h[i]=h[i-1];
				}
			}
		}
		bool flag=1;
		for (int i=1;i<=n;++i)
		{
			if (h[i]!=i)
			{
				if (h[i+1]!=h[i])
				{
					cout<<-1<<en;
					flag=0;
					break;
				}
			}
		}
		if (flag)
		{
			for (int i=1;i<=n;++i)
			{
				if (h[i]==h[i-1]) a[i]=a[i-1]-1;
				else a[i]=h[i];
				cout<<a[i]<<' ';
			}
			cout<<en;
		}*/
	}
}