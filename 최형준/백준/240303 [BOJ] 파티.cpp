[BOJ] ��Ƽ / ���3 / https://www.acmicpc.net/problem/1238
### ���ͽ�Ʈ�� �˰���
1. ���ͽ�Ʈ�� �˰����� �պ����� ����ϰ�, ���� ū ��� ��ȯ

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int v, e;	// ���� ����, ���� ����
int st;	// ����
vector<pair<int, int>> adj[1005];	// �� ������ ������ �ִ� ���� (���, �̵��� ����)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// �������� �켱���� ť
int d[1005];	// �ִܰŸ� ���̺�
const int INF = 0x3f3f3f3f;

int func(int st, int en) {
	fill(d, d + v + 1, INF);	// �迭�� ���Ѵ�(�̵� �Ұ�)�� �ʱ�ȭ
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
				pq.push({ d[nxt.Y], nxt.Y });
			}
		}
	}
	return d[en];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> st;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });	// ���, �̵� ����
	}
	int ans = 0;
	for (int i = 1; i <= v; i++) {
		ans = max(ans, func(i, st) + func(st, i)); // �պ��� ���� �����ɸ��� ��� üũ
	}
	cout << ans;
}