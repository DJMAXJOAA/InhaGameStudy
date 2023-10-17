[11주차 2번] / Maximum Product Subarray / 52분 / https://leetcode.com/problems/maximum-product-subarray/

[문제 접근]
사용 알고리즘 = 다이나믹 프로그래밍 (O(n), O(1))
1. 가장 최대값과 가장 최소값을 변수로 등록
2. 배열을 돌면서 현재 부분과 비교하기

Time taken : 51 m 49 s
Runtime 3ms
Beats 89.47 % of users with C++
Memory 14.29MB
Beats 10.19 % of users with C++

// 2, 7, -3, -2, 4, -1, 10, 6 = 480

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		if (size == 1)
		{
			return nums[0];
		}

		int result = nums[0];
		pair<int, int> current = make_pair(result, result);

		for (int i = 1; i < size; i++)
		{
			if (nums[i] < 0)
			{
				swap(current.first, current.second);
			}

			current.first = max(nums[i], current.first * nums[i]);
			current.second = min(nums[i], current.second * nums[i]);
			result = max(current.first, result);
		}

		return result;
	}
};