[BOJ] 거짓말 / 골드4 / https://www.acmicpc.net/problem/1043
처음에 백트래킹으로 접근했으나, 시간 초과 (범위가 50까지로 크지 않아서 가능할 줄 알았음)
이후 메모이제이션을 적용하여 dp로 접근하나 싶었는데
그래프 탐색(Union Find 알고리즘)으로 접근하는게 정답
문제가 집합 관련이고, 그래프 탐색 느낌이 나면 해당 알고리즘을 적용해보자.

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> parent, rnk;	// parent : 부모노드 보관, rnk : 트리의 높이 (노드들의 효율적인 재귀)
vector<vector<int>> party;	// union 갯수 (파티에 참가한 집합들)
vector<bool> isTruth, canLie;	// 진실 알고 있는 인원, 구라칠수 있는 인원 따로 체크
int find_parent(int x) {
	if (x != parent[x])
		parent[x] = find_parent(parent[x]);
	return parent[x];	// 재귀로 부모 노드 탐색
}
void union_group(int u, int v) {
	u = find_parent(u); v = find_parent(v);
	if (u == v) return;
	if (rnk[u] < rnk[v]) swap(u, v);	// 트리 높이 비교하여 부모 노드 교환
	parent[v] = u;
	if (rnk[u] == rnk[v]) rnk[u]++;		// 높이 동일하면 높이 올림
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
		parent[i] = i;		// Union Find시 자기 자신으로 부모 노드 초기화
	}
	int iTruth;
	cin >> iTruth;
	for (int i = 0; i < iTruth; i++) {
		int num;
		cin >> num;
		isTruth[num] = true;	// 진실 아는 인원 설정
	}
	party.resize(m);
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int firstPerson;
		for (int j = 0; j < num; j++) {
			int person;
			cin >> person;
			if (j == 0) firstPerson = person;		// 첫 노드를 그룹 부모노드로 설정
			else union_group(firstPerson, person);	// 첫 노드에 노드들 연결
			party[i].push_back(person);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isTruth[i]) {
			int truthGroup = find_parent(i);
			for (int j = 0; j < m; j++) {
				for (auto person : party[j]) {		// 모든 그룹을 돌면서 연결되어있는지 확인
					if (find_parent(person) == truthGroup) {
						canLie[j] = false;			// 연결되어있으면 거기 그룹은 구라못침
						break;
					}
				}
			}
		}
	}
	int ans = count(canLie.begin(), canLie.end(), true);
	cout << ans << '\n';
}