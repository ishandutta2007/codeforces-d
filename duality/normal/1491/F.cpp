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

int a[2000];
int main() {
    int i,j;
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n;

        int x;
        for (i = 0; i < n; i++) {
            cout << "? " << 1 << " " << n-i-1 << endl;
            cout << i+1 << endl;
            for (j = i+1; j < n; j++) cout << j+1 << " ";
            cout << endl;
            cin >> x;
            a[i] = x;
            if (x != 0) break;
        }
        int p = i;
        vi d;
        for (i = p+1; i < n-1; i++) {
            cout << "? " << 1 << " " << n-i-1 << endl;
            cout << p+1 << endl;
            for (j = i+1; j < n; j++) cout << j+1 << " ";
            cout << endl;
            cin >> x;
            a[i] = x;
        }
        a[n-1] = 0;
        for (i = p+1; i < n; i++) {
            if (a[i-1] == a[i]) d.pb(i);
        }
        int l = 0,r = p;
        while (l < r) {
            int m = (l+r) / 2;

            cout << "? " << 1 << " " << m+1 << endl;
            cout << p+1 << endl;
            for (i = 0; i <= m; i++) cout << i+1 << " ";
            cout << endl;
            cin >> x;
            if (x != 0) r = m;
            else l = m+1;
        }
        for (i = 0; i < p; i++) {
            if (i != l) d.pb(i);
        }
        cout << "! " << d.size();
        for (i = 0; i < d.size(); i++) cout << " " << d[i]+1;
        cout << endl;
    }

    return 0;
}