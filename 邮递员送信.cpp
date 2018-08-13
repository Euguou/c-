#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

struct edge
{
	int to, l;
}E[1001][1001];

int x[100001], y[100001], z[100001];
int len[1001];
int ans, n, m;
queue <int> q;

void spfa()
{
	bool inque[1001];
	int u, v;
	
	q.push(1); inque[1] = 1;
	int d[1001];
	memset(d, 127, sizeof(d));
	memset(inque, 0, sizeof(inque));
	d[1] = 0;
	while (!q.empty())
	{
		u = q.front(); q.pop(); inque[u] = 0;
		for (int i = 1; i <= len[u]; i++)
		{
			v = E[u][i].to;
			if (E[u][i].l + d[u]<d[v])
			{
				d[v] = E[u][i].l + d[u];
				if (!inque[v])
				{
					q.push(v);
					inque[v] = 1;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
		ans = ans + d[i];
}
int main()
{
	cin >> n >> m;
	edge tmp;
	for (int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
		E[x[i]][++len[x[i]]].to = y[i];
		E[x[i]][len[x[i]]].l = z[i];
	}
	spfa();
	memset(E, 0, sizeof(E));
	memset(len, 0, sizeof(len));
	for (int i = 1; i <= m; i++)
	{
		E[y[i]][++len[y[i]]].to = x[i];
		E[y[i]][len[y[i]]].l = z[i];
	}
	spfa();
	cout << ans << endl;
	return 0;
}