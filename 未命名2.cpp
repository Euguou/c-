#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

int ans1,ans2;
int j[10001],h[10001];
queue <int> q;
int m, n;
int map[1001][1001];

bool vis[1001];

void bfs()
{
	q.push(1);
	vis[1] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[now][i] && !vis[i])
				j[ans1] = now;
			    ans1++;
				h[ans2] = i;
				ans2++;
				vis[i] = 1;
				q.push(i);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	for (int i = 0; i <= ans1; i++)
		cout << i;
	for (int i = 0; i <= ans2; i++)
		cout << i;
	return 0;
}
