#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char in[70050][20];
char u[70050];
vector <ll> Vin[70050][11];

vector <ll> Vu[11];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", in[i]);
		for (j = 0; j < 9; j++) {
			ll v = 0;
			for (k = j; k < 9; k++) {
				v = 11 * v + (in[i][k] - '0' + 1);
				Vin[i][k - j + 1].push_back(v);
				Vu[k-j+1].push_back(v);
			}
		}
		for (j = 1; j <= 9; j++) {
			sort(all(Vu[j]));
			for (k = 0; k < Vu[j].size(); k++) if (k == 0 || Vu[j][k] != Vu[j][k - 1]) Vin[0][j].push_back(Vu[j][k]);
			Vu[j].clear();
		}
	}
	for (i = 1; i <= 9; i++) sort(all(Vin[0][i]));

	for (i = 1; i <= N; i++) {
		int mn = INF, a1 = 0, a2 = 0;
		for (j = 1; j <= 9; j++) {
			for (k = 0; j + k <= 9; k++) {
				int x = k, y = j + k - 1;
				ll v = Vin[i][j][k];

				int c = lower_bound(all(Vin[0][j]), v + 1) - lower_bound(all(Vin[0][j]), v);
				if (c != 1) continue;
				if (mn > j) {
					mn = j;
					a1 = x, a2 = y;
				}
			}
		}
		for (j = a1; j <= a2; j++) printf("%c", in[i][j]);
		printf("\n");
	}
	return 0;
}