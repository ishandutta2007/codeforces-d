#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

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
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;
const ll P = 239017;

str s;
ll dp[1000007][7];

void add(ll &a, ll &b){
	a = (a + b) % MOD;
}

const bool is_testing = 0;
int main()
{
	srand(3252);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> s;
	if (s[0] == '?'){
		dp[1][0] = 1;
		if (s.size() > 1)
			dp[1][1] = 1;
		dp[1][4] = 1;
	} else {
		if (s[0] == '0')
			dp[1][0] = 1;
		if (s[0] == '1')
			dp[1][1] = 1;
		if (s[0] == '2')
			cout << 0, exit(0);
		if (s[0] == '*')
			dp[1][4] = 1;
	}
	form(i, 1, (int)s.size() - 1){
		if (s[i] != '?'){
			if (s[i] == '0'){
				add(dp[i+1][0], dp[i][0]);
				add(dp[i+1][0], dp[i][2]);
			}
			if (s[i] == '1'){
				if (i != (int)s.size() - 1){
					add(dp[i+1][1], dp[i][0]);
					add(dp[i+1][1], dp[i][2]);
				}

				add(dp[i+1][2], dp[i][4]);
			}
			if (s[i] == '2'){
				if (i == (int)s.size() - 1)
					cout << 0, exit(0);
				add(dp[i+1][3], dp[i][4]);
			}
			if (s[i] == '*'){
				add(dp[i+1][4], dp[i][3]);
				add(dp[i+1][4], dp[i][1]);
				add(dp[i+1][4], dp[i][4]);
			}
		} else {
			add(dp[i+1][0], dp[i][0]);
			add(dp[i+1][0], dp[i][2]);
			
			if (i != (int)s.size() - 1){
				add(dp[i+1][1], dp[i][0]);
				add(dp[i+1][1], dp[i][2]);
			}

			add(dp[i+1][2], dp[i][4]);

			if (i != (int)s.size() - 1)
				add(dp[i+1][3], dp[i][4]);
			
			add(dp[i+1][4], dp[i][3]);
			add(dp[i+1][4], dp[i][1]);
			add(dp[i+1][4], dp[i][4]);

		}
	}
	ll ans = 0;
	add(ans, dp[(int)s.size()][0]);
	if (s.size() > 1)
		add(ans, dp[(int)s.size()][2]);
	add(ans, dp[(int)s.size()][4]);
	cout << ans;
}