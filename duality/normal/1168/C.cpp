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

int a[300000];
int dp[300001][20],nxt[20];
int main() {
    int i;
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    int j,k;
    for (i = 0; i < 20; i++) nxt[i] = dp[n][i] = n;
    for (i = n-1; i >= 0; i--) {
        for (j = 0; j < 20; j++) {
            if (a[i] & (1 << j)) dp[i][j] = i;
            else {
                dp[i][j] = n;
                for (k = 0; k < 20; k++) {
                    if (a[i] & (1 << k)) dp[i][j] = min(dp[i][j],dp[nxt[k]][j]);
                }
            }
        }
        for (j = 0; j < 20; j++) {
            if (a[i] & (1 << j)) nxt[j] = i;
        }
    }

    int x,y;
    for (i = 0; i < q; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        for (j = 0; j < 20; j++) {
            if ((a[y] & (1 << j)) && (dp[x][j] <= y)) break;
        }
        if (j < 20) printf("Shi\n");
        else printf("Fou\n");
    }

    return 0;
}