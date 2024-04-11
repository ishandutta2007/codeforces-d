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

int good[7001];
bitset<7001> a[7001],b[7001];
bitset<7001> bs[100000];
string ans;
int main() {
    int i,j;
    int n,q;
    int t,x,y,z,v;
    scanf("%d %d",&n,&q);
    for (i = 1; i <= 7000; i++) {
        int n = i,no = 0;
        for (j = 2; j <= n; j++) {
            if ((n % j) == 0) {
                n /= j;
                if ((n % j) == 0) no = 1;
            }
        }
        good[i] = !no;
    }
    for (i = 1; i <= 7000; i++) {
        for (j = i; j <= 7000; j += i) {
            if (good[j/i]) a[i][j] = 1;
            b[j][i] = 1;
        }
    }
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&x,&v);
            bs[x-1] = b[v];
        }
        else if (t == 2) {
            scanf("%d %d %d",&x,&y,&z);
            bs[x-1] = bs[y-1] ^ bs[z-1];
        }
        else if (t == 3) {
            scanf("%d %d %d",&x,&y,&z);
            bs[x-1] = bs[y-1] & bs[z-1];
        }
        else {
            scanf("%d %d",&x,&v);
            ans += '0'+((bs[x-1] & a[v]).count() & 1);
        }
    }
    cout << ans << endl;

    return 0;
}