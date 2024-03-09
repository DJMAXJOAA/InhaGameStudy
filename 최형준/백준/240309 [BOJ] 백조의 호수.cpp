[BOJ] ������ ȣ�� / �÷�1 / /https://www.acmicpc.net/problem/3197
### BFS, A*, ť
1. ó�� Ǯ��ô� �÷�Ƽ�� �����ε�, Ȯ���� �ſ� ��ƴ�.
   1�� Ǯ�̱����� �ݹ� �ۼ�������, �ð� �ʰ������� �� 2�ð� �Ѱ� �ɷȴ�..
2. ������ ���� ��� ��ü�� �����ϳ�, �ð��� ���� ���⵵�� ����� ����ؾ� �Ѵ�
3. ������ Ǯ�� �� �־��� ������ �� Ȯ���غ���, ���� Ǯ�� ����� �����ϰ� ��������.
4. �ٸ� Ǯ�̹�����δ� Union - Find�� ����Ͽ� �и� �������� ������ ���� ���տ� ���ϴ��� Ȯ���ϴ� ����� �ִ�.

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> l;		// ���� 2����

// bfs ���ư��� ��ġ (����, ��)
queue<pair<int, int>> waterQ;
queue<pair<int, int>> tmpWaterQ;
queue<pair<int, int>> swanQ;
queue<pair<int, int>> tmpSwanQ;

// 1�� ������ �̵� ������ ���� üũ (���� �κ��� ���� �̵� �������� �߰�)
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
// ���� ���� ������ ã��, �ش� ������ ���� (���̰� �ش� ���� ť�� �߰�)
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
			if (grid[i][j] != 'X') {	// ���� �ƴ� �� �� ť�� �߰�
				waterQ.push({ j,i });
			}
			if (grid[i][j] == 'L') {
				l.push_back({ j,i });
			}
		}
	}
	// 1�� ���� ���� ����
	swanQ.push({ l.front().X, l.front().Y });
	visited[l.front().Y][l.front().X] = true;

	int cnt = 0;
	while (1) {
		// ���� �̵� -> ���� ���̱�
		if (swanBFS()) {
			break;
		}
		waterBFS();
		// ���� �̵� ���� ����
		swanQ = tmpSwanQ;
		waterQ = tmpWaterQ;
		tmpSwanQ = queue<pair<int, int>>();
		tmpWaterQ = queue<pair<int, int>>();
		cnt++;
	}
	cout << cnt;
}