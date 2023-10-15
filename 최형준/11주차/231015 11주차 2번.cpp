[11���� 2��] / Maximum Product Subarray / 52�� / https://leetcode.com/problems/maximum-product-subarray/

[���� ����]
��� �˰��� = ���̳��� ���α׷��� (O(n), O(1))
1. ���� �ִ밪�� ���� �ּҰ��� ������ ���
2. �迭�� ���鼭 ���� �κа� ���ϱ�

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