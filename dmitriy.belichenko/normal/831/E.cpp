#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
long long inf = 1LL << 62;
static long parseans(long j, long l)
{
    string k = "";
    long ps = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        ps *= 10;
        ps += k[i] - '0';
    }
    return ps;
}

int cur = 1;

static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

static bool pri(long long k)
{
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}

double binpow (double a, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return binpow (a, n-1) * a;
    else {
        int b = binpow (a, n/2);
        return b * b;
    }
}
vector<int> calcz (string s)
{
    int n = s.length();
    vector<int> z (n);
    int l = 0, r = 0;
    for (int i = 1 ; i<n; i++)
    {
        if (i <= r)
        {
            z[i] = min (r - i+ 1, z[i - l]);
        }
        while (i + z[i] < n && s[ z[i] ] == s[i + z[i] ]) z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}


vector<int> calcpref(string s)
{
    vector<int> p(s.size() + 1);
    int n = s.length();
    p[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[p[i]] !=s[i-1]) p[i] = p[p[i]];
        if (s[p[i]] == s[i-1]) p[i]++;
    }
    return p;
}


int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    int cur = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<set<int>>p (100005);
    for(int i = 0; i < n; i++)
    {
        p[a[i]].insert(i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        ans++;
        auto it = p[a[i]].lower_bound(cur);
        if ( it == (p[a[i]].end()))
        {
            int del = n - i;
            cur = 0;
            it = p[a[i]].lower_bound(cur);
            ans += del;
        }
        cur = (int)*it;
        p[a[i]].erase(it);
        //cout << ans << "\n";
        //cout << *it;
    }
    cout << ans << "\n";
    return 0;
}