class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;

        int st = 0;
        int en = nums.size()-1;

        while(st <= en) {
            int mid = (st+en)/2;

            cout << st << ' ' << en << ' ' << mid << endl;

            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            if(nums[st] == target) {
                ans = st;
                break;
            }
            if(nums[en] == target) {
                ans = en;
                break;
            }

            // pivot 구간
            if(nums[st] > nums[mid]) {
                if(target > nums[mid] && target < nums[en]) st = mid+1;
                else en = mid-1;
            }
            // 오름차순 구간 nums[st] <= nums[mid]
            else {
                if(target < nums[mid] && target > nums[st]) en = mid-1;
                else st = mid+1;
            }
        }

        return ans;
    }
};