#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

struct state
{
	int x, y, z;
}; 

queue <state> q;

int A, B, C;
bool vis[101][101];

void push2(state t)
{
	if (vis[t.x][t.y])
	{
		vis[t.x][t.y] = 1;
		q.push(t);
	}
}

void spread(state t)
{
	push2((state) { 0, t.y, t.z + 1 });
	push2((state) { t.x, 0, t.z + 1 });
	push2((state) { A, t.y, t.z + 1 });
	push2((state) { t.x, B, t.z + 1 });
	if(t.x>(B-t.y))
		push2((state){t.x-(B-t.y),B,t.z+1});
	else
	{
		push2((state){0,t.y+t.x,t.z+1});
	}
	if(t.y>(A-t.x))
	{
		push2((state){A,t.y-(A-t.x),t.z+1});
	}
	else
	{
		push2((state){t.x+t.y,0,t.z+1});
	}
}

int bfs()
{
	q.push((state) { 0, 0, 0 });
	while(!q.empty())
	{
		state t = q.front();
		if (t.x == C || t, y == C)
			return t.z;
		q.pop();
	}
}

int main()
{
	cin >> A >> B >> C;
	int ans = bfs();
	if (ans < 0)
		cout << "impossible";
	else
		cout << ans;
	return 0 ;
}
