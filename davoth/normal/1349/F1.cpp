#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e3+10,LN=20,M=5e4+10,SQ=250,inf=1e9;
const ll INF=1e18;
const int MOD=/*1000000007*/ 998244353;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,dp[N][N],ans[N],f[N],iv[N];
int main(){
    fast_io;
    cin >> n;
    dp[0][0]=iv[0]=f[0]=1;
    for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD,iv[i]=pow(f[i],MOD-2,MOD);
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=i; j++){
            dp[i][j]=(j*dp[i-1][j]+(i-j+1)*dp[i-1][j-1])%MOD;
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            ans[i]=(ans[i]+dp[j][i]*iv[j])%MOD;
        }
        ans[i]=ans[i]*f[n]%MOD;
    }
    for(ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}