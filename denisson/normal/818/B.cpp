#include <bits/stdc++.h>
     
using namespace std;
     
typedef unsigned long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
    
 
/*const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }*/

int n, m;
int a[107];

const bool is_testing = 0;
int main() { 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    } else {
        //freopen("cpr.in", "r", stdin);
        //freopen("cpr.out", "w", stdout);
    }
    for (int i = 0; i < 107; i++) a[i] = -1;
    cin >> n >> m;
	int last;
	cin >> last;
    for (int i = 0; i < m - 1; i++){
    	int now;
    	cin >> now;

    	int d = now - last;
    	if (d <= 0) d += n;

    	if (a[last] == -1){
    		a[last] = d;
    	} else {
    		if (a[last] != d) cout << -1, exit(0);
    	}

    	last = now;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (a[i] != -1 && a[j] != -1 && i != j) if (a[i] == a[j]) cout << -1, exit(0);

    set<int> se;
    for (int i = 1; i <= n; i++) se.insert(i);
   	for (int i = 1; i <= n; i++) if (a[i] != -1) se.erase(a[i]);
   	for (int i = 1; i <= n; i++){
   		if (a[i] == -1){
   			a[i] = *se.begin();
   			se.erase(se.begin());
   		}
   		cout << a[i] << ' ';
   	}
}