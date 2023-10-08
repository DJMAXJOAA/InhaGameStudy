class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int ans = 1;
        int temp = 1;
        sort(nums.begin(), nums.end(), less<int>());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                temp++;
            }

            else if (nums[i] == nums[i - 1])
            {
                continue;
            }

            else
            {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};