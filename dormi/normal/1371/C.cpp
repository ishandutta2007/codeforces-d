#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll a,b,n,m;
        cin>>a>>b>>n>>m;
        if(a+b<n+m)printf("No\n");
        else if(min(a,b)<m)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}