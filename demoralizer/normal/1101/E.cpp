#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
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
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}


void solve(){
    int n;
    cin>>n;
    int x=-1,y=-1;
    char in;
    cin>>in>>x>>y;
    if(x>y)swap(x,y);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>in>>a>>b;
        if(a>b)swap(a,b);
        if(in=='+'){
            x=max(x,a);
            y=max(y,b);
        }
        else{
            if(a<x||b<y)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
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