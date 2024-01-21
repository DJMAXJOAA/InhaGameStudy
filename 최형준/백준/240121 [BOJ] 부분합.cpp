[BOJ] 부분합 / 골드4 / https://www.acmicpc.net/problem/1806
범위를 제한하는 문제는 투포인터로 해결

#include <bits/stdc++.h>
using namespace std;
int n, s;
vector<int> a;
int ans = INT_MAX;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		a.push_back(val);
	}

	int en = 0;
	int cur = a[0];
	for (int st = 0; st < n; st++) {
		while (en < n && cur < s) {
			if (++en == n) break;
			cur += a[en];
		}
		if (en == n) break;
		ans = min(ans, en - st + 1);
		cur -= a[st];
	}
	if (ans == INT_MAX) ans = 0;
	cout << ans;
}