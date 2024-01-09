// https://www.acmicpc.net/problem/2751
// 병합 정렬 연습

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int tmp[1000001];

void Merge(int st, int en)
{
	int mid = (st + en) / 2;
	int idx_a = st, idx_b = mid;
	for (int i = st; i < en; i++)
	{
		if (idx_a == mid) tmp[i] = arr[idx_b++];
		else if (idx_b == en) tmp[i] = arr[idx_a++];
		else if (arr[idx_a] <= arr[idx_b]) tmp[i] = arr[idx_a++];
		else tmp[i] = arr[idx_b++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void MergeSort(int st, int en)
{
	if (en - st == 1) return;
	int mid = (st + en) / 2;
	MergeSort(st, mid);
	MergeSort(mid, en);
	Merge(st, en);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int val;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		arr[i] = val;
	}
	MergeSort(0, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
}