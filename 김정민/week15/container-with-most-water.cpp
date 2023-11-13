class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size()-1;

        while(l < r) {
            int w = r-l;
            int h = min(height[l], height[r]);

            ans = max(ans, w*h);

            if(height[l] < height[r]) l++;
            else r--;
        }

        return ans;
    }
};