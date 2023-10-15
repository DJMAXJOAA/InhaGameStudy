class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mm = 1;
        int mx = 1;
        int ans = INT_MIN;

        // mm: 연속하는 가장 작은 숫자의 곱
        // mx: 연속하는 가장 큰 숫자의 곱
        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            int t1 = mm * n;
            int t2 = mx * n;

            mx = max(n, max(t1, t2));
            mm = min(n, min(t1, t2));

            ans = max(mx, ans);
        }

        return ans;   
    }
};