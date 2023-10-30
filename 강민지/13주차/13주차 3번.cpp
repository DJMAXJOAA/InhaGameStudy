class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> dp1(nums.size(), 0), dp2(nums.size(), 0);

        dp1[1] = nums[0]; // 1번째 집 ~ 마지막-1 집
        dp2[1] = nums[1]; // 2번째 집 ~ 마지막 집

        for(int i = 2; i < nums.size(); i++)
        {
            dp1[i] = max(dp1[i-2] + nums[i-1], dp1[i-1]);
            dp2[i] = max(dp2[i-2] + nums[i], dp2[i-1]);
        }

        // dp[i-1] + nums[i] : 전집을 들리지 않았다 => 전전집 들린 부분 + i번째 집(지금집)
        // dp[i] : 전집을 들렸다 => 이번집 못들린다 => 전집 들린 부분 

        return max(dp1[nums.size()-1], dp2[nums.size()-1]);
    }
};
