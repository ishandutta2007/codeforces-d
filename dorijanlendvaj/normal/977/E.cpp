/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
typedef long long int ll;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}

ll raand()
{
   return rand()*RAND_MAX+rand();
}

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<a.size();++i)
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

int gcd(int a,int b)
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

int n,m;
int a,b;
bool x;
vector<int> ch[200001];
bool bio[200001];
int cc;

void dfs(int i)
{
	if (bio[i]) return;
	bio[i]=1;
	if (ch[i].size()!=2) return;
	if (!bio[ch[i][0]])
	{
		bool e=bio[ch[i][1]];
		dfs(ch[i][0]);
		if (!e && bio[ch[i][1]] && ch[ch[i][1]].size()==2) x=1;
	}
	else if (!bio[ch[i][1]])
	{
		dfs(ch[i][1]);
	}
	else return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=0;i<m;++i)
	{
		cin>>a>>b;
		--a;
		--b;
		ch[a].push_back(b);
		ch[b].push_back(a);
	}
	for (int i=0;i<n;++i)
	{
		if (ch[i].size()!=2) continue;
		x=0;
		if (!bio[i]) dfs(i);
		if (x)
		{
			++cc;
			//cout<<i<<' ';
		}
	}
	cout<<cc;
}