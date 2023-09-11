class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<=n; i++) sum += i;

        for(auto& num : nums) sum -= num;

        return sum;
    }
};