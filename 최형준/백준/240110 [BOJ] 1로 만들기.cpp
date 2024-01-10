[BOJ] 1로 만들기 / 실버3 / https://www.acmicpc.net/problem/1463
DP로 풀이 가능, DFS 가지치기

#include <bits/stdc++.h>
using namespace std;

int mini = INT_MAX;

int DFS(int val, int depth)
{
	if (val < 1) return INT_MAX;
	else if (val == 1) return depth;

	if (depth >= mini) return INT_MAX;

	if (val % 3 == 0)
		mini = min(mini, DFS(val / 3, depth + 1));
	if (val % 2 == 0)
		mini = min(mini, DFS(val / 2, depth + 1));
	mini = min(mini, DFS(val - 1, depth + 1));

	return mini;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;
	cout << DFS(x, 0);
}