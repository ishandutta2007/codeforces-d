#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
typedef long long int ll;

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

int n;
bool fib[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	int a=1,b=1;
	fib[1]=1;
	for (;b<=5000;)
	{
		int c=b;
		b=a+b;
		a=c;
		fib[b]=1;
	}
	for (int i=0;i<n;++i)
	{
		if (fib[i+1]) cout<<'O';
		else cout<<'o';
	}
}