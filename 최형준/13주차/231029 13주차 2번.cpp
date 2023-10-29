[13주차 2번] / Search in Rotated Sorted Array / 1시간 40분 / https://leetcode.com/problems/search-in-rotated-sorted-array/

[문제 접근]
사용 알고리즘 = 이진 탐색 재귀함수 : O(log n), O(log n)
1. 배열을 중간으로 나누고, 어느 쪽이 정렬이 안된 부분인지 파악
2. 재귀로 범위를 제한, 탐색

[다른 풀이 방법]
1. 이진 탐색 반복문 : O(log n), O(1)

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