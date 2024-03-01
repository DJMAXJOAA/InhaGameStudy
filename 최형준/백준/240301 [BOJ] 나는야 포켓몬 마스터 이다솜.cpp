[BOJ] ���¾� ���ϸ� ������ �̴ټ� / �ǹ�4 / https://www.acmicpc.net/problem/1620
�����ϰ� �ؽø����� ���� Ǯ�� ����

#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<int, string> m1;
unordered_map<string, int> m2;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		m1[i] = s;
		m2[s] = i;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (isdigit(s[0])) {
			int num = stoi(s);
			cout << m1[num] << '\n';
		}
		else {
			cout << m2[s] << '\n';
		}
	}
}