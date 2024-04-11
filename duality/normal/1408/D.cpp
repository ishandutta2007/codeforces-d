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

int a[2000],b[2000],c[2000],d[2000];
vpii v,v2;
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d %d",&a[i],&b[i]);
    for (i = 0; i < m; i++) scanf("%d %d",&c[i],&d[i]);

    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((a[i] <= c[j]) && (b[i] <= d[j])) v.pb(mp(c[j]-a[i],d[j]-b[i]));
        }
    }
    if (v.empty()) {
        printf("0\n");
        return 0;
    }
    sort(v.begin(),v.end());
    for (i = 0; i < v.size(); i++) {
        while (!v2.empty() && (v2.back().second <= v[i].second)) v2.pop_back();
        v2.pb(v[i]);
    }
    int ans = min(v2[0].second+1,v2.back().first+1);
    for (i = 1; i < v2.size(); i++) ans = min(ans,v2[i-1].first+v2[i].second+2);
    printf("%d\n",ans);

    return 0;
}