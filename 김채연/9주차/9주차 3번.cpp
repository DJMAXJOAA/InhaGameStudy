class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_val = INT_MIN; //int의 최소 값을 의미

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            max_val = max(sum, max_val);

            if (sum < 0) {
                sum = 0;
            }
        }
        return max_val;
    }
};