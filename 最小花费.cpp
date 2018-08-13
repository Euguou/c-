#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int dui[200100];
double minn[2010];
vector<double> g[2010];
vector<int> man[2010];
int main()
{
	int n, m, a, b, x, y, head = 1, tail = 1, now, i;
	double z;
	memset(minn, 127, sizeof(minn));
	cin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %lf", &x, &y, &z);
		z = z / 100.0;
		z = 1.0 - z;
		g[x].push_back(z);
		g[y].push_back(z);
		man[x].push_back(y);
		man[y].push_back(x);
	}
	cin >> a >> b;
	dui[1] = a;
	minn[a] = 100.0;
	while (head >= tail)
	{
		now = dui[tail];
		for (i = 0; i<man[now].size(); i++)
		{
			if (minn[man[now][i]]>minn[now] / g[now][i])
			{
				minn[man[now][i]] = minn[now] / g[now][i];
				head++;
				dui[head] = man[now][i];
			}
		}
		tail++;
	}
	printf("%.8lf\n", minn[b]);
	return 0;
}