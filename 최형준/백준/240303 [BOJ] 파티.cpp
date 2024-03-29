[BOJ] 파티 / 골드3 / https://www.acmicpc.net/problem/1238
### 다익스트라 알고리즘
1. 다익스트라 알고리즘을 왕복으로 계산하고, 가장 큰 결과 반환

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int v, e;	// 정점 갯수, 간선 갯수
int st;	// 시작
vector<pair<int, int>> adj[1005];	// 각 정점이 가지고 있는 간선 (비용, 이동할 정점)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 오름차순 우선순위 큐
int d[1005];	// 최단거리 테이블
const int INF = 0x3f3f3f3f;

int func(int st, int en) {
	fill(d, d + v + 1, INF);	// 배열을 무한대(이동 불가)로 초기화
	d[st] = 0;	// 시작점 초기화
	pq.push({ 0, st });
	while (!pq.empty()) {
		int cost = pq.top().X;
		int vertex = pq.top().Y;
		pq.pop();
		if (d[vertex] != cost) continue;	// 최단거리 테이블과 비교해서 다르면 무시 (더 작은경우)
		for (auto& nxt : adj[vertex]) {		// 해당 정점의 간선들을 비교
			if (nxt.X + d[vertex] < d[nxt.Y]) {	// 최단거리 테이블 값 vs 현재 정점 + 이동 비용 비교
				d[nxt.Y] = nxt.X + d[vertex];
				pq.push({ d[nxt.Y], nxt.Y });
			}
		}
	}
	return d[en];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> st;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });	// 비용, 이동 정점
	}
	int ans = 0;
	for (int i = 1; i <= v; i++) {
		ans = max(ans, func(i, st) + func(st, i)); // 왕복이 가장 오래걸리는 경우 체크
	}
	cout << ans;
}