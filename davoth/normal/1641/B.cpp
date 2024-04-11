/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<double>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!")
#define killmashtali kill("Hello, World!")
const int N=5e2+10,LN=20,M=1e5+10,SQ=500,BS=737,inf=1.05e9,NSQ=N/SQ+1;
const ll INF=1e18;
const double pi=acos(-1);
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pii, null_type,greater<pii>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll t,n,a[N*N*4],L;
vector<pll> qu;
vector<ll> ans;
void solve(){
    ll r;
    for(ll i=2; i<=n; i++){
        if(a[i]==a[1]){
            r=i;
            break;
        }
    }
    for(ll i=2; i<r; i++){
        qu.pb({L+r+i-2,a[i]});
    }
    L+=(r-1)*2;
    ans.pb((r-1)*2);
    reverse(a+2,a+r);
    for(ll i=r+1; i<=n; i++) a[i-1]=a[i];
    for(ll i=2; i<n; i++) a[i-1]=a[i];
    n-=2;
}
int main(){
    fast_io;
    cin >> t;
    while(t--){
        cin >> n;
        map<ll,ll> p;
        qu.clear();
        ans.clear();
        L=0;
        for(ll i=1; i<=n; i++){
            cin >> a[i];
            p[a[i]]++;
        }
        ll f=0;
        for(ll i=1; i<=n; i++){
            if(p[a[i]]&1) f=1;
        }
        if(f){
            cout << -1 << '\n';
            continue;
        }
        while(n) solve();
        cout << qu.size() << '\n';
        for(auto [x,y] : qu) cout << x << ' ' << y << '\n';
        cout << ans.size() << '\n';
        for(ll i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}