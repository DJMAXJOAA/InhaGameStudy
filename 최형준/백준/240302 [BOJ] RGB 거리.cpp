[BOJ] RGB 거리 / 실버1 / https://www.acmicpc.net/problem/1149
1. 그리디로 접근할 지, 다이나믹 프로그래밍으로 풀이할 지 판단을 잘 해야 한다.
- 그리디는 관찰을 통해 탐색 범위를 줄이는 것으로, 항상 최적의 해가 나오지 않는다.
	- 탐색 범위를 줄여도 올바른 결과가 나올지 예측해야 한다.
	- 접근 순서를 바꿔도(정렬 시켜도) 문제 풀이에 지장이 없는지 ? (지장 있으면 X)
	- [간격 스케쥴링 문제](www.acmicpc.net/problem/1931), [동전 계산 문제](www.acmicpc.net/problem/11047)

2. 만약 그리디 풀이가 틀린다면 빠르게 손절하고 다른 풀이를 사용하는 것이 좋다.
-문제 풀이의 정당성을 꼼꼼하게 체크하기가 어렵다(감에 의존한다)

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