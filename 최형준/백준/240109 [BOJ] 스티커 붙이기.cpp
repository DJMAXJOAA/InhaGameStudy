[BOJ] 스티커 붙이기 / 골드3 / https://www.acmicpc.net/problem/18808
브루트 포스, 시뮬레이션

#include <bits/stdc++.h>
using namespace std;

void Rotate(vector<vector<int>>& arr)
{
	int x = arr[0].size();
	int y = arr.size();

	vector<vector<int>> rst(x, vector<int>(y));
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			rst[i][j] = arr[y - 1 - j][i];
		}
	}
	arr = rst;
}

struct Sticker
{
	int x, y;
	vector<vector<int>> v;

	Sticker(int n, int m) : v(n, vector<int>(m)), x(m), y(n) {}
	void rotate()
	{
		Rotate(v);
		x = v[0].size();
		y = v.size();
	}
};

vector<vector<int>> matrix;
vector<Sticker> stks;

int Count(const vector<vector<int>>& arr)
{
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			if (arr[i][j] == 1) count++;
		}
	}
	return count;
}

bool CanStick(const Sticker& s, int x, int y)
{
	for (int i = 0; i < s.y; i++)
	{
		for (int j = 0; j < s.x; j++)
		{
			if (s.v[i][j] == 1 && matrix[i + y][j + x] == 1)
			{
				return false;
			}
		}
	}
	return true;
}

void ApplySticker(const Sticker& s, int x, int y)
{
	for (int i = 0; i < s.y; i++)
	{
		for (int j = 0; j < s.x; j++)
		{
			if (s.v[i][j] == 1)
			{
				matrix[i + y][j + x] = 1;
			}
		}
	}
}

void CheckSticker(Sticker& s)
{
	for (int i = 0; i < 4; i++) // 0, 90, 180, 270
	{
		int x_range = matrix[0].size() - s.x + 1;
		int y_range = matrix.size() - s.y + 1;
		if (x_range <= 0 || y_range <= 0)
		{
			s.rotate();
			continue;
		}

		// 공간 찾기
		for (int y = 0; y < y_range; y++)
		{
			for (int x = 0; x < x_range; x++)
			{
				if (CanStick(s, x, y))
				{
					ApplySticker(s, x, y);
					return;
				}
			}
		}
		s.rotate();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k; // n 세로 m 가로 k 스티커갯수
	cin >> n >> m >> k;

	matrix.resize(n, vector<int>(m));

	for (int i = 0; i < k; i++)
	{
		int nn, mm; // nn 세로 mm 가로
		cin >> nn >> mm;

		Sticker s(nn, mm);
		for (int y = 0; y < nn; y++)
		{
			for (int x = 0; x < mm; x++)
			{
				int val;
				cin >> val;
				s.v[y][x] = val;
			}
		}
		stks.push_back(s);
	}

	for (int i = 0; i < k; i++) // 스티커 갯수만큼 반복
	{
		Sticker s = stks[i];	// 현재 스티커
		CheckSticker(s);
	}

	cout << Count(matrix) << '\n';
}