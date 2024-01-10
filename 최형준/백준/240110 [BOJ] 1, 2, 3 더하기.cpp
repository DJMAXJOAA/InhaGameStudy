[BOJ] 1, 2, 3 더하기 / 실버3 / https://www.acmicpc.net/problem/9095
그냥 dp 연습문제

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp(100);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		cout << dp[val] << '\n';
	}
}