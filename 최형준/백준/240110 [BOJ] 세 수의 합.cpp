[BOJ] �� ���� �� / ���4 / https://www.acmicpc.net/problem/2295
���� Ž��, �켱 �� �������� �� �����̸� �ѹ����̷� ����� ����Ž���ϴ� ���̵��

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		a.push_back(val);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			v.push_back(a[i] + a[j]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(v.begin(), v.end(), a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}
}