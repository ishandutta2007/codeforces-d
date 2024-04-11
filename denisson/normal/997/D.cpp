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
 
#define pper(a) cout << #a << " = " << a << endl;
 
void per() { cout << endl; }
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
 
const int mod = 998244353;
 
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
 
int k;
 
const int MAXN = 4444;
class CentroidDecomposition {
public:
  int n;
  vector<int> g[MAXN];
  int w[MAXN];
  int del[MAXN];
  
  void CalcW(int v, int p = -1) {
    w[v] = 1;
    for (int to : g[v]) if (to != p && !del[to]) {
      CalcW(to, v);
      w[v] += w[to];
    }
  }
  
  int FindCentroid(int v, int total_w, int p = -1) {
    for (int to : g[v]) if (to != p && !del[to] && 2 * w[to] > total_w) {
      return FindCentroid(to, total_w, v);
    } 
    return v;
  }
  
  int res[77];
  int f[4004][80];
  int d1[4004][80];
  int d2[4004][80];
  
  int pep[80];
  
  void dfs(int v, int p = -1) {
 
    for (int to : g[v]) if (to != p && !del[to]) {
      dfs(to, v);
    }
 
    fill(pep, pep + 80, 0);
    fill(f[v], f[v] + 80, 0);
    
    for (int to : g[v]) if (to != p && !del[to]) {
    //  cout << "EDGE " << v << ' ' << to << ' ' << f[to][0] << ' ' << pep[2] << endl;
      
      for (int i = 0; i <= k; ++i) {
        add(pep[i + 2], f[to][i]);
      }
    }
    
  //  cout << "v: " << v << endl;
  //    for (int i = 0; i <= k; ++i) cout << pep[i] << ' '; cout << endl;
    
    f[v][0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int nxt = 2; nxt + i <= k; ++nxt) {
            add(f[v][nxt + i], mult(pep[nxt], f[v][i]));
        }
    }
    
  }
  
  void go(int v, int p = -1) {
 
    fill(d1[v], d1[v] + 80, 0);
    fill(d2[v], d2[v] + 80, 0);

    if (p == -1) {
      d1[v][0] = 1;
      copy(f[v], f[v] + 80, d2[v]);
    } else {
      for (int a = 0; a <= k; ++a)
      for (int b = 0; a + b + 1 <= k; ++b) {
        add(d1[v][a + b + 1], mult(f[v][b], d1[p][a]));
        add(d2[v][a + b + 1], mult(f[v][b], d2[p][a]));
      }

    }

  //  pper(v);
  //  for (int i = 0; i <= k; ++i) {
  //    cout << v << ' ' << i << ' ' << f[v][i] << ' ' << d1[v][i] << ' ' << d2[v][i] << endl;
  //  }


    for (int a = 0; a <= k; ++a)
    for (int b = 0; a + b <= k; ++b) {
      add(res[a + b], mult(d1[v][a], d2[v][b]));
    }

    for (int to : g[v]) if (to != p && !del[to]) {
      go(to, v);
    }


  }

  int Build(int v) {
    CalcW(v);
    int c = FindCentroid(v, w[v]);
    
    dfs(c);
    go(c);
    
    del[c] = 1;
    for (int to : g[c]) if (!del[to]) {
      Build(to);
    }
  }
  
  vector<int> solve() {
    fill(res, res + 77, 0);
    Build(0);
    return vector<int>(res, res + k + 1);
  }
  
} c1, c2;
 
int cnk[77][77];
 
int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> c1.n >> c2.n >> k;
  for (int i = 1; i < c1.n; ++i) {
      int w1, w2;
      cin >> w1 >> w2;
      --w1; --w2;
      c1.g[w1].pb(w2);
      c1.g[w2].pb(w1);
  }
  
  for (int i = 1; i < c2.n; ++i) {
      int w1, w2;
      cin >> w1 >> w2;
      --w1; --w2;
      c2.g[w1].pb(w2);
      c2.g[w2].pb(w1);
  }
  
  for (int i = 0; i < 77; ++i) {
    cnk[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      add(cnk[i][j], cnk[i - 1][j]);
      add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }
 
  auto now1 = c1.solve();
  
  auto now2 = c2.solve();
  
//  for (int x : now1) cout << x << ' '; cout << endl;
//  for (int x : now2) cout << x << ' '; cout << endl;
  
  int res = 0;
  
  for (int i = 0; i <= k; ++i) {
    add(res, mult(mult(now1[i], now2[k - i]), cnk[k][i]));
  }
  
  cout << res;
}