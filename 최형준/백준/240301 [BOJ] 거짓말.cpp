[BOJ] ������ / ���4 / https://www.acmicpc.net/problem/1043
ó���� ��Ʈ��ŷ���� ����������, �ð� �ʰ� (������ 50������ ũ�� �ʾƼ� ������ �� �˾���)
���� �޸������̼��� �����Ͽ� dp�� �����ϳ� �;��µ�
�׷��� Ž��(Union Find �˰���)���� �����ϴ°� ����
������ ���� �����̰�, �׷��� Ž�� ������ ���� �ش� �˰����� �����غ���.

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> parent, rnk;	// parent : �θ��� ����, rnk : Ʈ���� ���� (������ ȿ������ ���)
vector<vector<int>> party;	// union ���� (��Ƽ�� ������ ���յ�)
vector<bool> isTruth, canLie;	// ���� �˰� �ִ� �ο�, ����ĥ�� �ִ� �ο� ���� üũ
int find_parent(int x) {
	if (x != parent[x])
		parent[x] = find_parent(parent[x]);
	return parent[x];	// ��ͷ� �θ� ��� Ž��
}
void union_group(int u, int v) {
	u = find_parent(u); v = find_parent(v);
	if (u == v) return;
	if (rnk[u] < rnk[v]) swap(u, v);	// Ʈ�� ���� ���Ͽ� �θ� ��� ��ȯ
	parent[v] = u;
	if (rnk[u] == rnk[v]) rnk[u]++;		// ���� �����ϸ� ���� �ø�
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	parent.assign(n + 1, -1);
	rnk.assign(n + 1, 0);
	isTruth.assign(n + 1, false);
	canLie.assign(m, true);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;		// Union Find�� �ڱ� �ڽ����� �θ� ��� �ʱ�ȭ
	}
	int iTruth;
	cin >> iTruth;
	for (int i = 0; i < iTruth; i++) {
		int num;
		cin >> num;
		isTruth[num] = true;	// ���� �ƴ� �ο� ����
	}
	party.resize(m);
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int firstPerson;
		for (int j = 0; j < num; j++) {
			int person;
			cin >> person;
			if (j == 0) firstPerson = person;		// ù ��带 �׷� �θ���� ����
			else union_group(firstPerson, person);	// ù ��忡 ���� ����
			party[i].push_back(person);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isTruth[i]) {
			int truthGroup = find_parent(i);
			for (int j = 0; j < m; j++) {
				for (auto person : party[j]) {		// ��� �׷��� ���鼭 ����Ǿ��ִ��� Ȯ��
					if (find_parent(person) == truthGroup) {
						canLie[j] = false;			// ����Ǿ������� �ű� �׷��� �����ħ
						break;
					}
				}
			}
		}
	}
	int ans = count(canLie.begin(), canLie.end(), true);
	cout << ans << '\n';
}