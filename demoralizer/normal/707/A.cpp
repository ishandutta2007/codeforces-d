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

void solve(){
    int n,m,t=0;
    cin>>n>>m;
    string c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if((c=="C")||(c=="M")||(c=="Y")){
                t=1;
            }
        }
    }
    if(t)cout<<"#Color";
    else cout<<"#Black&White";
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