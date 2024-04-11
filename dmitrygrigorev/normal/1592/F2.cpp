#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 507;

char t[N][N];

int cnt[N][N];
int sum[N];

int T, K;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;
 
bool try_kuhn (int v) {
  if (used[v])  return false;
  used[v] = true;
  for (size_t i=0; i<g[v].size(); ++i) {
    int to = g[v][i];
    if (mt[to] == -1 || try_kuhn (mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}


int main(){
#ifdef LOCAL
  freopen("N_input.txt", "r", stdin);
  //freopen("N_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> t[i][j];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    int tot = 0;
    for (int j = m - 1; j >= 0; --j) {
      tot += sum[j];
      if ((tot + (t[i][j] == 'B')) % 2 != 0) {
        cnt[i][j] = 1;
      }
      sum[j] += cnt[i][j];
      tot += cnt[i][j];
    }
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) ans += cnt[i][j];
  }

  T = n, K = m;
  g.assign(T, {});

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (cnt[i - 1][m - 1] && cnt[n - 1][j - 1] && cnt[i - 1][j - 1]) {
        g[i].pb(j);
      }
    }
  }

  mt.assign (K, -1);
  for (int v=0; v<T; ++v) {
    used.assign (T, false);
    try_kuhn (v);
  }

  int res = 0;

 
  for (int i=0; i<K; ++i)
    if (mt[i] != -1) res++;

  ans = ans - res + (cnt[n - 1][m - 1] ^ (res % 2)) - cnt[n - 1][m - 1];

  cout << ans;

 // cout << ans - res + (cnt[n - 1][m - 1] ^ (res % 2));

}