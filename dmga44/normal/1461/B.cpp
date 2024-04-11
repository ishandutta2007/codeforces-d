//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e2+5)

string s[MAXN];
int ma[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> s[i];
        int res=0;
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='.')
                    ma[i][j]=0;
                else if(i==n-1)
                    ma[i][j]=1;
                else
                {
                    if(!j || j==m-1)
                        ma[i][j]=1;
                    else
                        ma[i][j]=1+min(ma[i+1][j],min(ma[i+1][j-1],ma[i+1][j+1]));
                }
                res+=ma[i][j];
            }
        db(res)
    }

    return 0;
}