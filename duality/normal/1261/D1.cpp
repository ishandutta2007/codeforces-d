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
#define MOD 998244353

int h[200000];
int C[2005][2005];
int power[200000];
int main() {
    int i,j;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&h[i]);

    int c = 0,ans = 1;
    for (i = 0; i < n; i++) {
        if (h[i] == h[(i+1) % n]) ans = ((LLI) ans*k) % MOD;
        else c++;
    }
    for (i = 0; i < 2005; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1]+C[i-1][j]) % MOD;
    }
    power[0] = 1;
    for (i = 1; i < c; i++) power[i] = ((LLI) power[i-1]*(k-2)) % MOD;
    int sum = 0;
    for (i = 1; i <= c; i++) {
        for (j = 0; j < i; j++) {
            if (c >= i+j) sum += ((((LLI) power[c-i-j]*C[c][i]) % MOD)*C[c-i][j]) % MOD,sum %= MOD;
        }
    }
    ans = ((LLI) ans*sum) % MOD;
    printf("%d\n",ans);

    return 0;
}