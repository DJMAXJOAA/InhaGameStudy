// https://www.acmicpc.net/problem/1436
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int i = 666;
	string result;
	while (n)
	{
		result = to_string(i);
		if (result.find("666") != string::npos) // ���ڿ��� 666�� ���ԵǾ������� n �ϳ� ���ҽ�Ų��
			n--;
		i++;
	}
	cout << result;

	return 0;
}