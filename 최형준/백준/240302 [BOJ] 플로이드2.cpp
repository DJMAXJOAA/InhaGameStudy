[BOJ] �÷��̵� 2 / ���3 / https://www.acmicpc.net/problem/11780
�÷��̵� �˰����� �ð� ���⵵�� ���� V�� ������ �������� �Ͽ� ��� �ܰ踦 V^2��ŭ ���ϹǷ�, �ð����⵵�� O(V^3)�� �ȴ�.
- 1�ʴ� 3�� ~ 5����� ������ �����ϴ�, ����� ������ 1000�� ������ �ش� �˰����� ����� �� ����
- ��� ���� �� �ִ� ��θ� Ž���ؾ� �� ��쿡 ���

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int INF = 0x3f3f3f3f; // ���Ѵ�, 2�� �ص� �����÷ο� X
vector<vector<int>> nodes;
vector<vector<int>> nxt;	// ��� ������
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	nodes.resize(n + 1, vector<int>(n + 1, INF));	// �� �� ���� ��츦 infinite ó��
	nxt.resize(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		nodes[start][end] = min(nodes[start][end], cost); // start -> end ��� ����
		nxt[start][end] = end;
	}
	for (int i = 1; i <= n; i++) nodes[i][i] = 0;	// 3. x == y�� 0���� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {	// 1~n������ ������ ����
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {
				if (nodes[y][i] + nodes[i][x] < nodes[y][x]) {
					nodes[y][x] = min(nodes[y][x], nodes[y][i] + nodes[i][x]);
					nxt[y][x] = nxt[y][i];	// ��� ����
				}
			}
		}
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (nodes[y][x] == INF) cout << 0 << ' ';
			else cout << nodes[y][x] << ' ';
		}
		cout << '\n';
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (nodes[y][x] == 0 || nodes[y][x] == INF) {
				cout << 0 << '\n';
				continue;
			}
			int start = y, end = x;
			vector<int> path;
			while (nxt[start][end] != 0) {
				path.push_back(start);
				start = nxt[start][end];	// ���� ��ΰ� ���� ��ο� ����������
			}
			path.push_back(end);
			cout << path.size() << ' ';
			for (auto i : path) cout << i << ' ';
			cout << '\n';
		}
	}
}