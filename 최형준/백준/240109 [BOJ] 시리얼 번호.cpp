[BOJ] 시리얼 번호 / 실버3 / https://www.acmicpc.net/problem/1431
sort() 함수 비교 조건 설정하기

#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

bool cmp(const string& a, const string& b)
{
	int a_size = a.size();
	int b_size = b.size();
	if (a_size == b_size)
	{
		int acnt = 0, bcnt = 0;
		for (int i = 0; i < a_size; i++)
		{
			if (a[i] >= '0' && a[i] <= '9') acnt += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') bcnt += b[i] - '0';
		}
		if (acnt == bcnt)
		{
			return a < b;
		}
		else
		{
			return acnt < bcnt;
		}
	}
	else
	{
		return a_size < b_size;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), cmp);
	for (auto& i : v) cout << i << '\n';
}