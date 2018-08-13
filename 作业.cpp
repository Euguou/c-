#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int Map[101][101];
int vis[101];

queue <int> q;
vector <int> order;
queue <double> t;
vector <double> Q;

void bfs()
{
	memset(vis, -1, sizeof(vis));
	q.push(1);
	vis[1] = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		order.push_back(now);
		for (int i = 1; i <= N; i++)
		{
			if (Map[now][1] && vis[i] < 0)
			{
				vis[i] = vis[now] + 1;
				q.push(i); 
			}
		}
	 }
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Map[a][b] = Map[b][a] = 1;
	}
	bfs();
	for (int i = 1; i < order.size() ; i++)
	{
		printf(i < order.size() - 1 ? "%d " : "%d\n", order[i]);
	}
	for(int i = 0 ; i <= N ; i++)
	{
		printf(i < N ? "%d " : "%d\n", vis[i]);
	}
	return 0;
}
