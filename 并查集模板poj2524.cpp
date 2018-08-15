//http://poj.org/problem?id=2524
#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
const int N = 50005;
 
int f[N];
int n, m;
 
void init() {
    for (int i = 1; i <= n; i++) 
        f[i] = i; 
}
 
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
 
void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) {
        f[pa] = pb;
    }
}
 
int main() {
    int t = 1;
    while (scanf("%d %d", &n, &m) && n && m) {
        init();   
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b); 
                Union(a, b);
        }  
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (f[i] == i)
                cnt++;
        printf("Case %d: %d\n", t++, cnt);
    }
    return 0;
}
