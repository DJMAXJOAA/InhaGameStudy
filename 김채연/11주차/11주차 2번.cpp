class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProducts = nums[0]; // 부호에 따라 큰값이 달라지니까 max, min 둘다에 i번째 수를 곱하고 그 중에 큰거를 찾을거임.
        int minProducts = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int now = nums[i]; 
            int a = maxProducts * now;
            int b = minProducts * now;
            maxProducts = max(now, max(a, b));
            minProducts = min(now, min(a, b));
            ans = max(ans, maxProducts);
        }
        return ans;
    }
};