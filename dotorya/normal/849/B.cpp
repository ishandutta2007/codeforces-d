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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int N;
pll in[1050];
bool isValid(ll a, ll b) {
	set <ll> Sx;
	for (int i = 1; i <= N; i++) Sx.insert(a*in[i].first + b*in[i].second);
	if (Sx.size() == 2) return true;
	return false;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		in[i].first = i;
		scanf("%lld", &in[i].second);
	}
	for(int i = 2; i <= N; i++) if (isValid(in[1].second - in[i].second, in[i].first - in[1].first)) return !printf("Yes\n");
	if (isValid(in[2].second - in[3].second, in[3].first - in[2].first)) return !printf("Yes\n");
	return !printf("No\n");
}