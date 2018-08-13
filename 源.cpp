#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define maxn 500000

using namespace std;

int f[maxn],ans1,ans2;

int rf(int a)
{
	if (f[a])
	{
		f[a] = rf(f[a]);
		return f[a];
	}
	else return a;
}

void merge(int a, int b)
{
	if (rf(a) != rf(b))
	{
		f[rf(a)] = rf(b);
	}
}

int main()
{
	int N, M, P, Q;
	cin >> N >> M >> P >> Q;
	for (int i = 1; i <= P; i++)
	{
		int zx1, zy1;
		cin >> zx1 >> zy1;
		merge(zx1, zy1);
	}
	for (int i = 1; i <= Q; i++)
	{
		int fx1, fy1;
		cin >> fx1 >> fy1;
		merge(-fx1 + N, -fy1 + N);
	}
	for (int i = 1; i <= N; ++i)
		if (rf(i) == rf(1))
			ans1++;
	for (int i = N + 1; i <= N + M; ++i)
		if (rf(i) == rf(N + 1))
			ans2++;
	int O=min(ans1, ans2);
	cout << O << endl;
	return 0;
}