 #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;
#define ll long long
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (long long i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}
/*Author Ritick Goenka || ritick(codechef) ||ritick(codeforces) */
/*IIT Roorkee = <3 */
#define ull unsigned long long
#define ld long double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y0 yyyyyy0
auto clk=clock();
#define y1 yyyyyy1
#define setb __builtin_popcount
#define BIT(n) (1<<(n))
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define LSOne(S) (S) & (-S)
inline bool EQ(double a, double b) {return fabs(a - b) < 1e-9;}

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}
template<typename T> string toStr(T x) {stringstream st; st << x; string s; st >> s; return s;}
template<class T>
void splitStr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

inline int two(int n) {return 1 << n;}
inline int isOnBit(int n, int b) {return (n >> b) & 1;}
inline void onBit(int & n, int b) {n |= two(b);}
inline void offBit(int & n, int b) {n &= ~two(b);}
inline int lastBit(int n) {return n & (-n);}
inline int cntBit(int n) {int res = 0; while(n && ++res) n -= n &(-n); return res;}

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};

#define INP "test.inp"
#define OUT "test.out"

#define PI 3.1415926535897932385
#define INF 10000000000ll
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007ll
#define dec decr
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
ll modexp(ll x, ll y, ll p)
{
    ll res = 1;   
    x = x % p;  
    while (y > 0)
    {
        if (y %2==1)    
            res = (res*x) % p;
        y = y>>1;     
        x = (x*x) % p; 
    }
    return res;
}
vector<ll>v[300005];
vector<ll>v1[300005];
vector<pair<ll,ll>>br;
ll t=1;
ll tin[300005];
ll low[300005];
ll dsu[300005];
ll fpar(ll i)
{
    return (dsu[i]<0)?i:(dsu[i]=fpar(dsu[i]));
}
void merge(ll x,ll y)
{
    if((x=fpar(x))!=(y=fpar(y)))
    {
        if(dsu[x]>dsu[y])
        {
            swap(x,y);
        }
        dsu[x]+=dsu[y];
        dsu[y]=x;
    }
}
void dfs(ll x,ll p)
{
    tin[x]=t++;
    low[x]=tin[x];
    for(auto z:v[x])
    {
        if(z==p)
            continue;
        if(tin[z]>0)
        {
            low[x]=min(low[x],tin[z]);
        }
        else
        {
            dfs(z,x);
            low[x]=min(low[x],low[z]);
        }
        if(low[z]>tin[x])
        {
            br.pb(mp(z,x));
        }
        else
        {
            merge(z,x);
        }
    }
}
ll xx;
void build()
{
    for(auto x:br)
    {
        ll a=x.ff;
        ll b=x.ss;
        a=fpar(a);
        b=fpar(b);
        // debug(a);
        // debug(b);
        xx=a;
        v1[a].pb(b);
        v1[b].pb(a);
    }
}
ll mark[300006];
pair<ll,ll> dfs1(ll x)
{
    // debug(x);
    mark[x]=1;
    auto z=mp(0ll,x);
    for(auto y:v1[x])
    {
        // debug(y);
        // debug(mark[1]);
        if(mark[y]==0)
        {
            z=max(z,dfs1(y));
        }
    }
    z.ff++;
    return z;
}
int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(9);
     #ifdef rg
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    rep(i,300005)
    {
        dsu[i]=-1;
    }
    rep(i,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,-1);
    build();
    auto zz=dfs1(xx);
    rep(i,300005)
    {
        mark[i]=0;
    }
    // debug(zz.ss);
    zz=dfs1(zz.ss);
    cout<<zz.ff-1;



    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}