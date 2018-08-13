#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int a[100000];

int main() 
{ 
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	while (1)
	{
		int j = 1;
		while (a[j] == 0)
		{
			j++;
		}
		if (j == n)
		{
			break;
		}
		else 
		{
			a[j] += a[j + 1];
			sum += a[j];
			for (int l = j + 1; l<n; l++)
			{
				a[l] = a[l + 1];
			}
			n--;
		}
		for (int l = j; l<n; l++)
		{
			if (a[l]>a[l + 1])
			{
				swap(a[l], a[l + 1]);
			}
		}
	}
	cout << sum << endl;
	return 0;
}

/*¶ÑÐ´·¨
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstring>
#include <queue>
#include <algorithm> 
using namespace std;
priority_queue<int, vector<int>, greater<int> >q;
int main()
{
	int n, c, d, g, h = 0, sum, z;
	int b;
	cin >> n;
	for (int a = 0; a<n; a++)
	{
		cin >> b;
		q.push(b);
	}
	while (q.size() != 1)
	{
		z = q.top();
		q.pop();
		d = q.top();
		q.pop();
		g = z + d;
		h = h + g;	
		q.push(g);
	}
	cout << h;
	return 0;
}
*/
