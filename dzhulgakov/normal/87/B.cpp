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

int n;
map<string,int> d;

int main()
{
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	scanf("%d",&n);
	d["void"]=0;
	d["errtype"]=-1;
	REP(i,n)
	{
		char cmd[1024];
		char buf[1024];
		scanf("%s %s",cmd,buf);
		string s = string(buf);
		int plus=0,minus=0;
		while (s[s.length()-1]=='*')
		{
			s.resize(s.length()-1);
			++plus;
		}
		while (s[0]=='&')
		{
			s = s.substr(1);
			++minus;
		}
		int x = -1;
		if (d.count(s))
			x = d[s];
		if (x != -1)
		{
			x += plus;
			x -= minus;
			if (x < 0) x = -1;
		}
		if (strcmp(cmd,"typedef")==0)
		{
			scanf("%s",buf);
			d[string(buf)] = x;
		}
		else
		{
			if (x==-1)
				printf("errtype\n");
			else
			{
				printf("void");
				REP(i,x) printf("*");
				printf("\n");
			}
		}
	}
	return 0;
}