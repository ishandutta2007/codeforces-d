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

char s[200][100]={
"+------------------------+",
"|O.O.O.O.O.O.O.O.O.O.O.|D|)",
"|O.O.O.O.O.O.O.O.O.O.O.|.|",
"|O.......................|",
"|O.O.O.O.O.O.O.O.O.O.O.|.|)",
"+------------------------+"
};
                
int main()
{
  int n;
  #ifdef LOCAL
  //freopen(TASKNAME".in","r",stdin);
  //freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n), n=34-n;  
  for (int i=strlen(s[0]); i>=0; i--)
    for (int j=5; j>=0; j--)
      if (n && s[j][i]=='O')
        s[j][i]='#', n--;
  for (int i=0; i<6; i++)
    puts(s[i]);
  TIMESTAMP(end);
  return 0;
}