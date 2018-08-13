#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int m,n,w[3403],c[3403],f[3403][12881];
int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;++i)
        cin >> w[i] >> c[i];
    for (int i=1;i<=n;++i)
        for (int v=m;v>0;--v)
            {
                if (w[i] <= v)
                    f[i][v] = max(f[i-1][v],f[i-1][v-w[i]]+c[i]);
                else f[i][v] = f[i-1][v];
            }
    cout << f[n][m];
    return 0;
}