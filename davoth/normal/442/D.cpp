#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e6+10,LN=20,M=1.1e7+10,SQ=350,B=737,inf=1e9;
const ll INF=1e18;
const int MH=1000696969,MOD=1000000007  /*998244353*/;
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
ll n,p[N],dp[N],m[2][N];
int main(){
    fast_io;
    cin >> n;
    for(ll i=2; i<=n+1; i++){
        ll t,v=i;
        cin >> t;
        p[i]=t;
        dp[i]=1;
        while(t){
            if(dp[m[0][t]]<dp[v]){
                m[1][t]=m[0][t];
                m[0][t]=v;
            }else if(dp[m[1][t]]<dp[v] && m[0][t]!=v){
                m[1][t]=v;
            }
            if(dp[t]!=max(dp[m[0][t]],dp[m[1][t]]+1)){
                dp[t]=max(dp[m[0][t]],dp[m[1][t]]+1);
            }else t=1;
            v=t;
            t=p[t];
        }
        cout << dp[m[0][1]] << ' ';
    }
    cout << '\n';
    return 0;
}