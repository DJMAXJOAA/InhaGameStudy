[BOJ] 곱셈 / 실버1 / /https://www.acmicpc.net/problem/1629
### 수학, 분할 정복
1. 큰 수의 제곱은 분할 정복으로 해결해야 한다.
2. 자료형의 크기도 신경 써주어야 한다(int로 하면 overflow 발생)

#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
long long func(long long div) {
	if (div == 1) return a % c;
	long long l = func(div / 2) % c;	// 분할 정복
	if (div % 2 == 0) {
		return l * l % c;	// 짝수
	}
	else {
		return l * l % c * a % c;	// 홀수
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	cout << func(b);
}