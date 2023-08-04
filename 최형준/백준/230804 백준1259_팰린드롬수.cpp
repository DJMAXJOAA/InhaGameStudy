// https://www.acmicpc.net/problem/1259
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iInput;

	while (1)
	{
		vector<int> arr;

		cin >> iInput;
		if (!iInput)
			break;

		while (iInput)
		{
			arr.push_back(iInput % 10);
			iInput /= 10;
		}

		auto itrBegin = arr.begin();
		auto itrEnd = arr.rbegin();
		while (itrBegin != arr.end())
		{
			if (*itrBegin != *itrEnd)
			{
				printf("no\n");
				break;
			}

			itrBegin++;
			itrEnd++;
		}
		if (itrBegin == arr.end())
			printf("yes\n");
	}

	return 0;
}