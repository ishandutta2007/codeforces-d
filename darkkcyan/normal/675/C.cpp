#include <bits/stdc++.h>

using namespace std;

#ifdef db 
#define de(msg) cerr << "line " << __LINE__ << " => " << msg << '\n'
#else
#define de(msg)
#define at operator[]
#endif

#define dev(var) de(#var << ' ' << var)
#define _ << ' ' <<

#define fi first
#define se second
#define mp make_pair
#define ll long long 
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front

#define pii pair<int, int>
#define pilll pair<int, ll>
#define pllll pair<ll, ll>

#define ve vector
#define vi ve<int>
#define vll ve<ll>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ap(a, b, p) {a = (p).fi; b = (p).se;}

int n;
vi arr;
map<ll, ll> fq;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;  // count variable
    cin >> n;
    for (i = 0; i < n; ++i) {
        int a;
        cin >> a;
        arr.pub(a);
    }
    
    ll ps = arr.front();
    fq[ps] = 1;
    for (i = 1; i < n; ++i) {
        ps += arr[i];
        map<ll, ll>::iterator t = fq.find(ps);
        if (t != fq.end()) {
            t->se ++;
        } else {
            fq[ps] = 1;
        }
    }

    ll res = -1;
    for (map<ll, ll>::iterator i = fq.begin(); i != fq.end(); ++i) {
        res = max(res, i->se);
    }

    cout << (n - res);

    return 0;
}