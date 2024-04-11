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
string h[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (h[i][j]=='S')
	{
		if (i)
		{
			if (h[i-1][j]=='W')
			{
				cout<<"No"<<endl;
				return 0;
			}
			else if (h[i-1][j]=='.') h[i-1][j]='D';
		}
		if (i<n-1)
		{
			if (h[i+1][j]=='W')
			{
				cout<<"No"<<endl;
				return 0;
			}
			else if (h[i+1][j]=='.') h[i+1][j]='D';
		}
		if (j)
		{
			if (h[i][j-1]=='W')
			{
				cout<<"No"<<endl;
				return 0;
			}
			else if (h[i][j-1]=='.') h[i][j-1]='D';
		}
		if (j<m-1)
		{
			if (h[i][j+1]=='W')
			{
				cout<<"No"<<endl;
				return 0;
			}
			else if (h[i][j+1]=='.') h[i][j+1]='D';
		}
	}
	cout<<"Yes"<<endl;
	for (int i=0;i<n;++i) cout<<h[i]<<endl;
}