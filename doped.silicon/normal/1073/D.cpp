#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ll long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second





#define PI 3.1415926535897932385
#define INF 1000000000000000
#define EPS 1e-7
// #define MAXN 100000
#define MOD 1000000007
#define dec decr
// ll ans[10000000];
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(2);
        cout<<fixed;
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        set<ll>s,s1;
        ll n,t;
        cin>>n>>t;
        ll sum=0;
        ll x=n;
        ll ar[n];
        ll ans=0;
        rep(i,n)
        {
            s.insert(i);
            cin>>ar[i];
            sum+=ar[i];
        }
        while(x!=0)
        {
            ll z=(t/sum)*x;
            ll k=t/sum;
            ans+=z;
            t-=k*sum;
            // debug(x);
            // debug(t);
            // debug(sum);
            // debug(ans);
            for(auto i:s)
            {
                if(ar[i]<=t)
                {
                    t-=ar[i];
                    s1.insert(i);
                    ans++;
                }
                else
                {
                    sum-=ar[i];
                    x--;
                }
            }
            s.clear();
            s=s1;
            s1.clear();
        }
        cout<<ans;

            return 0;
}