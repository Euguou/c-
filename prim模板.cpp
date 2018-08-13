#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

const int N = 1010;
int n, m, dist[N], used[N];

struct Edge {
	int to, len;
};

vector <Edge> E[N];

int Prim() {
	memset(dist, 0x3f, sizeof(dist));
	int now = 1, ans = 0;
	while (1)
	{
		used[now] = 1;
		for (int j = 0; j<E[now].size(); j++)
		{
			dist[E[now][j].to] = min(dist[E[now][j].to], E[now][j].len);
		}
		now = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!used[j] && (now<0 || dist[j]<dist[now])) now = j;
		}
		if (now<0)
		{
			break;
		}
		else
		{
			ans += dist[now];
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i<m; i++)
	{
		int s, t, d;
		cin >> s >> t >> d;
		E[s].push_back((Edge) { t, d });
		E[t].push_back((Edge) { s, d });
	}
	printf("%d\n", Prim());
	return 0;
}
