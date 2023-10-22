class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //걍 앞->뒤로 다곱하고, 뒤->앞으로 다곱해서 최대값 뽑아내면되겠네
        int maximum = INT_MIN;
        int cur = 1;
        for(int i = 0; i<nums.size();i++)
        {
            cur *= nums[i];
            maximum = max(maximum, cur);
            if(cur == 0)
                cur = 1;
        }
        cur = 1;
        for(int i = nums.size()-1;i>=0;i--)
        {
            cur *= nums[i];
            maximum = max(maximum, cur);
            if(cur == 0)
                cur = 1;
        }
        return maximum;
    }
};