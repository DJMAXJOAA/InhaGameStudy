[BOJ] �� ����� / ���3 / /https://www.acmicpc.net/problem/2252
### ���� ����
1. ���� ������ �ڵ��׽�Ʈ�� ���� ������ ������ �ƴ�����, ���ӿ��� ��ų Ʈ���� ���� ���谡 �ʿ��� ��쿡 ���� ���Ǵϱ� �����δ� �� ������ ��
2. ��� ������ �޶��� �� �ִٴ� ��, �� - �� ���谡 ��Ȯ�ϴٴ� ���� ����ϱ�

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[32001];
int deg[32001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);	// ��������� Ű�� ���� ���� �л���
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (auto nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}
	for (auto x : result) cout << x << ' ';
}