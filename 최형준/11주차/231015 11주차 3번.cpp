[11주차 3번] / Maximum Product Subarray / 1시간 10분 / https://leetcode.com/problems/combination-sum-iv/

[문제 접근]
사용 알고리즘 = 다이나믹 프로그래밍(O(m*n), O(n))
1. 바텀 업 방식으로 dp 배열을 채우기 (음수가 나오면 패스) -> 작은 문제부터 큰 문제로 확장
(dp[i] = dp[i-1] + dp[i-2] + dp[i-3].... 이지만 i-nums[j]가 음수가 나오는 부분은 패스)

[개선점]
1. dp 테이블을 채울 때 특정 배열만 채울 생각하지말고, 하는김에 걍 다 채우면서 가자
2. 작은문제 -> 큰문제로 확장되는 문제는 보통 dp (탑다운 - 재귀, 바텀업 - 배열) / 점화식 세우는거 더 고민

Time taken : 1 hr 12 m 21 s
Runtime 0ms
Beats 100.00 % of users with C++
Memory 6.80MB
Beats 21.19 % of users with C++

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};

// 하다가 아까워서 나둠
//class Solution {
//public:
//    int combinationSum4(vector<int>& nums, int target) {
//        sort(nums.begin(), nums.end());
//        if (nums[0] > target)
//        {
//            return 0;
//        }
//        vector<unsigned int> dp(target + 1, 0);
//        dp[nums[0]] = 1;
//
//        int currentValue = nums[0];
//        int saveIndex = 0;
//
//        int temp;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (nums[i] >= target)
//            {
//                break;
//            }
//            currentValue = nums[i];
//            saveIndex = i;
//
//            for (int j = 0; j < i; j++)
//            {
//                temp = currentValue - nums[j];
//                if (dp[temp] > 0)
//                {
//                    dp[nums[i]] += dp[nums[j]];
//                }
//            }
//            dp[nums[i]] += 1;
//        }
//
//        for (int i = currentValue + 1; i < dp.size(); i++)
//        {
//            for (int j = 0; j < saveIndex; j++)
//            {
//                temp = target - nums[j];
//                if (dp[temp] > 0)
//                {
//                    dp[nums[i]] += dp[nums[j]];
//                }
//            }
//        }
//
//        return dp[target];
//    }
//};