#include <bits/stdc++.h>

using namespace std;

int n,a[110];
int f[110][110];
int l,i,j,k;

int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n-2;i++)
    {
         f[i][i+2]=a[i]*a[i+1]*a[i+2];
    }

    for(l=4;l<=n;l++)
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;f[i][j]=99999999;
            for (k=i+1;k<=j-1;k++)
            {
                 f[i][j]=min(f[i][j],f[i][k]+f[k][j]+a[i]*a[k]*a[j]);
            }

        }
    printf("%d",f[1][n]);
    return 0;
}

