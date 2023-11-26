class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int end = nums.size();
        int reached = 0;

        for(int i = 0; i < end; i++)
        {
            if(i > reached) return false;
            reached = max(reached, i+nums[i]);
        }

        return true;
    }
};
