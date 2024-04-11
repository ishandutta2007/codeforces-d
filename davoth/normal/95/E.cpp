#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,M=2e7+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,sz[N],p[N],c[N],dp[N],ans;
vector<pll> vec;
ll gp(ll x){
    return p[x]?p[x]=gp(p[x]):x;
}
void uni(ll v, ll u){
    v=gp(v);
    u=gp(u);
    if(v!=u){
        p[u]=v;
        sz[v]+=sz[u];
    }
}
bool l(ll x){
    while(x){
        if(x%10!=4 && x%10!=7) return false;
        x/=10;
    }
    return true;
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) sz[i]=1;
    for(ll i=1; i<=m; i++){
        ll v,u;
        cin >> v >> u;
        uni(v,u);
    }
    for(ll i=1; i<=n; i++){
        if(!p[i]) c[sz[i]]++;
    }
    for(ll i=1; i<=n; i++){
        ll p=1;
        while(c[i]>=p){
            vec.pb({p*i,p});
            c[i]-=p;
            p*=2;
        }
        if(c[i]) vec.pb({c[i]*i,c[i]});
    }
    memset(dp,63,sizeof dp);
    dp[0]=0;
    for(auto [x,y] : vec){
        for(ll i=n; i>=x; i--){
            if(dp[i-x]+y<dp[i]) dp[i]=dp[i-x]+y;
        }
    }
    ans=n+1;
    for(ll i=1; i<=n; i++) if(l(i)) ans=min(ans,dp[i]);
    if(ans<=n) cout << ans-1 << '\n';
    else cout << -1 << '\n';
    return 0;
}