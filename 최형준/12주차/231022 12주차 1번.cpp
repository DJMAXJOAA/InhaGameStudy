[12주차 1번] / Find Minimum in Rotated Sorted Array / 48분 / https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

[문제 접근]
사용 알고리즘 = 이진 탐색 (Binary Search) : O(log n), O(log n)

[개선점]
1. 재귀 함수를 사용하지 않고도 풀이할 수 있음 -> 공간 복잡도를 O(1)로 추가적인 공간 사용없이 풀이 가능
2. 재귀에서 조건 판단없이 무조건 두 방향으로 탐색하고 있음 -> low와 high의 값을 비교해서 탐색 시간을 줄일 수 있음

Time taken : 48 m 17 s
Runtime 3ms
Beats 58.73 % of users with C++
Memory 10.51MB
Beats 18.40 % of users with C++

class Solution {
public:
    int size;
    int result;
public:
    void BinarySearch(int low, int mid, int high, vector<int>& nums, int start, int end)
    {
        result = min(result, nums[mid]);

        if (mid == start || mid == end)
        {
            return;
        }

        BinarySearch(low, low + (mid - low) / 2, mid, nums, low, mid);
        BinarySearch(mid, mid + (high - mid + 1) / 2, high, nums, mid, high);
    }

    int findMin(vector<int>& nums) {
        size = nums.size();

        int high = size - 1;
        int low = 0;
        int mid = size / 2;

        result = nums[mid];

        BinarySearch(low, low + (mid - low) / 2, mid, nums, low, mid);
        BinarySearch(mid, mid + (high - mid + 1) / 2, high, nums, mid, high);

        return result;
    }
};

[다른 풀이 방법]
1. while문을 사용하는 이진 탐색 방법

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) {
            // 이는 최솟값이 오른쪽 절반에 있다는 것을 의미
            low = mid + 1;
        }
        else {
            // 이는 최솟값이 왼쪽 절반에 있다는 것을 의미
            high = mid;
        }
    }
    return nums[low];
}