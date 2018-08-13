#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
const int END = 10001;

int a[MAXN][MAXN], f[MAXN][MAXN], n, Ans;

void b(int x, int y, int Sn)
{
	if (x == n)
	{
		if (Sn > Ans)
			Ans = Sn;
		return ;
	}
	b(x + 1, y, Sn + a[x + 1][y]);
	b(x + 1, y + 1, Sn + a[x + 1][y + 1]);
}

queue <int> q;
int d[1000001];

int abc(int t)
{
    for(int i=0;i<=t;i++)
    {

        cin>>d[i];
    }
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
			Ans = 0 ;
			b(1, 1, a[1][1]);
    }
	printf("%d", Ans);
	return 0;
}
