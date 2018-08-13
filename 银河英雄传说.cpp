#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#define maxn 30005

using namespace std;

int n, fa[maxn], c[maxn], b[maxn]; 

int find(int x)
{
	if (fa[x] == 0)
	{
		return x;
	}
	
	int ret = find(fa[x]);
	c[x] += c[fa[x]] - 1;
	fa[x] = ret;
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= 30000; i++)
	{
		b[i] = 1;
		c[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		char opt;
		cin >> opt >> x >> y;
		int ans1, ans2;
		ans1 = find(x);
		ans2 = find(y);
		if (opt == 'M')
		{
			fa[ans1] = ans2;
			c[ans1] = b[ans2] + 1;
			b[ans2] += b[ans1];
		}
		else
		{
			if (ans1 == ans2)
			{
				cout << abs(c[x] - c[y]) - 1 << endl;
			}
			else cout << -1 << endl;
		}
	}
	return 0;
}
