#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Edge {
	int to, len;
};

vector <Edge> E[10010];
void add_edge(int from, int to, int len) {
	E[from].push_back((Edge) { to, len });
}

long long dist[10010];
int N, M, S;
bool used[10010];
void Dijkstra() {
	for (int i = 1; i <= N; i++) dist[i] = (i == S ? 0 : 2147483647);
	int now = S;
	while (now >= 0) {
		used[now] = 1;
		for (int i = 0; i<E[now].size(); i++) {
			if (dist[E[now][i].to]>dist[now] + E[now][i].len)
				dist[E[now][i].to] = dist[now] + E[now][i].len;
		}
		int minn = -1;
		for (int i = 1; i <= N; i++) {
			if (!used[i] && (minn<0 || dist[i]<dist[minn]))
				minn = i;
		}
		now = minn;
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i<M; i++) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		add_edge(u, v, d);
	}
	Dijkstra();
	for (int i = 1; i <= N; i++) printf(i<N ? "%lld " : "%lld\n", dist[i]);
	return 0;
}