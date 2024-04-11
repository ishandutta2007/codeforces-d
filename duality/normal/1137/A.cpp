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

int a[1000][1000];
int r[1000],c[1000];
int numr[1000][1000],numc[1000][1000];
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf("%d",&a[i][j]);
    }

    for (i = 0; i < n; i++) {
        vi v;
        for (j = 0; j < m; j++) v.pb(a[i][j]);
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        r[i] = v.size();
        for (j = 0; j < m; j++) numr[i][j] = lower_bound(v.begin(),v.end(),a[i][j])-v.begin();
    }
    for (i = 0; i < m; i++) {
        vi v;
        for (j = 0; j < n; j++) v.pb(a[j][i]);
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        c[i] = v.size();
        for (j = 0; j < n; j++) numc[j][i] = lower_bound(v.begin(),v.end(),a[j][i])-v.begin();
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ",max(numr[i][j],numc[i][j])+max(r[i]-numr[i][j],c[j]-numc[i][j]));
        }
        printf("\n");
    }

    return 0;
}