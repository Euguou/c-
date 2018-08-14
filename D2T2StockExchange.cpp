#include<stdio.h>
#include<algorithm>
using namespace std;
#define INF 1<<30
int main()
{
    int n, a[100010], dp[100010];
 
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d", a+i);
            dp[i] = INF;
        }
        for(int i=0; i<n; i++)
            *lower_bound(dp, dp+n, a[i]) = a[i];
        printf("%d\n", lower_bound(dp, dp+n, INF)-dp);
    }
    return 0;
}

