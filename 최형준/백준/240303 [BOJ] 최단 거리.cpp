[BOJ] 최단 거리 / 골드4 / https://www.acmicpc.net/problem/1753
### 다익스트라 알고리즘
1. 오름차순 우선순위 큐 선언(비용, 다음 정점)
2. 첫 시작점을 큐에 push(0, 시작점)
3. 우선순위 큐에서 가장 거리가 짧은 원소 선택, 최단 거리테이블과 비교하여 값이 다르면(작으면) 넘어감
	- 거리순으로 뽑기 때문에 사실 작을 일이 없음(= 값이 다르다로 체크)
4. 큐에서 비용이 제일 작은 노드 기준 이동가능한 정점들 비용 체크
	- 최단거리 배열보다 작으면 큐에 넣고 값 갱신(계산 비용, 해당 정점)
5. 우선순위 큐가 빌때까지 3, 4번 과정 반복

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int v, e;	// 정점 갯수, 간선 갯수
int k;	// 시작점
vector<pair<int, int>> adj[20002];	// 각 정점이 가지고 있는 간선 (비용, 이동할 정점)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 오름차순 우선순위 큐
int d[20002];	// 최단거리 테이블
const int INF = 0x3f3f3f3f;
void func(int st) {
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
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });	// 비용, 이동 정점
	}
	fill(d, d + v + 1, INF);	// 배열을 무한대(이동 불가)로 초기화
	func(k);
}