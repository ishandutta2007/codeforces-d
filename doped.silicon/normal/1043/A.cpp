#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ld long double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define PI 3.1415926535897932385
#define INF 1000000000000000
#define EPS 1e-7
#define MAXN 100000
#define MOD 998244353
#define dec decr
#define endl '\n'
auto clk=clock();
//END OF COMPETITVE PROGRAMMING TEMPLATE
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll modexp(ll x, ll y, ll p)
{
    ll res = 1;   
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}

signed main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(15);
        cout<<fixed;
        mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n;
        cin>>n;
        ll ar[n]; 
        ll mx=0;
        ll s=0;
        rep(i,n)
        {
            cin>>ar[i];
            mx=max(mx,ar[i]);
            s+=ar[i];
        }
        for(ll i=mx;;i++)
        {
            ll z=0;
            rep(j,n)
            {
                z+=i-ar[j];
            }
            if(z>s)
            {
                cout<<i<<endl;
                break;
            }
            // debug(i);
            // debug(z);
            // debug(s);
        }








}