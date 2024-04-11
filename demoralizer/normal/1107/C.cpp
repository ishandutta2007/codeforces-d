#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}


void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];string s;
    for(int& i:a)cin>>i;
    cin>>s;int ans=0;
    vc<int> v;char c=s[0];
    if(n==1){
        cout<<a[0];return;
    }
    v.pb(a[0]);
    for(int i=1;i<=s.size();i++){
        if((i<s.size())&&(c==s[i])){
            v.pb(a[i]);
        }
        else{
            if(v.size()<=k){
                int sum=0;
                for(int z:v)sum+=z;
                ans+=sum;
            }
            else{
                int sum=0;
                sort(all(v),greater<int>());
                for(int z=0;z<k;z++)sum+=v[z];
                ans+=sum;
            }
            if(i==s.size())break;
            c=s[i];
            v.clear();
            v.pb(a[i]);
        }
    }
    cout<<ans;
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