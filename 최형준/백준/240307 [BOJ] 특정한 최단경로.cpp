[BOJ] Ư���� �ִ� ��� / ���4 / /https://www.acmicpc.net/problem/1504
### �׷���, �ִ� ��� Ž��
1. �̵� �Ұ����� ����� ����ó���� �� ������
���� ����� �������� ������ ��찡 �־, ���� Ǯ�̰� �����Ǿ���
�÷��̵��� �˻� ����� �������� ���� �� ������ �߰������� ����ó�� ���ֱ�

2. ������ �׷����� ��� ���� �Է� �� �ݴ��� ������ �߰����־�� �Ѵ�.
���� �׷���ó�� ������ Ǯ���ٰ� ���� Ǯ�̰� ������

3. ���ͽ�Ʈ�� �˰������� �����ϰ� Ǯ�̰� �����ϴ�
1, v1, v2 ���� ������ �������� �̵��ϴ� ��츦 ��� ���
�����ϰ� 2���� ��츦 ���Ͽ� ����� ���� ��� ��츦 ��ȯ

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, e;
int v1, v2;
int d[801][801];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
		d[b][a] = min(d[b][a], c);	// ������ �׷��� ó��
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	cin >> v1 >> v2;

	// �÷��̵� �˰������� ��� ������ �̵� ��� ���
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	// �� ��Ʈ �� �� ���� ���� ���
	long long v1_result = d[1][v1] + d[v1][v2] + d[v2][n];
	long long v2_result = d[1][v2] + d[v2][v1] + d[v1][n];
	// �̵��� �Ұ����� ��� -> 0 < result < INF ���� ó��
	if ((v1_result >= INF || 0 > v1_result)
		&& (v2_result >= INF || 0 > v2_result)) cout << -1;
	else cout << min(v1_result, v2_result);
}