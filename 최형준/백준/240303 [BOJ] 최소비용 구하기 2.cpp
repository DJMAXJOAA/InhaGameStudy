[BOJ] �ּҺ�� ���ϱ� / ���3 / https://www.acmicpc.net/problem/11779
### ���ͽ�Ʈ�� �˰���
1. ��� ������ pre �迭 �߰�
2. pre�迭�� �� �ε����� ������ �θ� ��尡 ����ȴ�
3. �ִܰŸ� Ž�� ���� �� vector<int> �迭�� �߰��Ͽ� ��θ� �Է�
4. �Էµ� ��θ� �������� �̵� ��� ���� �Ϸ�

// BOJ 11779 �ּҺ�� ���ϱ� 2
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int v, e;	// ���� ����, ���� ����
int st, en;	// ����, ������
vector<pair<int, int>> adj[1005];	// �� ������ ������ �ִ� ���� (���, �̵��� ����)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// �������� �켱���� ť
int d[1005];	// �ִܰŸ� ���̺�
int pre[1005];	// ��� ���� ���̺�
const int INF = 0x3f3f3f3f;

void func(int st, int en) {
	d[st] = 0;	// ������ �ʱ�ȭ
	pq.push({ 0, st });
	while (!pq.empty()) {
		int cost = pq.top().X;
		int vertex = pq.top().Y;
		pq.pop();
		if (d[vertex] != cost) continue;	// �ִܰŸ� ���̺�� ���ؼ� �ٸ��� ���� (�� �������)
		for (auto& nxt : adj[vertex]) {		// �ش� ������ �������� ��
			if (nxt.X + d[vertex] < d[nxt.Y]) {	// �ִܰŸ� ���̺� �� vs ���� ���� + �̵� ��� ��
				d[nxt.Y] = nxt.X + d[vertex];
				pre[nxt.Y] = vertex;	// ��� ����
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
	reverse(route.begin(), route.end());	// ��� ������

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
		adj[u].push_back({ w, v });	// ���, �̵� ����
	}
	fill(d, d + v + 1, INF);	// �迭�� ���Ѵ�(�̵� �Ұ�)�� �ʱ�ȭ
	cin >> st >> en;
	func(st, en);
}