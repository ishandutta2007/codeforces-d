//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: ????
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
int n,w,h;
vector<int> x[Maxn*2],y[2*Maxn];
int sx[Maxn*2],sy[Maxn*2];
pair<int,int> ans[Maxn];
struct ev{
	int gr,pos,t,num;
}e[Maxn];
bool cmp(ev x,ev y){
	if (x.gr!=y.gr) return x.gr<y.gr;
	if (x.pos!=y.pos) return x.pos<y.pos;
	return x.t<y.t;
}
int main(){
	scanf("%d %d %d",&n,&w,&h);
	//memset(x,-1,sizeof(x));
	//memset(y,-1,sizeof(y));
	for (int i=0;i<n;i++){
		int tp,p,t;
		scanf("%d %d %d",&tp,&p,&t);
		e[i].gr=tp;
		e[i].pos=p;
		e[i].t=t;
		e[i].num=i+1;
		//cout<<p-t+Maxn<<endl;
		if (tp==1){
			x[p-t+Maxn].push_back(p);
		}
		else{
			y[p-t+Maxn].pb(p);
		}
		//cerr<<i<<endl;
	}
	for (int i=0;i<2*Maxn;i++){
		sort(x[i].begin(),x[i].end());
		sort(y[i].begin(),y[i].end());
		sx[i]=x[i].size();
		sy[i]=y[i].size();
	}
	sort(e,e+n,cmp);
	int i;
	for (i=0;i<n && e[i].gr==1;i++){
		// c: XXXXX
		int tmp=e[i].pos-e[i].t+Maxn;
		if (y[tmp].empty()){
			ans[e[i].num]=mp(e[i].pos,h);
			continue;
		}
		//int y=*y[tmp].begin();
		int szy=y[tmp].size()-1,szx=sx[tmp]--;
		szx--;
		int diff=abs(szx-szy);
		int ffy=y[tmp].size()-diff,ffx=x[tmp].size()-diff;
		if (szx>szy){
			ans[e[i].num]=mp(x[tmp][ffx],h);
		}
		else{
			ans[e[i].num]=mp(w,y[tmp][ffy-1]);
		}
	}
	for (;i<n;i++){
		// c: YYYYY
		int tmp=e[i].pos-e[i].t+Maxn;
		if (x[tmp].empty()){
			ans[e[i].num]=mp(w,e[i].pos);
			continue;
		}
		//int y=*y[tmp].begin();
		int szx=x[tmp].size()-1,szy=sy[tmp]--;
		szy--;
		int diff=abs(szx-szy);
		int ffx=x[tmp].size()-diff,ffy=y[tmp].size()-diff;
		if (szy>szx){
			ans[e[i].num]=mp(w,y[tmp][ffy]);
		}
		else{
			ans[e[i].num]=mp(x[tmp][ffx-1],h);
		}
	}
	for (int i=1;i<=n;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}