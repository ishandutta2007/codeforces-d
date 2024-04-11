#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

string t[]={"6", "7", "8", "9", "T", "J", "Q", "K","A"};

int main()
{
    ios_base::sync_with_stdio(0);
    char tr;cin>>tr;
    string s1,s2;
    cin>>s1>>s2;
    int a=find(t,t+9,s1.substr(0,1))-t;
    int b=find(t,t+9,s2.substr(0,1))-t;
    if (s1[1]==tr)
    {
        if (s2[1]!=tr)
        {
            cout<<"YES";
            return 0;
        }
        else if (a>b) cout<<"YES";
        else cout<<"NO";
        return 0;
        
    }
    else
    {
        if (s2[1]==tr)
        {
            cout<<"NO";
            return 0;
        }
        if (s2[1]==s1[1] && a>b)
        {
            cout<<"YES";
        }
        else cout<<"NO";
    }

    return 0;
}