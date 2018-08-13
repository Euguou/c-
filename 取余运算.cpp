#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long int a, b, c;
	cin >> a >> b >> c;
	long long int r = 1, t = a, k = b;
	while (b)
	{
		if (b & 1)
		{
			r = (t*r) % c;
		}
		t = (t*t) % c;
		b = b >> 1;
	}
	cout << a << "^" << k << " " << "mod" << " " << c << "=" << r << endl;
	return 0;
}
