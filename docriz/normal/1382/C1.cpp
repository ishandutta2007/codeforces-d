#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

using ll = long long;
using PII = pair<int, int>;
using PIL = pair<int, ll>;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define VL(n) vector<ll>(n)
#define VI(n) vector<int>(n)
#define VII(n, m) vector<vector<int>>(n, vector<int>(m))
#define VLL(n, m) vector<vector<ll>>(n, vector<ll>(m))
#define VIII(n, m, p) vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(p)))
#define VLLL(n, m, p) vector<vector<vector<ll>>>(n, vector<vector<ll>>(m, vector<ll>(p)))

/*
  find the biggest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_biggest(int l, int r, const function<bool(int)>& check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  return l;
}

/*
  find the smallest x that check(x) is true.
  time complexity: O(log(r-l))
  space commplexity: O(1)
*/
int bs_smallest(int l, int r, const function<bool(int)>& check) {
  assert(l <= r);
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  return l;
}

const int MOD = (int)1e9 + 7;

int fexp(int a, int b) {
  int res = 1;
  for(int i = 1; i <= b; i <<= 1) {
    if(i & b) res = (ll)res * a % MOD;
    a = (ll)a * a % MOD;
  }
  return res;
}

int inv(int x) {
  return fexp(x, MOD - 2);
}

ll gcd(ll a, ll b) { 
  return b ? gcd(b, a % b) : a;
}

void my_main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    assert(sz(a) == n);
    assert(sz(b) == n);
    a = "#" + a;
    b = "#" + b;
    vector<int> ans;
    auto go = [&](int p) -> void {
      ans.push_back(p);
      rep(i, 1, p + 1) {
        if (a[i] == '0') a[i] = '1';
        else a[i] = '0';
      }
      rep(i, 1, p + 1) {
        int j = p + 1 - i;
        if (j <= i) break;
        swap(a[i], a[j]);
      }
      // reverse(a.begin() + 1, a.begin() + p + 1);
      // cout << "go(" << p << "): " << a << endl;
    };
    for (int i = n; i >= 1; i--) {
      if (a[i] == b[i]) continue;
      if (a[1] == b[i]) go(1);
      assert(a[1] != b[i]);
      go(i);
      assert(a[i] == b[i]);
    }
    /*
    cout << a << endl;
    cout << b << endl;
    */
    assert(a == b);
    cout << sz(ans);
    for (auto v: ans) {
      cout << " " << v;
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  my_main();
  return 0;
}