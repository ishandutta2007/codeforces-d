#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=1e5+10,LN=20,SQ=550,M=5e4+10;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<pll,ll>, null_type,less<pair<pll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,q,c[26];
string s,t;
int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n >> s;
        memset(c,0,sizeof c);
        for(char i : s) c[i-'a']++;
        t="";
        for(ll i=0; i<26; i++) while(c[i]){
            t+='a'+i;
            c[i]--;
        }
        cout << t << '\n';
    }
    return 0;
}