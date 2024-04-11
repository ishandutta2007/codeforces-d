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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int kk;
        for(int i=2;i<n;i++)
        {
            int v=n;
            int u=i;
            int cont=0;
            while(u!=1)
            {
                cont++;
                v=((v-1)/u)+1;
                if(v<=u)
                    swap(u,v);
            }
            if(v==2 && cont<=8)
            {
                kk=i;
                break;
            }
        }

        vector<pii> res;
        for(int i=2;i<n;i++)
            if(i!=kk)
                res.push_back(pii(i,n));

        int v=n;
        int u=kk;
        int pv=n;
        int pu=kk;
        while(u!=1)
        {
            res.push_back(pii(pv,pu));
            v=((v-1)/u)+1;
            if(v<=u)
            {
                swap(u,v);
                swap(pu,pv);
            }
        }
        db(res.size())
        for(auto p : res)
            cout << p.f << ' ' << p.s << '\n';
    }

    return 0;
}