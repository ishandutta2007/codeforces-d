//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<int,int> pii;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int xa,ya;
        cin>> xa >> ya;
        int xb,yb;
        cin>> xb >> yb;
        int xf,yf;
        cin>> xf >> yf;
        if(xa!=xb && ya!=yb)
        {
            db(abs(xa-xb)+abs(ya-yb))
            continue;
        }
        if(xa==xb)
        {
            if(xf==xa && max(ya,yb)>=yf && min(ya,yb)<=yf)
                db(abs(xa-xb)+abs(ya-yb)+2)
            else
                db(abs(xa-xb)+abs(ya-yb))
            continue;
        }
        if(yf==ya && max(xa,xb)>=xf && min(xa,xb)<=xf)
            db(abs(xa-xb)+abs(ya-yb)+2)
        else
            db(abs(xa-xb)+abs(ya-yb))
        continue;
    }


    return 0;
}