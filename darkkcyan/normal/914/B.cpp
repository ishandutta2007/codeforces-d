#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 101010
int n;
int a[maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) {
    int u; cin >> u;
    a[u] ++;
  }
  bool ans = 0;
  rep(i, maxn ) {
    if (a[i] and (a[i] & 1)) ans = 1;
  }
  cout << (ans ? "Conan" : "Agasa"); 
  return 0;
}