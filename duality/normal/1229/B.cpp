#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------
#define MOD 1000000007

LLI x[100000];
vi adjList[100000];
LLI gcd(LLI a,LLI b) {
    LLI t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
LLI ans = 0;
int doDFS(int u,int p,vplli path) {
    int i;
    path.pb(mp(0,1));
    for (i = 0; i < path.size(); i++) path[i].first = gcd(path[i].first,x[u]),ans += path[i].second*path[i].first,ans %= MOD;
    sort(path.begin(),path.end());
    vplli path2;
    for (i = 0; i < path.size(); i++) {
        if (path2.empty() || (path[i].first != path2.back().first)) path2.pb(path[i]);
        else path2.back().second += path[i].second;
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,path2);
    }
    return 0;
}
int main() {
    int i;
    int n,a,b;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d",&x[i]);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    vplli p;
    doDFS(0,-1,p);
    printf("%I64d\n",ans);

    return 0;
}