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

int x[100000],y[100000];
vi adjList[200000];
int visited[200000],c = 0,e;
int doDFS(int u) {
    if (visited[u]) return 0;
    int i;
    visited[u] = 1,c++;
    for (i = 0; i < adjList[u].size(); i++) {
        e++;
        if (!visited[adjList[u][i]]) doDFS(adjList[u][i]);
    }
    return 0;
}
int main() {
    int i;
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) scanf("%d %d",&x[i],&y[i]),x[i]--,y[i]--;

        for (i = 0; i < m; i++) {
            if (x[i] != y[i]) {
                adjList[x[i]].pb(y[i]+n);
                adjList[y[i]+n].pb(x[i]);
            }
        }
        for (i = 0; i < n; i++) {
            adjList[i].pb(i+n);
            adjList[i+n].pb(i);
        }
        int ans = 0;
        for (i = 0; i < 2*n; i++) {
            if (!visited[i]) {
                c = e = 0,doDFS(i),e /= 2;
                if (c == e) ans += c/2+1;
                else ans += e/2;
            }
        }
        printf("%d\n",ans);

        for (i = 0; i < 2*n; i++) adjList[i].clear(),visited[i] = 0;
    }

    return 0;
}