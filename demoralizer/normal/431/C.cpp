#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int n,k,d;
int dp[105],yo[105];
void solve(){
    cin>>n>>k>>d;
    dp[d]=1;
    yo[1]=1;yo[0]=1;
    for(int i=2;i<n;i++){
        for(int j=1;(j<=k)&&(j<=i);j++){
            yo[i]+=yo[i-j];
            yo[i]%=M;
        }
    }
    for(int i=d+1;i<=n;i++){
        for(int j=1;(j<=k)&&(j<=i);j++){
            if(j<d)dp[i]+=dp[i-j];
            else dp[i]+=yo[i-j];
            dp[i]%=M;
        }
    }
    cout<<dp[n];
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}