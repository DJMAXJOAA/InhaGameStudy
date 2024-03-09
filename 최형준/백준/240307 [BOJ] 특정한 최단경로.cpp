[BOJ] 특정한 최단 경로 / 골드4 / /https://www.acmicpc.net/problem/1504
### 그래프, 최단 경로 탐색
1. 이동 불가능한 경우의 예외처리를 잘 해주자
더한 결과가 음수값이 나오는 경우가 있어서, 문제 풀이가 지연되었다
플로이드의 검색 결과는 음수값이 나올 수 없으니 추가적으로 예외처리 해주기

2. 무방향 그래프인 경우 간선 입력 시 반대편 간선도 추가해주어야 한다.
방향 그래프처럼 문제를 풀었다가 문제 풀이가 지연됨

3. 다익스트라 알고리즘으로 동일하게 풀이가 가능하다
1, v1, v2 기준 나머지 정점으로 이동하는 경우를 모두 계산
동일하게 2가지 경우를 비교하여 비용이 적게 드는 경우를 반환

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, e;
int v1, v2;
int d[801][801];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
		d[b][a] = min(d[b][a], c);	// 무방향 그래프 처리
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	cin >> v1 >> v2;

	// 플로이드 알고리즘으로 모든 정점의 이동 비용 계산
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	// 두 루트 중 더 값이 적은 경우
	long long v1_result = d[1][v1] + d[v1][v2] + d[v2][n];
	long long v2_result = d[1][v2] + d[v2][v1] + d[v1][n];
	// 이동이 불가능한 경우 -> 0 < result < INF 예외 처리
	if ((v1_result >= INF || 0 > v1_result)
		&& (v2_result >= INF || 0 > v2_result)) cout << -1;
	else cout << min(v1_result, v2_result);
}