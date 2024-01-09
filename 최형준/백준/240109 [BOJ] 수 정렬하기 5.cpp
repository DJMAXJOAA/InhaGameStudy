[BOJ] �� �����ϱ� 5 / �ǹ�5 / https://www.acmicpc.net/problem/15688
ī���� ����

#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int val;
	for (int i = 0; i < n; i++)
	{
		cin >> val;

		if (mp.count(val) > 0) mp[val]++;
		else mp[val] = 1;
	}
	for (auto& it : mp)
	{
		for (int i = 0; i < it.second; i++)
		{
			cout << it.first << "\n";
		}
	}
}