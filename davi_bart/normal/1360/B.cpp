#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int N;
  cin>>N;
  vector<int>p;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;p.push_back(a);
  }
  sort(p.begin(),p.end());
  int mi=1000000;
  for(int i=1;i<N;i++)mi=min(mi,p[i]-p[i-1]);
  cout<<mi<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--)solve();
}