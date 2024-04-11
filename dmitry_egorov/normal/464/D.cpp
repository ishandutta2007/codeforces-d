#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

const int maxn = 600;

ld D[maxn];
ld res;
                        
int main()
{
  int n, k, i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &k);
  D[1]=k;
  while (n)
  {
    n--;
    ld add=0, tmp;
    for (i=maxn-2; i>=1; i--)
    {
      if (D[i]<1e-100)
        continue;
      add+=D[i]*((i+2)/2.0-1.0/(i+1))/k;
      tmp=D[i]/((i+1)*k);
      D[i+1]+=tmp, D[i]-=tmp;
    }
    res+=add;
  }
  printf("%.12lf\n", (double)res);  
  TIMESTAMP(end);
  return 0;
}