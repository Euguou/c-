#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#define maxn 1000001;
using namespace std;
struct Node
{
	int son[10];
	bool f;
}Trie[1000001];
int cnt, root;
void insert(char phone[])
{
	bool legal = 1, flag = 0;
	int now = root;
	for (int i = 0; phone[i] != '\0'; i++)
	{
		int to = Trie[now].son[phone[i] - '0'];
		if (to)
		{
			now = to;
		}
		else
		{
			Trie[now].son[phone[i] - '0'] = cnt++;
			now = cnt++;
		}
		if (Trie[now].f)
		{
			legal = 0;
		}
	}
	if (flag)
		{
			legal = 0;
		}
	Trie[now].f = 1;
	return legal;
}
int main()
{
	int i, j, t, n;
	char a[11];
	bool abc;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 0)
		{
			cout << "YES" << endl;
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			abc = insert(a);
			if (abc != 0)
			{
				break;
			}
		}
		cout << "NO" <<endl;
		for (int i = 0; i < n; i++)
		{
			
		}
		if (abc[i] == 1)
		{
			cout << "YES"<<endl;
		}
	}
	return 0;
}