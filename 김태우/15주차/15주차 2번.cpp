class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int ans = 0;
        int start = 0;
        int end = height.size() - 1;

        while (start <= end)
        {
            ans = max(ans, (end - start) * min(height[start], height[end]));

            if (height[start] < height[end])
            {
                start++;
            }

            else
            {
                end--;
            }

        }

        return ans;
    }
};