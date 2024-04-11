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

bool go(vector<int>& a, int x) {
  vector<int> b;
  for (int y : a) if (y != x) b.pb(y);
  for (int i = 0; i < b.size(); ++i) {
    int j = (int)b.size() - i - 1;
    if (i >= j) return 1;
    if (b[i] != b[j]) return 0;
  }
  assert(0);
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    readArr(all(a));

   // sort(all(a), [](pair<int, int> w1, pair<int, int> w2) {
   //   return w1.y > w2.y;
   // });

    int vl = 1, vr = n + 1;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      
/*      multiset<int> se;
      int i = 0;
      for (int j = vm - 1; j >= 0; --j) {
        int need = vm - j - 1;
        while (i < n && a[i].y >= j) {
          se.insert(a[i].x);
          ++i;
        }
        while (se.size() && (*se.begin()) < need) {
          se.erase(se.begin()); 
        }
        if (se.size() == 0) {
          ok = 0;
          break;
        }
        se.erase(se.begin());
      } */

      int w1 = 0, w2 = vm - 1;
      for (int i = 0; i < n; ++i) {
        if (a[i].y >= w1 && a[i].x >= w2) {
          ++w1; --w2;
        }
        if (w2 == -1) break;
      }


      if (w2 == -1) vl = vm; else vr = vm;
    }

    cout << vl << "\n";
  }

}