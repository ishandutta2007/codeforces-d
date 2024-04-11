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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

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
        vector<int> ty(n);
        for(int i=0;i<n;i++)
            cin >> ty[i];
        vector<vector<int> >  dp;
        dp.push_back(vector<int>(n+1));
        dp.push_back(vector<int>(n+1));
        for(int i=0;i<=n;i++)
            dp[0][i]=dp[1][i]=oo;
        dp[0][0]=0;
        for(int i=0;i<n;i++)
        {
            if(i+1<n)
            {
                dp[1][i+2]=min(dp[1][i+2],dp[0][i]+ty[i]+ty[i+1]);
                dp[0][i+2]=min(dp[0][i+2],dp[1][i]);
            }
            dp[1][i+1]=min(dp[1][i+1],dp[0][i]+ty[i]);
            dp[0][i+1]=min(dp[0][i+1],dp[1][i]);
        }

        db(min(dp[0][n],dp[1][n]))
    }

    return 0;
}