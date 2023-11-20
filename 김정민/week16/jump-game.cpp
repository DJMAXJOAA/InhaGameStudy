class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = false;

        int target = nums.size()-1;
        while(target >= 0) {
            bool flag = false;
            // cout << "target: " << target << endl;

            for(int i=0; i<=target-1; i++) {
                int d = target - i;
                // cout << "d: " << d << endl;
                if(d <= nums[i]) {
                    flag = true;
                    target = i;
                    break;
                }
            }

            if(!flag) break;
        }

        if(target == 0) ans = true;

        return ans;   
    }
};