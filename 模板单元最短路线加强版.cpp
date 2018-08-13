#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#define M(x,y) make_pair(x,y)

using namespace std;

int fr[100010], to[200010], nex[200010], v  [200010], tl, d[100010];
bool b[100010];

void add(int x, int y, int w) {
	to[tl++] = y;
	
	v[tl] = w;
	nex[tl] = fr[x];
	fr[x] = tl;
}

priority_queue< pair<int, int> > q;

int main() {
	int n, m, x, y, z, s;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
	}
	for (int i = 1; i <= n; i++) d[i] = 1e10;
	d[s] = 0; 
	q.push(M(0, s));
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (b[x]) continue;
		b[x] = 1;
		for (int i = fr[x]; i; i = nex[i]) {
			int y = to[i], l = v[i];
			if (d[y]>d[x] + l) {
				d[y] = d[x] + l;
				q.push(M(-d[y], y));
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
	return 0;
}
