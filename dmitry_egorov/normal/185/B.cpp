#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
  double s, a[3];
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%lf%lf%lf%lf", &s, &a[0], &a[1], &a[2]);
  //assert(a[0]+a[1]+a[2]>=0.5);
  if (a[0]+a[1]+a[2]<0.5)
  {
    printf("%.18lf %.18lf %.18lf\n", s/3.0, s/3.0, s/3.0);
    return 0;
  }
  int i;
  for (i=0; i<3; i++)
    printf("%.18lf ", (s*a[i])/(a[0]+a[1]+a[2]));
  printf("\n");
  return 0;
}