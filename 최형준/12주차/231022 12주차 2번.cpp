[12주차 2번] / House Robber / 11분 / https://leetcode.com/problems/house-robber/description/

[문제 접근]
사용 알고리즘 = 동적 계획법(Dynamic Programming) O(n), O(n)
1. nums 배열과 동일한 크기의 dp 배열 선언
2. 2가지 경우를 비교하는 점화식을 세우고, 최대값을 dp배열에 저장
3. dp 배열의 마지막 값 반환

[개선점]
1. 동일한 크기의 dp배열을 선언할 필요가 없음 (두가지 값만 비교하면 되기 때문)

[다른 풀이 방법]
1. 동적 계획법(Dynamic Programming) O(n), O(1)

Time taken : 11 m 5 s
Runtime 0ms
Beats 100.00 % of users with C++
Memory 8.44MB
Beats 6.64 % of users with C++

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        if (size == 2)
        {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(size);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[size - 1];
    }
};

[다른 풀이 방법]
동적 계획법(Dynamic Programming) O(n), O(1)
1. 두가지 수만 비교하여 공간 복잡도를 개선할 수 있음

int rob(vector<int>& nums) {
    int prev1 = 0, prev2 = 0;
    for (int num : nums) {
        int temp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = temp;
    }
    return prev1;
}
