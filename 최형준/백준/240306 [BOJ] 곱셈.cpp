[BOJ] ���� / �ǹ�1 / /https://www.acmicpc.net/problem/1629
### ����, ���� ����
1. ū ���� ������ ���� �������� �ذ��ؾ� �Ѵ�.
2. �ڷ����� ũ�⵵ �Ű� ���־�� �Ѵ�(int�� �ϸ� overflow �߻�)

#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
long long func(long long div) {
	if (div == 1) return a % c;
	long long l = func(div / 2) % c;	// ���� ����
	if (div % 2 == 0) {
		return l * l % c;	// ¦��
	}
	else {
		return l * l % c * a % c;	// Ȧ��
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	cout << func(b);
}