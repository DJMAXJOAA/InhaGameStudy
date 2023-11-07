class Solution {
public:
    int rob(vector<int>& nums) {
        //마지막 집은 첫 집을 털었는지에 대한 여부가 필요
        if(nums.size()==1)return nums[0];
        vector<int> nums1, nums2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
                nums1.push_back(nums[i]);
            if(i!=nums.size()-1)
                nums2.push_back(nums[i]);
        }
        return max(func(nums1), func(nums2));
    }
    int func(vector<int>& nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        
        for(int i = 1; i<nums.size();i++)
        {
            int take = nums[i];
            if(i>1)take+=dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take,notTake);
        }
        return dp[nums.size()-1];
    }
};