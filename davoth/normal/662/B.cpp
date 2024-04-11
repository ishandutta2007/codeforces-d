#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=18,M=1.1e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const int MH=1000696969,MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
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
ll n,m,f,fl[N],g;
vector<pll> adj[N];
vector<ll> comp[2],ans,ap;
void dfs(ll v, ll c){
    comp[fl[v]-1].pb(v);
    for(auto [u,w] : adj[v]){
        if(w==c){
            if(fl[u]==3-fl[v]){
                f=1;
                return;
            }
            if(!fl[u]) fl[u]=fl[v],dfs(u,c);
        }else{
            if(fl[u]==fl[v]){
                f=1;
                return;
            }
            if(!fl[u]) fl[u]=3-fl[v],dfs(u,c);
        }
    }
}
int main(){
    fast_io;
    cin >> n >> m;
    for(ll i=1; i<=m; i++){
        ll v,u,c=0;
        char t;
        cin >> v >> u >> t;
        if(t=='R') c=1;
        adj[v].pb({u,c});
        adj[u].pb({v,c});
    }
    for(ll i=1; i<=n; i++){
        if(!fl[i]){
            fl[i]=1;
            dfs(i,0);
            if(comp[0].size()<comp[1].size()) for(ll v : comp[0]) ap.pb(v);
            else for(ll v : comp[1]) ap.pb(v);
            comp[0]=comp[1]={};
        }
    }
    g=f;
    f=0;
    memset(fl,0,sizeof fl);
    for(ll i=1; i<=n; i++){
        if(!fl[i]){
            fl[i]=1;
            dfs(i,1);
            if(comp[0].size()<comp[1].size()) for(ll v : comp[0]) ans.pb(v);
            else for(ll v : comp[1]) ans.pb(v);
            comp[0]=comp[1]={};
        }
    }
    if(g && f) cout << -1 << '\n';
    else if(g || (!f && ans.size()<=ap.size())){
        cout << ans.size() << '\n';
        for(ll v : ans) cout << v << ' ';
        cout << '\n';
    }else{
        cout << ap.size() << '\n';
        for(ll v : ap) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}