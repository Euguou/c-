#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int a, b;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			q.push(b);
		}
		if (a == 2)
		{
			int c;
			c = q.top();
			printf("%d\n",c);
		}
		if(a==3)
		{
			q.pop();
		}
	}
	return 0;
}