#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N];
int main()
{
	int i,n,k,sum=0,m,j;
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&m);
		for(j=1;j<=m;j++)
			scanf("%d",&a[j]);
		if(a[1]==1)
		{
			for(j=1;j<=m;j++)
				if(a[j]!=j)
					break;
			j--;
			sum+=(m-j)*2;
		}
		else sum+=m+m-1;
	}
	cout<<sum<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);