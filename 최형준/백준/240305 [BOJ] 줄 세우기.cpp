[BOJ] 줄 세우기 / 골드3 / /https://www.acmicpc.net/problem/2252
### 위상 정렬
1. 위상 정렬은 코딩테스트로 자주 나오는 유형은 아니지만, 게임에서 스킬 트리나 전후 관계가 필요한 경우에 자주 사용되니까 익혀두는 게 좋을듯 함
2. 출력 순서가 달라질 수 있다는 점, 전 - 후 관계가 명확하다는 점을 기억하기

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[32001];
int deg[32001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);	// 상대적으로 키가 가장 작은 학생들
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (auto nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}
	for (auto x : result) cout << x << ' ';
}