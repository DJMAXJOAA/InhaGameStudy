class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        // I only find O(n^2) solution and it didn't right
        // Should know the main point of question ( only need  length, not array)

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (ans.back() < nums[i]) // compare if it is increasing
            {
                ans.push_back(nums[i]);
            }

            else //if not
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
                //find index of number that first of upper num
                //and change it (we only need the length of ans)
            }

        }

        return ans.size();
    }
};