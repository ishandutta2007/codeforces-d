#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int N;
    cin >> N;
    int t = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        t += a;
    }
    cout << t << '\n';
}