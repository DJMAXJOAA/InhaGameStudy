[BOJ] 그림 / 실버1 / https://www.acmicpc.net/problem/1926
BFS 체크를 여러군데 해야 할때 (연결 그래프가 아닐때 BFS 순회)

#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> v;
bool dist[501][501];
int n, m;
int pic, cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int val;
			cin >> val;
			v[i][j] = val;
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] || v[i][j] == 0) continue;
			pic++;
			q.push({ j, i });
			dist[i][j] = true;
			int cur = 1;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int idx = 0; idx < 4; idx++) {
					int xidx = x + dx[idx];
					int yidx = y + dy[idx];
					if (xidx >= 0 && xidx < m && yidx >= 0 && yidx < n &&
						!dist[yidx][xidx] && v[yidx][xidx] == 1) {
						cur++;
						dist[yidx][xidx] = true;
						q.push({ xidx, yidx });
					}
				}
			}
			cnt = max(cnt, cur);
		}
	}

	cout << pic << '\n' << cnt;
}