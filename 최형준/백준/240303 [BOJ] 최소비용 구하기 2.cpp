[BOJ] 최소비용 구하기 / 골드3 / https://www.acmicpc.net/problem/11779
### 다익스트라 알고리즘
1. 경로 복구용 pre 배열 추가
2. pre배열의 각 인덱스는 정점의 부모 노드가 연결된다
3. 최단거리 탐색 종료 시 vector<int> 배열을 추가하여 경로를 입력
4. 입력된 경로를 뒤집으면 이동 경로 복원 완료

// BOJ 11779 최소비용 구하기 2
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int v, e;	// 정점 갯수, 간선 갯수
int st, en;	// 시작, 도착점
vector<pair<int, int>> adj[1005];	// 각 정점이 가지고 있는 간선 (비용, 이동할 정점)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 오름차순 우선순위 큐
int d[1005];	// 최단거리 테이블
int pre[1005];	// 경로 복원 테이블
const int INF = 0x3f3f3f3f;

void func(int st, int en) {
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
				pre[nxt.Y] = vertex;	// 경로 복원
				pq.push({ d[nxt.Y], nxt.Y });
			}
		}
	}
	vector<int> route;
	int idx = en;
	while (idx != st) {
		route.push_back(idx);
		idx = pre[idx];
	}
	route.push_back(idx);
	reverse(route.begin(), route.end());	// 경로 뒤집기

	cout << d[en] << '\n';
	cout << route.size() << '\n';
	for (auto i : route)
		cout << i << ' ';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });	// 비용, 이동 정점
	}
	fill(d, d + v + 1, INF);	// 배열을 무한대(이동 불가)로 초기화
	cin >> st >> en;
	func(st, en);
}