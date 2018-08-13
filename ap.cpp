#include <bits/stdc++.h>

using namespace std;

int  p[10], vis[10];
queue <int> q;

void dfs(int x)
{
	int n;

	if (x > n)
	{
		for (int i = 0; i <= n; i++)
		{
			printf("%d", p[i]);
		}
		printf("%d\n");
	}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				vis[i] = 1;
				p[x] = i;
				dfs(x + 1);
				vis[i] = 0;
			}
		}

}
int bfs(int x,int y)
{
    if(x>y) return (x+y)*3/2;
    if(x<y) return (y-x)*3/2;
    if(x=y) return 0;
}
	int main()
	{
		int y;
		cin >> y;
		dfs(y);
		return 0;
	}


