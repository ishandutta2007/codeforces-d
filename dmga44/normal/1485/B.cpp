#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q,k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        int dp=(r-l+1);
        l=a[l];
        r=a[r];
        db(l-1+(k-r)+2*(r-l+1-dp))
    }

    return 0;
}