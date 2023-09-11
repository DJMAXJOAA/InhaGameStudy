class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);

        int left = 1;
        ret[0] = left;
        for(int i=1; i<n; i++)
        {
            ret[i] = left * nums[i-1];
            left *= nums[i-1];
        }

        int right = 1;
        for(int i=n-1; i>=0; i--)
        {
            ret[i] = ret[i] * right;
            right *= nums[i];
        }

        return ret;
    }
};