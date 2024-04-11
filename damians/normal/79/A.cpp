#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
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
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }



int main()
{
    ios_base::sync_with_stdio(0);
    int x,y;
    cin>>x>>y;
    int ruch=0;
    while(1)
    {
        if (ruch==0)
        {
            if (x>=2 && y>=2)
            {
                x-=2;
                y-=2;
            }
            else if (x>=1 && y>=12)
            {
                x-=1;
                y-=12;
            }
            else if (y>=22)
            {
                y-=22;
            }
            else
                break;
        }
        else
        {
            if (y>=22)
            {
                y-=22;
            }
            else if (x>=1 && y>=12)
            {
                x-=1;
                y-=12;
            }
            else if (x>=2 && y>=2)
            {
                x-=2;
                y-=2;
            }
            else
                break;
        }
        
        ruch=1-ruch;
    }
    if (!ruch) cout<<"Hanako";
    else cout<<"Ciel";
    return 0;
}