[BOJ] Ʈ���� ���� / ���2 / /https://www.acmicpc.net/problem/1167
### �׷��� Ž�� (DFS)
1. ������ �׷������� ���̸� ã�� ���� vistied �迭�� ����ϴ� DFS�� ����� ��
	- ������ �׷������� BFS�� ����ϸ� ����� �������� �ߺ��Ǵ� �׷����� ó���ϱⰡ ��ٷο�����
	- �� ��� �޸������̼��� �����ϸ� ����������, �ش� ����� ������ ���� ���� ���� �����ϴ�. (�÷��̵�, DP)
2. ũ�罺Į �˰����� ���� Ʈ���� ����� �˰����̰�, �ƿ� �ٸ� ���ٹ��̿���

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int v;
vector<pair<int, int>> adj[100002];	// ���� ����, ���
bool visited[100002];	// ������ �׷����̱� ������ �湮ó��
int maxNode, maxDist;	// 1�� dfs���� ���� �� ����, �����

void dfs(int index, int dist) {
	if (visited[index])
		return;

	visited[index] = true;
	if (dist > maxDist) {
		maxNode = index;
		maxDist = dist;
	}
	for (auto& nxt : adj[index]) {
		dfs(nxt.X, dist + nxt.Y);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int nxt, dist;
		int st;
		cin >> st;
		do {
			cin >> nxt;
			if (nxt == -1) break;
			cin >> dist;
			adj[st].push_back({ nxt, dist });
		} while (nxt != -1);
	}

	// 1�� dfs : ������ ����(1)���� ���� �� ���� ã��
	fill(visited, visited + v + 1, false);
	dfs(1, 0);
	// 2�� dfs : �ش� �������� ���� �� ������ ���� ���
	fill(visited, visited + v + 1, false);
	dfs(maxNode, 0);
	cout << maxDist;
}