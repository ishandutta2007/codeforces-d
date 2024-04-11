#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int n, a[300005];
int dp[300005];
int pos1, pos2, pos3, pos4;
int main(){
    read(n);int cc = -0x3f3f3f3f;
    for (register int i = 1;i <= n;i ++) read(a[i]), chmax(cc, a[i]);
    if(n & 1) pos1 = pos2 = (n >> 1) + 1;
    else pos3 = pos4 = (n >> 1) + 1;
    if(n & 1) pos3 = pos1, pos4 = pos1 + 1;
    else pos1 = pos3 - 1, pos2 = pos4;
    for (register int k = n;k >= 1;k --){
        if(k & 1){
            dp[k] = mx(dp[k + 2], mx(mx(mn(a[pos1], a[pos1 - 1]), mn(a[pos2], a[pos2 + 1])), mx(mn(a[pos2], a[pos2 - 1]), mn(a[pos2], a[pos2 + 1]))));
            pos1 --;pos2 ++;
        }
        else{
            dp[k] = mx(dp[k + 2], mx(mx(a[pos3 - 1], a[pos3]), mx(a[pos4 - 1], a[pos4])));
            pos3 --;pos4 ++;
        }
    }
    for (register int i = 0;i < n - 1;i ++) fprint(dp[n - i], 32);
    fprint(cc, 10);
    return 0;
}