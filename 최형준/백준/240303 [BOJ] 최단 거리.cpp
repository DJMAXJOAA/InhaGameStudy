[BOJ] �ִ� �Ÿ� / ���4 / https://www.acmicpc.net/problem/1753
### ���ͽ�Ʈ�� �˰���
1. �������� �켱���� ť ����(���, ���� ����)
2. ù �������� ť�� push(0, ������)
3. �켱���� ť���� ���� �Ÿ��� ª�� ���� ����, �ִ� �Ÿ����̺�� ���Ͽ� ���� �ٸ���(������) �Ѿ
	- �Ÿ������� �̱� ������ ��� ���� ���� ����(= ���� �ٸ��ٷ� üũ)
4. ť���� ����� ���� ���� ��� ���� �̵������� ������ ��� üũ
	- �ִܰŸ� �迭���� ������ ť�� �ְ� �� ����(��� ���, �ش� ����)
5. �켱���� ť�� �������� 3, 4�� ���� �ݺ�

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int v, e;	// ���� ����, ���� ����
int k;	// ������
vector<pair<int, int>> adj[20002];	// �� ������ ������ �ִ� ���� (���, �̵��� ����)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// �������� �켱���� ť
int d[20002];	// �ִܰŸ� ���̺�
const int INF = 0x3f3f3f3f;
void func(int st) {
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
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });	// ���, �̵� ����
	}
	fill(d, d + v + 1, INF);	// �迭�� ���Ѵ�(�̵� �Ұ�)�� �ʱ�ȭ
	func(k);
}