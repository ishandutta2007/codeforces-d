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
#define MOD 1000000007
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
int mat[50][50];
bool check(ll x,ll y)
{
    if(x>=0&&x<=10&&y>=0&&y<=10)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
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
    // ll n;
    rep(i,10)
    {
        rep(j,10)
        {
            char x;
            cin>>x;
            if(x=='.')
            {
                // debug(i+1);
                // debug(j+1);
                mat[i+1][j+1]=0;
            }
            else if(x=='X')
            {
                mat[i+1][j+1]=1;
            }
            else
                mat[i+1][j+1]=-1;
        }
    }
    // cout<<"ds;f";
    for(ll i=1;i<=10;i++)
    {
        for(ll j=1;j<=10;j++)
        {
                // debug(i);
                // debug(j);
                // debug(mat[i][j]);
            if(mat[i][j]==0)
            {
                ll l=0,r=0,u=0,d=0,rd=0,ud=0,dd=0;
                ll x=i,y=j;
                x--;
                while(l+r<4&&check(x,y)&&mat[x][y]==1)
                {
                    l++;
                    x--;
                }
                x=i+1;
                while(l+r<4&&check(x,y)&&mat[x][y]==1)
                {
                    l++;
                    x++;
                }
                x=i;
                y--;
                while(u+d<4&&check(x,y)&&mat[x][y]==1)
                {
                    u++;
                    y--;
                }
                y=j;
                y++;
                while(u+d<4&&check(x,y)&&mat[x][y]==1)
                {
                    u++;
                    y++;
                }
                x=i-1,y=j-1;
                while(rd<4&&check(x,y)&&mat[x][y]==1)
                {
                    rd++;
                    y--;
                    x--;
                }
                x=i+1,y=j+1;
                while(rd<4&&check(x,y)&&mat[x][y]==1)
                {
                    rd++;
                    y++;
                    x++;
                }
                x=i+1,y=j-1;
                while(ud<4&&check(x,y)&&mat[x][y]==1)
                {
                    ud++;
                    y--;
                    x++;
                }
                x=i-1,y=j+1;
                while(ud<4&&check(x,y)&&mat[x][y]==1)
                {
                    ud++;
                    y++;
                    x--;
                }
                // if(i==1&&j==3)
                // {
                //     debug(l);
                //     debug(r);
                // }
                if(l>=4||ud>=4||u>=4||rd>=4)
                {
                    // debug(i);
                    // debug(j);
                    // debug(u);
                    cout<<"YES";
                    return 0;
                }

            }
            

        }
    }
    cout<<"NO";


    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}