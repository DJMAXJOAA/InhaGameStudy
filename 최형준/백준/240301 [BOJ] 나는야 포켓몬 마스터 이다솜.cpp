[BOJ] 나는야 포켓몬 마스터 이다솜 / 실버4 / https://www.acmicpc.net/problem/1620
간단하게 해시맵으로 문제 풀이 가능

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