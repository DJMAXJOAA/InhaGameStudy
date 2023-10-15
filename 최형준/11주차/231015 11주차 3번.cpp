[11���� 3��] / Maximum Product Subarray / 1�ð� 10�� / https://leetcode.com/problems/combination-sum-iv/

[���� ����]
��� �˰��� = ���̳��� ���α׷���(O(m*n), O(n))
1. ���� �� ������� dp �迭�� ä��� (������ ������ �н�) -> ���� �������� ū ������ Ȯ��
(dp[i] = dp[i-1] + dp[i-2] + dp[i-3].... ������ i-nums[j]�� ������ ������ �κ��� �н�)

[������]
1. dp ���̺��� ä�� �� Ư�� �迭�� ä�� ������������, �ϴ±迡 �� �� ä��鼭 ����
2. �������� -> ū������ Ȯ��Ǵ� ������ ���� dp (ž�ٿ� - ���, ���Ҿ� - �迭) / ��ȭ�� ����°� �� ���

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

// �ϴٰ� �Ʊ���� ����
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