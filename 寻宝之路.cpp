#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m,sum,a[101][101],b[10001];

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
	{
    	cin>>b[i];
 	}
    for (int i=1;i<=n;i++)
    {
    	for (int j=1;j<=n;j++)
    	{
    		scanf("%d",&a[i][j]);
		}
	}
    for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i!=j&&j!=k&&k!=i&&a[i][j]>a[i][k]+a[k][j])  
				{
					a[i][j]=a[i][k]+a[k][j] ;
				}
			}
		}
	} 
    for(int i=1;i<=m;i++)
    {
    	sum+=a[b[i-1]][b[i]];
	}
    cout<<sum<<endl;
    return 0;
}
