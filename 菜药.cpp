#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
long long int w[100001];
int v[100001];
int dp[1001][1001];

int main()
{
	int T,M,q;
	cin>>T>>M;
	for(int i = 0 ; i < M; i++)
	{
		cin>>w[i]>>v[i];
	}
	dp[1][0]=0;
	for(int i=0;i<M;i++)
	{
		for (int j = 0; j <= T; j++)
		{
			if (j >= w[i])
			{
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
			q = dp[i][j];
		}
	}
	cout << q << endl;
	return 0;
}