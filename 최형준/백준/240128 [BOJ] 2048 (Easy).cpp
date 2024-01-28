[BOJ] 2048 (Easy) / 골드2 / https://www.acmicpc.net/problem/12100
구현, 백트래킹, 브루트포스, 시뮬레이션 - 실수할 부분이 많아서 신경써서 구현해야함
특히 2차원 배열을 탐색할때 범위가 맞는지 잘 확인할 것

#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> board;
int n, ans;
void Init();
void Func(int count, vector<vector<int>>& v);
void Move(vector<vector<int>>& v, int dir);
void Moving(vector<vector<int>>& v, vector<vector<bool>>& check, int x, int y, int dir);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Init();
	Func(0, board);
	cout << ans;
}
void Init() {
	cin >> n;
	board.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			ans = max(ans, board[i][j]);
		}
	}
}
void Func(int count, vector<vector<int>>& v) {
	if (count == 5) return;

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> tmp = v;
		Move(tmp, i);
		Func(count + 1, tmp);
	}
}
void Move(vector<vector<int>>& v, int dir) {
	vector<vector<bool>> check(n, vector<bool>(n));
	switch (dir) {
	case 0: // 오른쪽
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (v[i][j] != 0) Moving(v, check, j, i, dir);
			}
		}
		break;
	case 1: // 아래
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != 0) Moving(v, check, j, i, dir);
			}
		}
		break;
	case 2: // 왼쪽
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != 0) Moving(v, check, j, i, dir);
			}
		}
		break;
	case 3: // 위쪽
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != 0) Moving(v, check, j, i, dir);
			}
		}
		break;
	}
}
void Moving(vector<vector<int>>& v, vector<vector<bool>>& check, int x, int y, int dir) {
	int val = v[y][x];
	int curX = x + dx[dir], curY = y + dy[dir];
	while (0 <= curX && curX < n && 0 <= curY && curY < n) {
		if (v[curY][curX] != 0) {
			if (v[curY][curX] == v[y][x] && !check[curY][curX]) {
				v[y][x] = 0;
				v[curY][curX] = val * 2;
				ans = max(ans, v[curY][curX]);
				check[curY][curX] = true;
				return;
			}
			else {
				v[y][x] = 0;
				v[curY - dy[dir]][curX - dx[dir]] = val;
				return;
			}
		}
		curX += dx[dir];
		curY += dy[dir];
	}
	v[y][x] = 0;
	v[curY - dy[dir]][curX - dx[dir]] = val;
}