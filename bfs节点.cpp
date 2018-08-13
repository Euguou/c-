#include <cstdio>
#include <vector>
#include <queue>
#include <cstring> 
#include <iostream>
#include <string>
#include <cstring>    
#include <algorithm>
#include <ctime>
#include <cmath>
 
using namespace std;
 
int n, m, d[100005];
vector <int> G[100005];
queue <int> Q;
queue <double> A; 
int v[1001];

int main()
{
	 
	scanf("%d%d", &n, &m) ;
	for(int i = 1; i <= m; i++)
	{
		int a, b; scanf("%d%d", &a, &b) ;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int s , t;
	scanf ("%d%d", &s, &t);
	if (s == t) 
	{
		printf ("0\n");
		return 0;
	}
	memset (d , -1 , sizeof (d));
	Q.push(s);
	d[s] = 0;
	{
		int now = Q.front();
		Q.pop();
		for(int i = 0; i < G[now].size(); i++)
		{
			 
			int nxt = G[now][i];
			if ( d[nxt] < 0)
			{
				d[nxt] = d[now] + 1;
				Q.push(nxt);
			}
		}
	}
	if ( d[t] < 0) 
	printf ("-1\n");
	else
	printf ( "%d\n" , d[t]-1);
	return 0;
}
