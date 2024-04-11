/*
    author: DPair
    language: C++

    description:
    Duel!
*/
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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

int a[505][505];
pair <int, int> s[250005];
int main(){
    int T;
    read(T);
    while(T --){
        int n, m;read(n);read(m);int x;
        for (register int i = 1;i <= n;i ++){
            for (register int j = 1;j <= m;j ++){
                read(x);
                s[x].second = j;
            }
        }
        for (register int i = 1;i <= m;i ++){
            for (register int j = 1;j <= n;j ++){
                read(x);
                s[x].first = j;
            }
        }
        for (register int i = 1;i <= n * m;i ++) a[s[i].first][s[i].second] = i;
        for (register int i = 1;i <= n;i ++){
            for (register int j = 1;j <= m;j ++){
                fprint(a[i][j], 32);
            }
        putchar(10);
        }
    }
}