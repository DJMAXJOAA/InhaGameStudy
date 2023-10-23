class Solution {
public:
    int rob(vector<int>& nums) {
       
       vector<int>dp(nums.size()+1);

       dp[0] = 0; // 1번째 집을 들리지 않았다.
       dp[1] = nums[0]; // 1번째 집을 들렸다.

       for(int i = 1; i < nums.size(); i++)
       {
           dp[i+1] = max(dp[i-1] + nums[i], dp[i]);
       }

       // dp[i-1] + nums[i] : 전집을 들리지 않았다 => 전전집 들린 부분 + i번째 집(지금집)
       // dp[i] : 전집을 들렸다 => 이번집 못들린다 => 전집 들린 부분 

        return dp[nums.size()];
    }
};
