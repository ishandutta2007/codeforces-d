#include <bits/stdc++.h>
#include <Windows.h>
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
const int MAXN = 20 + 7;

int n;
bool was[4007];
int ans[4007];
vec < pair < int, pair <int, int> > > a;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    if (is_testing)
    {
        freopen("INPUT.in", "r", stdin);
    }
    cin >> n;
    for (int i = 1; i <= 2 * n - 1; i++)
        for (int j = 1; j <= i; j++)
        {
            int z;
            cin >> z;
            a.pb(mp(z, mp(i + 1, j)));
        }
    sort(all(a));
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (!was[a[i].YY.XX] && !was[a[i].YY.YY])
        {
            was[a[i].YY.YY] = true;
            was[a[i].YY.XX] = true;
            ans[a[i].YY.YY] = a[i].YY.XX;
            ans[a[i].YY.XX] = a[i].YY.YY;
        }
    }
    form(i, 1, n*2)
        cout << ans[i] << ' ';
}
//190660JM