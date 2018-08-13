#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
int a[1000001];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N; i++)
	{
		sort(a, a + i+1);
		if (i % 2 != 0)
		{
			continue;
		}
		else
		{
			cout << a[i / 2] << endl;
		}
	}
	return 0;
}