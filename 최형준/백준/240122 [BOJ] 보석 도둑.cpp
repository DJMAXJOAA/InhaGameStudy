[BOJ] ���� ���� / ���2 / https://www.acmicpc.net/problem/1202
���� ����, �׸��� �˰��� + ����Ʈ�� ���� / 2���� �迭 dp�ε� Ǯ �� ����

#include <bits/stdc++.h>
using namespace std;
int n, k;
long long ans;
vector<pair<int, int>> items;
multiset<int> bags;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int weight, price;
		cin >> weight >> price;
		items.push_back({ price, weight });
	}
	sort(items.rbegin(), items.rend());
	for (int i = 0; i < k; i++) {
		int weight;
		cin >> weight;
		bags.insert(weight);
	}

	for (int i = 0; i < n; i++) {
		int val = items[i].second;
		auto itr = bags.lower_bound(val);
		if (itr == bags.end()) continue;
		bags.erase(itr);
		ans += items[i].first;
	}
	cout << ans;
}