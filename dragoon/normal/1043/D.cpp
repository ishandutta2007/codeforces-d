#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
//#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

int renumber[100005];
int dp[12][100005];
int num[12][100005];
int whr[12][100005];

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) scanf("%d", &num[i][j]);
	}
	for (int i = 1; i <= n; i++) {
		renumber[num[1][i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			num[i][j] = renumber[num[i][j]];
			whr[i][num[i][j]] = j;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 1; j--) {
			if (j == n) dp[i][j] = 1;
			else {
				dp[i][j] = 1;
				if (whr[i][j + 1] == whr[i][j] + 1) {
					dp[i][j] += dp[i][j + 1];
				}
			}
		}
	}

	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		int mn = n;
		for (int j = 1; j <= m; j++) {
			mn = MIN(mn, dp[j][i]);
		}
		ans += mn;
	}
	printf("%lld\n", ans);

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}