[BOJ] 카드 정렬하기 / 골드4 / https://www.acmicpc.net/problem/1715
그리디 알고리즘 + 우선순위 큐, 데이터 압축과 같은 원리

#include <bits/stdc++.h>
using namespace std;
int n, ans;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		pq.push(val);
	}
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans;
}