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
    string t;
    cin>>t;
    string s[5];
    for(int i=0;i<5;i++){
        cin>>s[i];
    }
    int c=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++){
            if(s[j].at(i)==t.at(i))c=1;
        }
    }
    if(c)cout<<"YES";
    else cout<<"NO";
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