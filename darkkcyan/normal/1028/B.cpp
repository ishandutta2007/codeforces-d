#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; ) 

int n, m;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;

  cout << string(n, '1') << '\n' << string(n - 1, '8') << '9';


  return 0;
}