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

int A[2];
char s[1100];

int main()
{
  int i, len, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<2; i++)
    for (gets(s), len=strlen(s), j=0; j<len; j++)
      if (s[j]=='1')
        A[i]++;
  if (A[0]&1)
    A[0]++;
  (A[0]>=A[1])?(puts("YES")):(puts("NO"));
  return 0;
}