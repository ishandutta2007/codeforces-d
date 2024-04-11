#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(3e1+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> ks(k);
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<k;i++)
            cin >> ks[i];

        sort(all(a));
        sort(allr(ks));

        ll res=0;
        int pos=0;
        for(int i=0;i<k;i++)
        {
            res+=a[n-k+i];
            if(ks[i]==1)
                res+=a[n-k+i];
            else
            {
                res+=a[pos];
                pos+=(ks[i]-1);
            }
        }
        db(res)
    }

    return 0;
}