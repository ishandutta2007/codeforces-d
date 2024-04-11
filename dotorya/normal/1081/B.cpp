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
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> Vl[100050];
int ans[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		Vl[t].push_back(i);
	}

	int hc = 0;
	for (i = 0; i < N; i++) {
		int c = N - i;
		if (Vl[i].size() % c != 0) return !printf("Impossible\n");

		while (!Vl[i].empty()) {
			hc++;
			for (int j = 0; j < c; j++) {
				ans[Vl[i].back()] = hc;
				Vl[i].pop_back();
			}
		}
	}
	
	printf("Possible\n");
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}