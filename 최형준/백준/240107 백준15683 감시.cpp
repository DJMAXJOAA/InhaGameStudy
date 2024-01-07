// https://www.acmicpc.net/problem/15683
// 브루트 포스 + 백트래킹

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> dir
{
	{0, 1},		// 위쪽		0
	{1, 0},		// 오른쪽	1
	{0, -1},	// 아래쪽	2
	{-1, 0}		// 왼쪽		3
};
enum Types
{
	직선,
	양방향,
	직각,
	세방향,
	네방향,
};

struct CCTV
{
	int x;
	int y;
	Types type;
	vector<vector<int>> check;

	CCTV(int _x, int _y, int _type) : x(_x), y(_y), type((Types)(_type - 1)) { Func(); }
	CCTV(const CCTV& temp) : x(temp.x), y(temp.y), type(temp.type), check(temp.check) {}

private:
	void Func()
	{
		switch (type)
		{
		case 직선:
			check.push_back({ 0 });
			check.push_back({ 1 });
			check.push_back({ 2 });
			check.push_back({ 3 });
			break;
		case 양방향:
			check.push_back({ 0,2 });
			check.push_back({ 1,3 });
			break;
		case 직각:
			check.push_back({ 0, 1 });
			check.push_back({ 1, 2 });
			check.push_back({ 2, 3 });
			check.push_back({ 3, 0 });
			break;
		case 세방향:
			check.push_back({ 3,0,1 });
			check.push_back({ 0,1,2 });
			check.push_back({ 1,2,3 });
			check.push_back({ 2,3,0 });
			break;
		case 네방향:
			check.push_back({ 0, 1, 2, 3 });
			break;
		}
	}
};

void Print(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
void Print(vector<CCTV>& v)
{
	for (auto& i : v)
	{
		cout << i.x << ", " << i.y << " / " << i.type << "\n";
	}
	cout << "\n";
}

class Solution
{
public:
	vector<vector<int>> field;
	vector<CCTV> cctvs;

private:
	int xSize, ySize;

public:
	void Input(int M, int N)
	{
		ySize = N;
		xSize = M;

		int val;
		for (int i = 0; i < N; i++)
		{
			vector<int> temp;
			for (int j = 0; j < M; j++)
			{
				cin >> val;

				if (val > 0 && val < 6)
				{
					CCTV temp(j, i, val);
					cctvs.push_back(temp);
				}

				temp.push_back(val);
			}
			field.push_back(temp);
		}
	}
	int Func()
	{
		int size = Count(field);
		return DFS(field, size, 0);
	}

private:
	int DFS(vector<vector<int>>& visited, int size, int index)
	{
		if (index == cctvs.size())
			return size;

		int newSize;
		for (int i = 0; i < cctvs[index].check.size(); i++)
		{
			vector<vector<int>> visit = visited;
			Visit(visit, cctvs[index].x, cctvs[index].y, cctvs[index].check[i]);
			newSize = Count(visit);
			size = min(size, DFS(visit, newSize, index + 1));
		}
		return size;
	}

	void Visit(vector<vector<int>>& _field, int _x, int _y, vector<int>& check)
	{
		for (int i = 0; i < check.size(); i++)
		{
			int direction = check[i];
			int x = _x;
			int y = _y;

			while (1)
			{
				x += dir[direction].X;
				y += dir[direction].Y;

				if (x < 0 || x >= xSize || y < 0 || y >= ySize || _field[y][x] == 6)
				{
					break;
				}
				else if (_field[y][x] == 0)
				{
					_field[y][x] = 7;
				}
			}
		}
	}

	int Count(vector<vector<int>>& _field)
	{
		int result = 0;
		for (int i = 0; i < _field.size(); i++)
		{
			for (int j = 0; j < _field[0].size(); j++)
			{
				if (_field[i][j] == 0)
				{
					result++;
				}
			}
		}

		return result;
	}
};

int main()
{
	Solution sol;
	int M, N;

	cin >> N >> M;
	sol.Input(M, N);
	cout << sol.Func();
}

