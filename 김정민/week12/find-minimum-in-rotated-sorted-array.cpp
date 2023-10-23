class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int st = 0;
        int en = nums.size()-1;
        
        while(st <= en) {
            int mid = (st + en) / 2;

            if(nums[st] <= nums[mid]) {
                ans = min(ans, nums[st]);
                st = mid + 1;
            }
            else {
                ans = min(ans, nums[mid]);
                en = mid - 1;
            }
            
        }
        return ans;
    }
};