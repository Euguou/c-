#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#define maxn 300000

using namespace std;

int f[maxn];

struct node {
	int x, y, t;
}e[maxn];

int rf(int a)
{
	if (f[a])
	{
		f[a] = rf(f[a]);
		return f[a];
	}
	else return a;
}

int cmp(node a, node b)
{
	return a.t<b.t;
}

int merge(int x)
{
		if (x != f[x]) return f[x] = merge(f[x]);
		return f[x];
}


int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> e[i].x >> e[i].y >> e[i].t;
	}
	sort(e + 1, e + 1 + M, cmp);
	int num = 0, tot = 0;
	for (int i = 1; i <= M; i++)
	{
		int u = merge(e[i].x), v = merge(e[i].y);
		if (u != v)
		{
			f[u] = v;
			num++;
			tot = max(tot, e[i].t);
		}
	}
	if (num >= N - 1) cout << tot << endl;
	else cout << -1 << endl;
	return 0;
}