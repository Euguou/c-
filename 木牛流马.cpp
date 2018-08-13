#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int N, K, H;
int main()
{
	cin >> N >> K >> H;
	int ans1 = 1, ans2 = 1;
	if (K>N) 
	{
		cout << "0" << endl;
		return 0;
	}
	
	for (int i = 1; i <= H; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			ans1 *= j;
		}
	}
	for (int i = N; i >= N - K + 1; i--)
	{
		ans2 *= i * i;
	}
	int zans = ans2 / ans1;
	cout << zans << endl;
	return 0;
}
