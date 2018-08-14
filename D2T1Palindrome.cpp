#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdio>
using namespace std;
short dp[5005][5005];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        getchar();
        memset(dp,0,sizeof(dp));
        char a[5005],b[5005];
        for(int i=1,j=n;i<=n;j--,i++)
        {
            scanf("%c",&a[i]);
            b[j]=a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]==b[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<< n-dp[n][n] <<endl;
    }
    return 0;
}
 
