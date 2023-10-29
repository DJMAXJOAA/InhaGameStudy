[13���� 2��] / Search in Rotated Sorted Array / 1�ð� 40�� / https://leetcode.com/problems/search-in-rotated-sorted-array/

[���� ����]
��� �˰��� = ���� Ž�� ����Լ� : O(log n), O(log n)
1. �迭�� �߰����� ������, ��� ���� ������ �ȵ� �κ����� �ľ�
2. ��ͷ� ������ ����, Ž��

[�ٸ� Ǯ�� ���]
1. ���� Ž�� �ݺ��� : O(log n), O(1)

Time taken : 1 hr 46 m 31 s
Runtime 0ms
Beats 100.00 % of users with C++
Memory 11.45MB
Beats 25.00 % of users with C++

class Solution {

public:
    int BinarySearch(int low, int high, vector<int>& nums, int target)
    {
        int mid = (low + high) / 2;

        if (target == nums[mid])
        {
            return mid;
        }

        if (low > high)
        {
            return -1;
        }

        // 3 4 5 1 2
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
            {
                return BinarySearch(low, mid - 1, nums, target);
            }
            else
            {
                return BinarySearch(mid + 1, high, nums, target);
            }
        }
        // 4 5 1 2 3
        else
        {
            if (target <= nums[high] && target > nums[mid])
            {
                return BinarySearch(mid + 1, high, nums, target);
            }
            else
            {
                return BinarySearch(low, mid - 1, nums, target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return BinarySearch(0, nums.size() - 1, nums, target);
    }
};