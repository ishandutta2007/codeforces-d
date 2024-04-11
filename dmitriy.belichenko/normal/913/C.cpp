
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 2e5 + 5;
int MOD = 1e9 + 7;
ll sum(ll a , ll b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

ll mult( ll a , ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
bitset<30> t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n , l;
    cin >> n >> l ;
    ll ans = 1e18;
    ll ans2 = 0;
    vector<ll> c(n);
    for(int i = 0 ; i < n; i++) cin >> c[i];
    for(int i = 1; i < n; i++)
    {
        c[i] = min(c[i] , 2 * c[i - 1]);
    }
    
    for(int i = n - 1; i >= 0 ; i--)
    {
        int p = l / ( 1 << i);
        ans2 += c[i] * p;
        l -= (p << i);
       // cout << l << " ";
        ans = min(ans , ans2 + (l > 0) * c[i] );
    }
    cout << (long long)ans << "\n";
    return 0;
}