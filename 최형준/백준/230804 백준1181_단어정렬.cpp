// https://www.acmicpc.net/problem/1181
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;			// 단어 갯수
	vector<vector<string>> word(51); // 50개 길이

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string temp;	// 넣을 문자열

		cin >> temp;
		word[temp.size()].push_back(temp);
	}
	for (auto& i : word)
	{
		sort(i.begin(), i.end());
		i.erase(unique(i.begin(), i.end()), i.end());
		for (auto& j : i)
		{
			cout << j << endl;
		}
	}

	return 0;
}