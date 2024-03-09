[BOJ] 백조의 호수 / 플레1 / /https://www.acmicpc.net/problem/3197
### BFS, A*, 큐
1. 처음 풀어봤던 플레티넘 문제인데, 확실히 매우 어렵다.
   1번 풀이까지는 금방 작성했으나, 시간 초과때문에 총 2시간 넘게 걸렸다..
2. 문제의 접근 방법 자체는 명쾌하나, 시간과 공간 복잡도를 제대로 고려해야 한다
3. 문제를 풀기 전 주어진 범위를 잘 확인해보고, 문제 풀이 방법을 신중하게 선택하자.
4. 다른 풀이방법으로는 Union - Find를 사용하여 분리 집합으로 백조가 같은 집합에 속하는지 확인하는 방법이 있다.

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> l;		// 백조 2마리

// bfs 돌아가는 위치 (백조, 물)
queue<pair<int, int>> waterQ;
queue<pair<int, int>> tmpWaterQ;
queue<pair<int, int>> swanQ;
queue<pair<int, int>> tmpSwanQ;

// 1번 백조가 이동 가능한 지점 체크 (빙하 부분을 다음 이동 지점으로 추가)
bool swanBFS() {
	while (!swanQ.empty()) {
		auto front = swanQ.front(); swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int curX = front.X + dx[i];
			int curY = front.Y + dy[i];
			if (curX >= 0 && curX < c && curY >= 0 && curY < r && !visited[curY][curX]) {
				visited[curY][curX] = true;
				if (grid[curY][curX] == 'L') return true;
				if (grid[curY][curX] == 'X') {
					tmpSwanQ.push({ curX, curY });
				}
				else {
					swanQ.push({ curX, curY });
				}
			}
		}
	}
	return false;
}
// 물과 닿은 빙판을 찾고, 해당 빙판을 녹임 (녹이고 해당 지점 큐에 추가)
void waterBFS() {
	while (!waterQ.empty()) {
		auto front = waterQ.front(); waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int curX = front.X + dx[i];
			int curY = front.Y + dy[i];
			if (curX >= 0 && curX < c && curY >= 0 && curY < r) {
				if (grid[curY][curX] == 'X') {
					grid[curY][curX] = '.';
					tmpWaterQ.push({ curX, curY });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	grid.resize(r, vector<char>(c, '.'));
	visited.resize(r, vector<bool>(c, false));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] != 'X') {	// 빙판 아닌 곳 물 큐에 추가
				waterQ.push({ j,i });
			}
			if (grid[i][j] == 'L') {
				l.push_back({ j,i });
			}
		}
	}
	// 1번 백조 시작 지점
	swanQ.push({ l.front().X, l.front().Y });
	visited[l.front().Y][l.front().X] = true;

	int cnt = 0;
	while (1) {
		// 백조 이동 -> 빙판 녹이기
		if (swanBFS()) {
			break;
		}
		waterBFS();
		// 다음 이동 지점 갱신
		swanQ = tmpSwanQ;
		waterQ = tmpWaterQ;
		tmpSwanQ = queue<pair<int, int>>();
		tmpWaterQ = queue<pair<int, int>>();
		cnt++;
	}
	cout << cnt;
}