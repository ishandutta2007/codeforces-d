// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef int ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
// #define MOD 2000000000000000000ll
#define MOD 1000000007
#define EPS 1e-7
// #define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()
#define sz(x) (int)x.size();

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef bhartiya
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }






ll cur=0;

pair<ll,ll> find(ll x,ll y)
{
    if(x==y)
    {
        return {x+1,y+1};
    }
    return {x,y+1};
}
vector<ll>g[200005];
pair<ll,ll> dfs(ll x,ll p)
{
    vector<pair<ll,ll>>v;
    for(auto z:g[x])
    {
        if(z!=p)
        {
            auto xz=dfs(z,x);
            v.pb(find(xz.ff,xz.ss));
        }
    }
    if(v.size()==0)
    {
        return {0,0};
    }
    else if(v.size()==1)
    {
        return v[0];
    }
    else
    {
        sort(all(v));
        reverse(all(v));
        ll mn=1000000;
        for(auto z:v)
        {
            mn=min(mn,z.ss);
        }
        if(v[0].ff==v[0].ss)
        {
            if(v[1]==v[0])
            {
                if(v[0].ss<cur)
                {
                    return {v[0].ff,mn};
                }
                else
                {
                    return {v[0].ff+1,v[0].ss};
                }
            }
            else
            {
                if(v[0].ss<cur)
                {
                    return {v[0].ff,mn};
                }
                else
                {
                    return v[0];
                }
            }
        }
        else
        {
            
            return {v[0].ff,mn};
        }
    }
}

void solve()
{   
    ll n;
    cin>>n;
    rep(i,n+5)
    {
        g[i].clear();
    }
    rep(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    ll l=1,r=n-1;
    // ll l=3,r=3;
    ll ans=r;
    while(l<=r)
    {
        ll m=(l+r)/2;
        cur=m;
        ll han=1;
        auto z=dfs(1,1);

        if(z.ff<=m)
        {
            ans=m;
            r=m-1;
        }
        else
        {
            l=m+1;
        }

    }
    cout<<ans<<endl;

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}