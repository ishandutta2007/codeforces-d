#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[103];
int main(){
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	a[n]=a[0];
	int ans1=0,ans2=1,num=abs(a[1]-a[0]);
	for (int i=1;i<n;i++){
		if (abs(a[i+1]-a[i])<num){
			ans1=i;
			ans2=i+1;
			num=abs(a[i+1]-a[i]); 
		}
	}
	cout<<ans1%n+1<<" "<<ans2%n+1;
	return 0;
}