[BOJ] 최소 힙 / 실버2 / https://www.acmicpc.net/problem/1927
배열로 우선순위 큐 구현 / 이진트리를 배열로 = x*2, x*2+1의 인덱스 차이가 난다

#include <bits/stdc++.h>
using namespace std;
int heap[100005];
int sz = 0;
int n;
void push(int x) {
	heap[++sz] = x;
	int i = sz;
	while (i != 1) {
		int parent = i / 2;
		if (heap[parent] <= heap[i]) break;
		swap(heap[i / 2], heap[i]);
		i = parent;
	}
}
int top() {
	return sz == 0 ? 0 : heap[1];
}
void pop() {
	if (sz == 0) return;
	heap[1] = heap[sz--];
	int i = 1;
	while (2 * i <= sz) {
		int left = i * 2, right = i * 2 + 1;
		int mini = left;
		if (right <= sz && heap[right] < heap[left]) {
			mini = right;
		}
		if (heap[i] <= heap[mini]) break;
		swap(heap[i], heap[mini]);
		i = mini;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (val == 0) {
			cout << top() << '\n';
			pop();
		}
		else push(val);
	}
}