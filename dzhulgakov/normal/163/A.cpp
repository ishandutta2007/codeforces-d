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

#define MOD 1000000007
#define N 5555
char a[N],b[N];
LL d[2][N];
LL res;

int main()
{
	//freopen("a.in","r",stdin);

	CLEAR(d);
	res = 0;
	gets(a);
	gets(b);
	int na = strlen(a);
	int nb = strlen(b);
	int cur = 0;
	REP(iii,na)
	{
		CLEAR(d[cur^1]);
		LL sum = 1;
		REP(i,nb)
		{
			if (a[iii] == b[i])
			{
				d[cur^1][i] = (d[cur^1][i] + sum)%MOD;
				res = (res+sum)%MOD;
			}
			sum = (sum+d[cur][i])%MOD;
		}
		cur^=1;
	}
	printf("%d\n",(int)(res%MOD));
	return 0;
}