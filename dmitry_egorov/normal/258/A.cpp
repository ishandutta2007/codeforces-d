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

char s[110000];

int main()
{
  int i, j, len;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), len=strlen(s);
  for (i=0; i<len-1; i++)
    if (s[i]=='0')
    {
      for (j=i+1; j<len; j++)
        s[j-1]=s[j];
      break;
    }
  s[len-1]=0, puts(s);
  return 0;
}