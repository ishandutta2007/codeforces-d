#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll=long long int;
using ld=long double;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
using point=complex<ld>;
#define F first
#define S second
//#define X real()
//#define Y imag()
#define pb push_back
#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define kill(x) cout << x << '\n';exit(0)
#define killshayan kill("done!\n")
const int N=3e3+10,LN=19,M=1e8+10,SQ=256,B=737,inf=1e9;
const ll INF=1e18;
const ld ep=1e-7;
const int MH=1000696969,MD=998244353,MOD=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
template<typename F, typename C> // F = flow, C = cost
struct MinCostMaxFlow {
    struct Edge {
        int to;
        F cap;
        C cost;
        int id;
        Edge () : to(), cap(), cost(), id() {}
        Edge (int _to, F _cap, C _cost, int _id) : to(_to), cap(_cap), cost(_cost), id(_id) {}
    };
    int n;
    vector< Edge > E;
    vector< vector<int> > G;
    vector< int > par, use;
    vector< C > dis, pot;

    MinCostMaxFlow(int _n) : n(_n), use(_n, 0), pot(_n, 0){
        G.resize(_n);
        dis.resize(_n,inf);
        par.resize(_n,-1);
    }
    void AddEdge(int u, int v, F cap, C cost, int id = -1){
        G[u].push_back((int) E.size());
        E.push_back({v, cap, cost, id});
        G[v].push_back((int) E.size());
        E.push_back({u, 0, -cost, id});
    }
    pair<F, C> Push(int src, int snk, int ct){
        fill(dis.begin(), dis.end(), numeric_limits<C>::max());
        fill(par.begin(), par.end(), -1);
        fill(use.begin(), use.end(), 0);
        priority_queue<pair<C, int>, vector< pair<C, int> >, greater< pair<C, int> > > pq;
        dis[src] = 0; pq.push({dis[src], src});

        int fr;
        while(!pq.empty()){
            fr = pq.top().S; pq.pop();
            if(use[fr]) continue;
            use[fr] = 1;
            for(auto id : G[fr]){
                if(E[id].cap == 0) continue;
                C w = E[id].cost + pot[fr] - pot[E[id].to];
                if(dis[ E[id].to ] > dis[fr] + w){
                    dis[ E[id].to ] = dis[fr] + w;
                    pq.push({dis[ E[id].to ], E[id].to});
                    par[ E[id].to ] = id;
                }
            }
        }

        if(use[snk] == 0) return {0, 0};

        for(int i = 0; i < n; i++) pot[i] += dis[i];
        F mn = ct;
        for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) mn = min(mn, E[par[u]].cap);
        for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) E[par[u]].cap -= mn, E[par[u]^1].cap += mn;
        return {mn, pot[snk]};
    }

    pair<F, C> MinCost(int src, int snk, int ct){
        pair<F, C> res, tot = {0, 0};
        for(int i = 0; i < n; i++) pot[i] += dis[i];
        F mn = ct;
        for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) mn = min(mn, E[par[u]].cap);
        for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) E[par[u]].cap -= mn, E[par[u]^1].cap += mn;
        ct-=mn;
        tot.F+=mn;
        tot.S+=mn*pot[snk];
        while((res = Push(src, snk, ct)).F > 0){
            tot.S += res.F * res.S;
            ct-=res.F;
            tot.F += res.F;
        }
        return tot;
    }
};
template<typename F, typename C>
using Flow = MinCostMaxFlow<F, C>;
ll n,k,a[N];
int main(){
    fast_io;
    cin >> n;
    Flow<ll,ll> flow(n*2+2);
    flow.dis[0]=0;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        flow.AddEdge(0,i+n,1,0);
        flow.dis[i+n]=0;
        flow.par[i+n]=flow.G[0].back();
        for(ll j=1; j<i; j++){
            if(abs(a[j]-a[i])==1 || a[j]%7==a[i]%7){
                flow.AddEdge(j,i+n,1,0);
                if(flow.dis[i+n]>flow.dis[j]){
                    flow.dis[i+n]=flow.dis[j];
                    flow.par[i+n]=flow.G[j].back();
                }
            }
        }
        flow.AddEdge(i+n,i,1,-1);
        flow.dis[i]=flow.dis[i+n]-1;
        flow.par[i]=flow.G[i+n].back();
        flow.AddEdge(i,n*2+1,1,0);
        if(flow.dis[2*n+1]>flow.dis[i]){
            flow.dis[2*n+1]=flow.dis[i];
            flow.par[2*n+1]=flow.G[i].back();
        }
    }
    cout << flow.MinCost(0,n*2+1,4).S*-1 << '\n';
    return 0;
}