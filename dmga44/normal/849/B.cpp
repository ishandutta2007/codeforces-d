#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    ll dy1=a[1]-a[0];
    ll dy3=a[2]-a[1];

    bool res=0;
    for(auto dy : {dy1,dy3})
    {
        set<ll> d0;
        for(int i=0;i<n;i++)
            d0.insert(a[i]-i*dy);
        if(d0.size()==2)
            res=1;
    }
    ll dy=a[2]-a[0];
    set<ll> d0;
    for(ll i=0;i<n;i++)
        d0.insert(2*a[i]-i*dy);
    if(d0.size()==2)
        res=1;
    if(res)
        db("Yes")
    else
        db("No")

    return 0;
}