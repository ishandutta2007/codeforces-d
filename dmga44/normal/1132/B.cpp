#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,x;
    cin >> n;
    ll sum=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        v.push_back(x);
        sum+=x;
    }

    sort(v.rbegin(),v.rend());

    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x;
        db(sum-v[x-1])
    }

    return 0;
}