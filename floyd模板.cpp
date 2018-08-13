#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> 
using namespace std;
const int INF = 99999999;
int N, M, dist[1010][1010];
void floyd() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = (i == j ? 0 : INF);
	for (int i = 0; i<M; i++) {
		int s, t, d;
		scanf("%d %d %d", &s, &t, &d);
		dist[s][t] = min(dist[s][t], d);
	}
	floyd();
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			printf(j<N ? "%d " : "%d\n", dist[i][j]);
	return 0;
}