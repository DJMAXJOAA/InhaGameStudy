[BOJ] 듣보잡 / 실버4 / https://www.acmicpc.net/problem/1764
- `unordered_set`을 사용하여 중복 체크
- 중복 시 배열에 추가
- 이후 배열 사전순 정렬

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