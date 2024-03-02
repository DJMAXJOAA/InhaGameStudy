[BOJ] �躸�� / �ǹ�4 / https://www.acmicpc.net/problem/1764
- `unordered_set`�� ����Ͽ� �ߺ� üũ
- �ߺ� �� �迭�� �߰�
- ���� �迭 ������ ����

#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_set<string> st;
vector<string> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		st.insert(s);
	}
	for (int j = 0; j < m; j++) {
		string s;
		cin >> s;
		if (st.count(s) > 0) {
			ans.push_back(s);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& s : ans) {
		cout << s << '\n';
	}
}