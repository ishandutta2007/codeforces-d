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
#define write(x) printf("%d", x)
#define writeln(x) printf("%d\n", x)
#define wp(x) cout << x.first << ' ' << x.second << '\n';
#define wm(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' '; cout << LN;
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

int n, m;
set<int> g[107];
pair<int, int> par[107];

int get(int v){
	if (par[v].XX == v)
		re v;
	par[v].XX = get(par[v].XX);
	re par[v].XX;
}

void merge(int v, int u){
	v = get(v);
	u = get(u);
	if (par[v].YY > par[u].YY){
		par[v].YY += par[u].YY;
		par[u].XX = v;
	} else {
		par[u].YY += par[v].YY;
		par[v].XX = u;
	}
}

bool can(int v, int u){
	for (auto it = g[v].begin(); it != g[v].end(); it++)
		if (g[u].count(*it))
			re 1;
	re 0;
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m;
	forn(i, n){
		int k;
		cin >> k;
		forn(j, k){
			int x;
			cin >> x;
			g[i].in(x);
		}
	}
	forn(i, n)
		par[i].XX = i, par[i].YY = 1;
	forn(i, n){
		forn(j, n)
			if (get(i) != get(j) && i != j && can(i ,j))
				merge(i, j);
	}
	set<int> ans;
	int k = 0;
	forn(i, n)
		if (g[i].size() > 0)
			ans.insert(get(i));
		else 
			k++;
	cout << max((int)ans.size() - 1, 0) + k;
}