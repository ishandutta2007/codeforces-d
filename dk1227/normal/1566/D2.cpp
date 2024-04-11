#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <chrono>
#include <random>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define fi first
#define se second
#define il inline
#define Ld double
#define pc putchar
#define rg register
#define ll long long
#define lll __int128
#define pb push_back
#define mp make_pair
#define It ::iterator
#define W(p) while(p--)
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int, int>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define def(N, K, b) const K N = b;
#define FOR(i, b, s) for(int i = (b); i < (s); ++i) 
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define FOR_(i, b, s) for(int i = (b); i > (s); --i) 
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

namespace IO {
    const int SIZE = (1 << 20) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = obuf + SIZE - 1;
    char _st[55];
    int _qr = 0;
    inline char gc() {
        return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++) : *iS++);
    }
    inline void qread() {}
    template<class T1, class ...T2>
    inline void qread(T1 &IEE, T2&... ls) {
        register T1 __ = 0, ___ = 1;
        register char ch;
        while(!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
        do {
            __ = (__ << 1) + (__ << 3) + (ch ^ 48);
        }while(isdigit(ch = gc()));
        __ *= ___;
        IEE = __;
        qread(ls...);
        return ;
    }
    template<class T>
	inline void QreadArr(T Begin, T End) {
		while(Begin != End) {
			qread(*Begin);
			++Begin;
		}
	}
    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return ;
    }
    inline void putc_(char _x) {
        *oS++ = _x;
        if(oS == oT) flush();
    }
    inline void qwrite() {}
    template<class T1, class ...T2>
    inline void qwrite(T1 IEE, T2... ls) {
        if(!IEE) putc_('0');
        if(IEE < 0) putc_('-'), IEE = -IEE;
        while(IEE) _st[++_qr] = IEE % 10 + '0', IEE /= 10;
        while(_qr) putc_(_st[_qr--]);
        qwrite(ls...);
        return ;
    }
    template<class T>
    inline void WriteArr(T Begin, T End) {
    	const char Kg = ' ', Edl = '\n';
    	while(Begin != End) {
    		qwrite(*Begin);
    		++Begin;
    		putc_(Kg);
		}
		putc_(Edl);
	}
    struct Flusher_{ ~Flusher_() { flush(); } } io_flusher;
}

using namespace IO;
using namespace std;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll My_Rand(ll Mod) { return (ull)(rnd()) % Mod; }

template<class T1, class T2>
T1 Min(const T1 x, const T2 y) { return x > y ? y : x; }
template<class T1, class T2>
T1 Max(const T1 x, const T2 y) { return x > y ? x : y; }

template<class T1, class T2>
void To_max(T1 &x, const T2 y) { x < y ? x = y : x = x; }
template<class T1, class T2>
void To_min(T1 &x, const T2 y) { x > y ? x = y : x = x; }

il ll qmul(ll x, ll y, ll p) {
	ll l = x * (y >> 25) % p * (1 << 25) % p;
	ll r = x * (y & ((1 << 25) - 1)) % p;
	return (l + r) % p;	
}

il ll qpow(ll n, ll base, ll mod = 1e18) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = ret * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return ret % mod;
}

il ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
il ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

void InitHash(ull &base, int &prime, ull &mod) { base = 131, prime = 233317, mod = 212370440130137957ll; } 
//header

#define Node pair<pii, int>

def(N, int, 305)
def(M, int, N * N)

int n, m;
int len;
Node x[M];
int y[N][N];

bool cmp(Node a, Node b) { return a.fi.fi == b.fi.fi ? a.fi.se < b.fi.se : a.fi.fi < b.fi.fi; }
bool Cmp(Node a, Node b) { return a.fi.se < b.fi.se; }

struct BIT {
	int sz;
	int t[N];
	
	void init() { sz = m + 1; rep(i, 0, sz) t[i] = 0; }
	
	int lowbit(int x) { return x & (-x); }
	
	void upd(int x, int v) { while(x <= sz) t[x] += v, x += lowbit(x); }
	
	int qry(int x) {
		int ret = 0;
		while(x) ret += t[x], x -= lowbit(x);
		return ret;
	}
} tr[N];

int main() {
	int T;
	cin >> T;
	W(T) {
		ll ans = 0;
		qread(n, m);
		len = n * m;
		
		rep(i, 1, n) tr[i].init();
		rep(i, 1, len) qread(x[i].fi.fi), x[i].fi.se = i;
		
		sort(x + 1, x + len + 1, cmp);
		rep(i, 1, len) x[i].se = i;
		sort(x + 1, x + len + 1, Cmp);
		
		rep(i, 1, len) {
			int X = (x[i].se - 1) / m + 1, Y = (x[i].se - 1) % m + 1;
			y[X][Y] = x[i].fi.fi;
			ans += tr[X].qry(Y);
			tr[X].upd(Y, 1);
		}
		rep(i, 1, len) {
			int X = (x[i].se - 1) / m + 1, Y = (x[i].se - 1) % m + 1;
			tr[X].upd(Y, -1);
		}
		
		rep(i, 1, n) {
			int nw = 0, len = 0;
			y[i][m + 1] = -1;
			rep(j, 1, m + 1) if(y[i][j] != nw) {
				ans -= 1ll * len * (len - 1) / 2;
				len = 1, nw = y[i][j];
			}
			else ++len;
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}