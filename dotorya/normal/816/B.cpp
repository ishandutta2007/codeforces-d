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

int del[200050];
int sum[200050];
int main() {
	int N, K, Q, i, j;
	scanf("%d %d %d", &N, &K, &Q);
	for (i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		del[t1]++, del[t2 + 1]--;
	}
	for (i = 1; i <= 200000; i++) del[i + 1] += del[i];
	for (i = 1; i <= 200000; i++) {
		sum[i] = sum[i - 1];
		if (del[i] >= K) sum[i]++;
	}
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		printf("%d\n", sum[t2] - sum[t1 - 1]);
	}
	return 0;
}