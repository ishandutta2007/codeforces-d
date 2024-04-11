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

vi sol,sol2,ans;
int main() {
    int u,v,p;
    cin >> u >> v >> p;

    int fu = 0,fv = 0;
    if (u == 0) fu = 1,u = 1;
    if (v == 0) fv = 1,v = 1;

    int i;
    mt19937 gen;
    uniform_int_distribution<int> dist(1,p-1);
    while (1) {
        int b = dist(gen),a = ((LLI) u*b) % p;
        while (1) {
            if (a == b) break;
            else if (a > b) sol.pb(2),a -= b;
            else sol.pb(3),swap(a,b);
            if (sol.size() > 99) break;
        }
        if (sol.size() < 99) break;
        else sol.clear();
    }
    while (1) {
        int b = dist(gen),a = ((LLI) v*b) % p;
        while (1) {
            if (a == b) break;
            else if (a > b) sol2.pb(1),a -= b;
            else sol2.pb(3),swap(a,b);
            if (sol2.size() > 99) break;
        }
        if (sol2.size() < 99) break;
        else sol2.clear();
    }
    if (fu) ans.pb(1);
    for (i = 0; i < sol.size(); i++) ans.pb(sol[i]);
    for (i = (int) sol2.size()-1; i >= 0; i--) ans.pb(sol2[i]);
    if (fv) ans.pb(2);
    printf("%d\n",ans.size());
    for (i = 0; i < ans.size(); i++) printf("%d ",ans[i]);
    printf("\n");

    return 0;
}