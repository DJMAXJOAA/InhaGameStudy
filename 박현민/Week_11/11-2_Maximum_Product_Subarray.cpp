class Solution {
public:
    // 2 3 -2 4 -1
    int maxProduct(vector<int>& nums) {
        vector<int> maxsofar(nums.size(), 0);
        vector<int> minsofar(nums.size(), 0);
        int maxVal = nums[0];
        maxsofar[0] = nums[0];
        minsofar[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int val1 = maxsofar[i - 1] * nums[i];
            int val2 = minsofar[i - 1] * nums[i];
            maxsofar[i] = max(nums[i], max(val1, val2));
            minsofar[i] = min(nums[i], min(val1, val2));
            maxVal = max(maxVal, maxsofar[i]);
        }
        return maxVal;
    }
};