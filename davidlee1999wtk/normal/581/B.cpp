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
int a[N],n,ans[N];
int main()
{
    int i,mx=0;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=n;i;i--)
    {
        if(a[i]>mx)
            ans[i]=0;
        else ans[i]=mx+1-a[i];
        mx=max(mx,a[i]);
    }
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))