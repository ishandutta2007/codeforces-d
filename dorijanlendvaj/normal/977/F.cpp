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

int n;
int h[200001];
map<int,int> uz;
int l[200001];
int su[200001];
int mapi,man;
vector<int> sq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		uz[h[i]]=i+1;
		if (uz[h[i]-1])
		{
			l[i]=l[uz[h[i]-1]-1]+1;
			if (l[i]>man)
			{
				man=l[i];
				mapi=i;
			}
			su[i]=uz[h[i]-1];
		}
	}
	while (su[mapi])
	{
		sq.push_back(mapi);
		mapi=su[mapi]-1;
	}
	sq.push_back(mapi);
	reverse(sq.begin(),sq.end());
	cout<<sq.size()<<endl;
	for (int a: sq) cout<<a+1<<' ';
	cout<<endl;
}