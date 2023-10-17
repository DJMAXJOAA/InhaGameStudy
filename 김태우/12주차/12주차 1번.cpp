class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        int start = 0;
        int mid = n / 2;
        int end = n - 1;
        int size = n;
        int ans = INT_MAX;

        while (size > 0)
        {
            if (nums[start] > nums[mid])
            {
                ans = min(ans, nums[mid]);
                end = mid - 1;
                mid = (start + end) / 2;
            }

            else if (nums[mid] > nums[end])
            {
                ans = min(ans, nums[end]);
                start = mid + 1;
                mid = (start + end) / 2;
            }

            else
            {
                ans = min(ans, nums[start]);
            }

            size /= 2;
        }

        return ans;
    }
};