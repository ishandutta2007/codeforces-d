#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

int main(){
	vector<int>	vec(4);
	for (int i = 0; i < 4; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 2; i < 4; i++)
		if (vec[i] < vec[i -1] + vec[i - 2]){
			cout << "TRIANGLE" << endl;
			return 0;
		}
	for (int i = 2; i < 4; i++)
		if (vec[i] == vec[i - 1] + vec[i - 2]){
			cout << "SEGMENT" << endl;
			return 0;
		}
	cout << "IMPOSSIBLE" << endl;
    return 0;
}