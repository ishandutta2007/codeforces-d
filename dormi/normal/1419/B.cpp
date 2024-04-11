#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        int cnt=0;
        for(ll i=2;;i*=ll(2)){
            ll req=(i-1)*i/2;
            if(req>x)break;
            x-=req;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}