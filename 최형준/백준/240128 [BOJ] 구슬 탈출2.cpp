[BOJ] 구슬 탈출 2 / 골드1 / https://www.acmicpc.net/problem/13460
백트래킹, 시뮬레이션 - 문제 조건을 잘 읽어야함 (파란구슬만 들어가도 아웃인데, 빼먹었다)

#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m, ans = INT_MAX;
vector<vector<char>> board;
bool red, blue;
void Init();
void Func(int count, vector<vector<char>>& v);
bool Move(vector<vector<char>>& v, int dir);
bool Moving(vector<vector<char>>& v, int x, int y, int dir);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Init();
	Func(1, board);
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}
void Init() {
	cin >> n >> m;
	board.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}
void Func(int count, vector<vector<char>>& v) {
	if (count > 10) return;

	for (int i = 0; i < 4; i++) {
		vector<vector<char>> tmp = v;
		if (Move(tmp, i)) {
			ans = min(ans, count);
			return;
		}
		if (blue) continue; // 파랑만 들어갔으면 건너뛰기
		if (tmp == v) continue; // 전이랑 똑같으면 건너뛰기
		Func(count + 1, tmp);
	}
}
bool Move(vector<vector<char>>& v, int dir) {
	red = false, blue = false;
	switch (dir)
	{
	case 0: // 오른쪽
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (v[i][j] == 'R') red = Moving(v, j, i, dir);
				if (v[i][j] == 'B') blue = Moving(v, j, i, dir);
			}
		}
		break;
	case 1: // 아래쪽
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 'R') red = Moving(v, j, i, dir);
				if (v[i][j] == 'B') blue = Moving(v, j, i, dir);
			}
		}
		break;
	case 2: // 왼쪽
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 'R') red = Moving(v, j, i, dir);
				if (v[i][j] == 'B') blue = Moving(v, j, i, dir);
			}
		}
		break;
	case 3: // 위쪽
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] == 'R') red = Moving(v, j, i, dir);
				if (v[i][j] == 'B') blue = Moving(v, j, i, dir);
			}
		}
		break;
	}
	// 빨강 들어갔으면서, 파랑 안들어감
	return red && !blue;
}
bool Moving(vector<vector<char>>& v, int x, int y, int dir) {
	char c = v[y][x];
	int curX = x + dx[dir], curY = y + dy[dir];
	while (0 <= curX && curX < m && 0 <= curY && curY < n) {
		if (v[curY][curX] == 'O') {
			v[y][x] = '.';
			return true;
		}
		if (v[curY][curX] == '#' || v[curY][curX] == 'R' || v[curY][curX] == 'B') {
			v[y][x] = '.';
			v[curY - dy[dir]][curX - dx[dir]] = c;
			return false;
		}
		curY += dy[dir];
		curX += dx[dir];
	}
	v[y][x] = '.';
	v[y - dy[dir]][x - dx[dir]] = c;
	return false;
}