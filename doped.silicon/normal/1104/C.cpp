#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
/*Author Ritick Goenka || ritick(codechef) ||doped.silicon(codeforces) */
/*IIT Roorkee = <3 */
#define ll long long
#define int long long

#define ld double
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define INF 1000000000000000
#define MOD 1000000007

signed main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(11);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        string s;
        cin>>s;
        ll x=1,y=1;
        rep(i,s.length())
        {
            if(s[i]=='0')
            {
                if(x==1)
                {
                    cout<<"1 1"<<endl;
                    x+=2;
                }
                else if(x==3)
                {
                    cout<<"3 1"<<endl;
                    x=1;
                }
            }
            else
            {
                cout<<y<<" 2"<<endl;
                y++;
                if(y==5)
                    y=1;
            }
        }
            return 0;

}