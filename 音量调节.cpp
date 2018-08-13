#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int dp[10001][10001];
int N, beginLevel, maxLevel, c, a[1001];

int main()
{
	cin >> N >> beginLevel >> maxLevel;
	for (int i= 0; i < N; i++)
	{
		cin >> c;
	}
	dp[0][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= maxLevel; j++) {
			if (dp[i - 1][j] && j + a[i] <= maxLevel) dp[i][j + a[i]] = 1;
			if (dp[i - 1][j] && j - a[i] >= 0) dp[i][j - a[i]] = 1;
		}
	}
	for (int i = maxLevel; i >= 0; i--) {
		if (dp[N][i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}