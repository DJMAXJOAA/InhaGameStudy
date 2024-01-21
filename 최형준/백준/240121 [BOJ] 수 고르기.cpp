[BOJ] 수 고르기 / 골드5 / https://www.acmicpc.net/problem/2230
이진 탐색 혹은 투포인터로 풀 수 있음

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		a.push_back(val);
	}
	sort(a.begin(), a.end());
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		auto iter = lower_bound(a.begin(), a.end(), a[i] + m);
		if (iter != a.end())
			ans = min(ans, *iter - a[i]);
	}
	cout << ans;
}