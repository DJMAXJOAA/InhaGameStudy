[BOJ] RGB �Ÿ� / �ǹ�1 / https://www.acmicpc.net/problem/1149
1. �׸���� ������ ��, ���̳��� ���α׷������� Ǯ���� �� �Ǵ��� �� �ؾ� �Ѵ�.
- �׸���� ������ ���� Ž�� ������ ���̴� ������, �׻� ������ �ذ� ������ �ʴ´�.
	- Ž�� ������ �ٿ��� �ùٸ� ����� ������ �����ؾ� �Ѵ�.
	- ���� ������ �ٲ㵵(���� ���ѵ�) ���� Ǯ�̿� ������ ������ ? (���� ������ X)
	- [���� �����층 ����](www.acmicpc.net/problem/1931), [���� ��� ����](www.acmicpc.net/problem/11047)

2. ���� �׸��� Ǯ�̰� Ʋ���ٸ� ������ �����ϰ� �ٸ� Ǯ�̸� ����ϴ� ���� ����.
-���� Ǯ���� ���缺�� �Ĳ��ϰ� üũ�ϱⰡ ��ƴ�(���� �����Ѵ�)

#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
vector<vector<int>> house;
vector<vector<int>> dp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	house.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int val;
			cin >> val;
			house[i].push_back(val);
		}
	}
	dp.resize(n, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		dp[0][i] = house[0][i];
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}
	ans = min(dp[n - 1][0], dp[n - 1][1]);
	ans = min(ans, dp[n - 1][2]);
	cout << ans;
}