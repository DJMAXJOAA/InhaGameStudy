class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int maxNum = INT_MIN;
        int curNum = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            curNum *= nums[i];
            maxNum = max(maxNum, curNum);
            if (nums[i] == 0) curNum = 1;
        }

        // negative count are odd, answers always negative even if answer is over there 
        // [3, -1, 4] -> shuld be reverse again 

        curNum = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            curNum *= nums[i];
            maxNum = max(maxNum, curNum);
            if (nums[i] == 0) curNum = 1;
        }

        return maxNum;
    }
};