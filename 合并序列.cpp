#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int n;
	map<string, int>vis;
	string t, a[100001];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> t;
	vis[t] = 1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (vis[a[i].substr(0, t.length())])
		{
			cout << a[i] << endl;
		}	
	}
	return 0;
}