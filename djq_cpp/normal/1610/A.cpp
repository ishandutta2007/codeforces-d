#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) {
		int n, m;
		scanf("%d%d", &n, &m);
		if(n == 1 && m == 1) printf("0\n");
		else if(n == 1 || m == 1) printf("1\n");
		else printf("2\n");
	}
	return 0;
}