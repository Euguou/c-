#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
int dp[200][200];
int a[200][200];
int ans;

int main()
{
	int M, N;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
			}
			ans = max(ans, dp[i][j]);
		}
	cout << ans << endl;
}