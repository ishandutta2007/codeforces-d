#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 555000
int n;
int x[N],v[N];

double solve(int s, int m, int e)
{
	double left = 0, right = 1.0e11;
	REP(step,100)
	{
		double t = (left+right)/2.0;
		double mx = -1.0e10;
		FOR(i,s,m-1)
			mx = max(mx, x[i]+v[i]*t);
		double mn = 1.0e10;
		FOR(i,m,e-1)
			mn = min(mn, x[i]+v[i]*t);
		if (mx >= mn)
			right=t;
		else
			left=t;
	}
	return left;
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	REP(i,n)
		scanf("%d%d",x+i,v+i);
	int i = 0;
	for (; i < n && v[i] < 0; i++) ;
	double res = 1.0e11;
	for (; i<n; )
	{
		int j1;
		for (j1 = i; j1 < n && v[j1] > 0; j1++) ;
		if (j1 >= n)
			break;
		int j2;
		for (j2 = j1; j2 < n && v[j2] < 0; j2++) ;
		res = min(res,solve(i,j1,j2));
		i=j2;
	}
	if (res >= 1.0e10)
		printf("-1\n");
	else
		printf("%.12lf\n",res);
	return 0;
}