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

int inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int fact[1000001],invfact[1000001];
int c1[1000001],c2[1000001];
int main() {
    string s;
    cin >> s;

    int i,q = 0;
    int n = s.size();
    for (i = 0; i < n; i++) {
        if (s[i] == '?') q++;
    }
    if (q == 0) {
        int l = 0,r = n-1,c = 0;
        while (l < r) {
            if (s[l] == ')') l++;
            else if (s[r] == '(') r--;
            else c++,l++,r--;
        }
        cout << c << endl;
        return 0;
    }
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = ((LLI) fact[i-1]*i) % MOD;
    invfact[n] = inv(fact[n]);
    for (i = n-1; i >= 0; i--) invfact[i] = ((LLI) invfact[i+1]*(i+1)) % MOD;
    for (i = 0; i < q; i++) {
        c1[i] = ((((LLI) fact[q-1]*invfact[i]) % MOD)*invfact[q-i-1]) % MOD;
        if (i > 0) c1[i] += c1[i-1],c1[i] %= MOD;
    }
    for (i = 0; i <= q; i++) {
        c2[i] = ((((LLI) fact[q]*invfact[i]) % MOD)*invfact[q-i]) % MOD;
        if (i > 0) c2[i] += c2[i-1],c2[i] %= MOD;
    }
    int ans = 0;
    int a = 0,b = 0,c = 0,d = q;
    for (i = 0; i < n; i++) {
        if (s[i] == ')') b++;
    }
    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            int x = d+b-a-1;
            if (x >= 0) ans += c2[min(x,q)];
            a++;
        }
        else if (s[i] == ')') b--;
        else {
            d--;
            int x = d+b-a-1;
            if (x >= 0) ans += c1[min(x,q-1)];
            c++;
        }
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}