[BOJ] 트리의 지름 / 골드2 / /https://www.acmicpc.net/problem/1167
### 그래프 탐색 (DFS)
1. 무방향 그래프에서 길이를 찾을 때는 vistied 배열을 사용하는 DFS를 사용할 것
	- 무방향 그래프에서 BFS를 사용하면 양방향 간선에서 중복되는 그래프를 처리하기가 까다로워진다
	- 이 경우 메모이제이션을 적용하면 가능하지만, 해당 방법은 정점이 많지 않을 때만 가능하다. (플로이드, DP)
2. 크루스칼 알고리즘은 신장 트리를 만드는 알고리즘이고, 아예 다른 접근법이였음

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int v;
vector<pair<int, int>> adj[100002];	// 다음 정점, 비용
bool visited[100002];	// 무방향 그래프이기 때문에 방문처리
int maxNode, maxDist;	// 1차 dfs에서 가장 먼 정점, 결과값

void dfs(int index, int dist) {
	if (visited[index])
		return;

	visited[index] = true;
	if (dist > maxDist) {
		maxNode = index;
		maxDist = dist;
	}
	for (auto& nxt : adj[index]) {
		dfs(nxt.X, dist + nxt.Y);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int nxt, dist;
		int st;
		cin >> st;
		do {
			cin >> nxt;
			if (nxt == -1) break;
			cin >> dist;
			adj[st].push_back({ nxt, dist });
		} while (nxt != -1);
	}

	// 1차 dfs : 임의의 정점(1)에서 가장 먼 정점 찾기
	fill(visited, visited + v + 1, false);
	dfs(1, 0);
	// 2차 dfs : 해당 정점에서 제일 먼 정점이 최종 결과
	fill(visited, visited + v + 1, false);
	dfs(maxNode, 0);
	cout << maxDist;
}