#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
//

#define read(x) scanf("%d", &x)
#define write(x) printf("%d", &x)
#define read2(x, y) scanf("%d %d", &x, &y)

//
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const bool is_testing = false;
const int p = 31;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 11;
const int MAXN = 6e5 + 7;

int n, m, k;
bool was[1007][1007];

bool check(int i, int j)
{
    if (was[i][j] && was[i - 1][j] && was[i][j - 1] && was[i - 1][j - 1])
        re 0;
    if (was[i][j] && was[i - 1][j] && was[i][j + 1] && was[i - 1][j + 1])
        re 0;
    if (was[i][j] && was[i + 1][j] && was[i][j - 1] && was[i + 1][j - 1])
        re 0;
    if (was[i][j] && was[i + 1][j] && was[i][j + 1] && was[i + 1][j + 1])
        re 0;
    re 1;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n >> m >> k;
    forn(i, k)
    {
        int x, y;
        cin >> x >> y;
        was[x][y] = true;
        if (!check(x, y))
            cout << i + 1, exit(0);
    }
    cout << 0;
}
//190660JM