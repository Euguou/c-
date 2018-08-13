#include <algorithm>
#include <iostream> 
#include <cstdio> 
#include <queue>
using namespace std;

char a[1001][10001];
int b[1001][1001]={1};
int sum;
int x,y;
bool judge()
{
	return !a[x][y];
}
void dfs(char x)
{
	b[x][y] = 1;
	if (b[x + 1][y] && a[x + 1][y]=='#')  dfs(x + 1, y);
	if (b[x][y + 1] && a[x][y + 1]=='#')  dfs(x, y + 1);
	if (b[x - 1][y] && a[x - 1][y]=='#')  dfs(x - 1, y);
	if (b[x][y - 1] && a[x][y - 1]=='#')  dfs(x, y - 1);
}

int main()
{
	freopen("graph.in", "w", stdin);
	freopen("graph.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	sum = 0 ;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s",b[i]+1) ; 
	}
	return 0;
}
