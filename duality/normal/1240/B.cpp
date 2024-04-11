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
vi s;
int l[300000],r[300000];
int bit[300003];
int dp[300000];
int main() {
    int i;
    int q,n;
    scanf("%d",&q);
    while (q--) {
        scanf("%d",&n);
        fill(l,l+n,-1);
        for (i = 0; i < n; i++) {
            scanf("%d",&a[i]),a[i]--;
            s.pb(a[i]);
        }
        sort(s.begin(),s.end());
        s.resize(unique(s.begin(),s.end())-s.begin());
        for (i = 0; i < n; i++) a[i] = lower_bound(s.begin(),s.end(),a[i])-s.begin();
        for (i = 0; i < n; i++) {
            if (l[a[i]] == -1) l[a[i]] = r[a[i]] = i;
            else r[a[i]] = i;
        }

        int j,m = 0;
        for (i = 0; i < n; i++) {
            dp[i] = 0;
            if (i == l[a[i]]) {
                dp[i] = 1;
                if ((a[i] > 0) && (r[a[i]-1] < i)) dp[i] = max(dp[i],dp[r[a[i]-1]]+1);
            }
            if (i == r[a[i]]) dp[i] = dp[l[a[i]]];
            m = max(m,dp[i]);
        }
        int c = 0;
        printf("%d\n",s.size()-m);
        s.clear();
    }

    return 0;
}