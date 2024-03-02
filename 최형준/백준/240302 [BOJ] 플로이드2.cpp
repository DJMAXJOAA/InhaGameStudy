[BOJ] 플로이드 2 / 골드3 / https://www.acmicpc.net/problem/11780
플로이드 알고리즘의 시간 복잡도는 정점 V의 개수를 경유지로 하여 모든 단계를 V^2만큼 비교하므로, 시간복잡도는 O(V^3)가 된다.
- 1초당 3억 ~ 5억번의 연산이 가능하니, 노드의 개수가 1000개 까지는 해당 알고리즘을 사용할 수 있음
- 모든 정점 간 최단 경로를 탐색해야 할 경우에 사용

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int INF = 0x3f3f3f3f; // 무한대, 2배 해도 오버플로우 X
vector<vector<int>> nodes;
vector<vector<int>> nxt;	// 경로 복원용
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	nodes.resize(n + 1, vector<int>(n + 1, INF));	// 갈 수 없는 경우를 infinite 처리
	nxt.resize(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		nodes[start][end] = min(nodes[start][end], cost); // start -> end 비용 설정
		nxt[start][end] = end;
	}
	for (int i = 1; i <= n; i++) nodes[i][i] = 0;	// 3. x == y를 0으로 초기화
	for (int i = 1; i <= n; i++) {	// 1~n까지의 경유지 설정
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {
				if (nodes[y][i] + nodes[i][x] < nodes[y][x]) {
					nodes[y][x] = min(nodes[y][x], nodes[y][i] + nodes[i][x]);
					nxt[y][x] = nxt[y][i];	// 경로 설정
				}
			}
		}
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (nodes[y][x] == INF) cout << 0 << ' ';
			else cout << nodes[y][x] << ' ';
		}
		cout << '\n';
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (nodes[y][x] == 0 || nodes[y][x] == INF) {
				cout << 0 << '\n';
				continue;
			}
			int start = y, end = x;
			vector<int> path;
			while (nxt[start][end] != 0) {
				path.push_back(start);
				start = nxt[start][end];	// 시작 경로가 도착 경로와 같을때까지
			}
			path.push_back(end);
			cout << path.size() << ' ';
			for (auto i : path) cout << i << ' ';
			cout << '\n';
		}
	}
}