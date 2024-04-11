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

int n;
int a[100007];
vector<int> d[100007];
vector<int> t[100007];

int dp[100007];

void go(int x, int val) {
    for (int p : d[x]) dp[p] += val;
}

int mu[100007];

int main(){
#ifdef LOCAL
  freopen("D_input.txt", "r", stdin);
  //freopen("D_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  for (int v = 1; v < 100007; ++v) {
      for (int i = v; i < 100007; i += v) d[i].pb(v);
  }
  
  mu[1] = 1;
  mu[2] = mu[3] = -1;
  for (int v = 4; v < 100007; ++v) {
      int f = d[v][1];
      if ((v / f) % f != 0) mu[v] = -mu[v / f];
  }
  
  ll ans = 0;
  
  cin >> n;
  for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i] = x;
      
      for (int y : d[x]) t[y].pb(x / y);
  }
  
  for (int v = 1; v < 100007; ++v) if (t[v].size() > 1) {
      sort(all(t[v]));
      reverse(all(t[v]));
      
     // cout << t[v] << endl;
      
      vector<int> st;
      for (int x : t[v]) {
          while (st.size()) {
              int now = 0;
              
              for (int p : d[x]) now += mu[p] * dp[p];
              
              if (now != 0) {
                  if (__gcd(x, st.back()) == 1)
                    uax(ans, v * (ll)x * (ll)st.back());
                  go(st.back(), -1);
                  st.pop_back();
              } else break;
          }
          st.pb(x);
          go(x, 1);
      }
      for (int x : st) go(x, -1);
      
    //  break;
  }
  
  cout << ans;
  
}