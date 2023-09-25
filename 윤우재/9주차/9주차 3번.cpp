class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int Max = nums[0];
        int localMax = nums[0];
        for(int i = 1; i<len;i++)
        {
            localMax = max(localMax + nums[i], nums[i]);
            Max = max(Max, localMax);
        }

        return Max;
    }
};