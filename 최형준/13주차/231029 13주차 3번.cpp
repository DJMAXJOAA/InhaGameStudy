[13주차 3번] / House Robber II / 16분 / https://leetcode.com/problems/house-robber-ii/description/

[문제 접근]
사용 알고리즘 = dp : O(n), O(1)
1. 첫번째 집부터 마지막 전 집까지 터는 경우
2. 두번째 집부터 마지막 집까지 터는 경우
3. 두가지 경우 중 더 큰 값을 반환

[다른 풀이 방법]
1. 재귀 + 메모이제이션 : O(n), O(n)

Time taken : 16 m 53 s
Runtime 0ms
Beats 100.00 % of users with C++
Memory 8.06MB
Beats 65.79 % of users with C++

class Solution {
public:
    int dp(int start, int end, vector<int>& nums)
    {
        int prev = 0, prev_prev = 0;

        for (int i = start; i < end; i++)
        {
            int temp = prev;
            prev = max(prev_prev + nums[i], prev);
            prev_prev = temp;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        else if (size == 2)
        {
            return max(nums[0], nums[1]);
        }

        return max(dp(0, size - 1, nums), dp(1, size, nums));
    }
};

[다른 풀이 방법]
재귀(메모이제이션) : O(n), O(n)
1. 배열을 이용해서, 저장해두고 값을 비교하는 경우
2. 첫 집을 턴 경우, 털지 않은 경우를 따로 계산

class Solution {
public:
    int memo[100][2]; // 메모이제이션을 위한 배열

    int robHouses(vector<int>& nums, int index, bool robbedFirst, int n) {
        if (index >= n) {
            return 0;
        }
        if (index == n - 1) {
            return robbedFirst ? 0 : nums[index]; // 첫 집을 털었다면 마지막 집은 털 수 없음
        }
        if (memo[index][robbedFirst] != -1) {
            return memo[index][robbedFirst]; // 이미 계산된 값을 사용
        }

        // 현재 집을 털 경우와 털지 않는 경우의 금액을 계산
        int robCurrent = nums[index] + robHouses(nums, index + 2, robbedFirst, n);
        int skipCurrent = robHouses(nums, index + 1, robbedFirst, n);

        // 더 큰 금액을 메모하고 반환
        memo[index][robbedFirst] = max(robCurrent, skipCurrent);
        return memo[index][robbedFirst];
    }

    int rob(vector<int>& nums) {
        memset(memo, -1, sizeof(memo)); // 메모이제이션 배열 초기화
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robHouses(nums, 0, true, n - 1), // 첫 집을 털 경우
            robHouses(nums, 1, false, n)); // 마지막 집을 털 경우
    }
};
