class Solution {
public:
    int search(vector<int>& nums, int target) {
        //stl 날먹
        // auto it = find(nums.begin(), nums.end(), target);
        // if (it != nums.end()) {
        //     return distance(nums.begin(), it);
        // }
        // return -1;

        //구간을 두 개로 나눠서 각각 이분탐색 실행

        int answer = -1;
        if(nums.size() == 1 && nums[0] == target)
            return 0;
        if(nums[0]<nums.back())
            return binarySearch(nums,0, nums.size()-1,target);
        else
        {
            int start = 0;
            int end = nums.size()-1;
            while(start<end)
            {
                int mid = (end+start)/2;
                if(nums[mid]>nums[mid+1])
                {
                    
                    int left = binarySearch(nums, 0, mid,target);
                    int right = binarySearch(nums, mid+1, nums.size()-1, target);
                    answer = (left>right) ? left : right;
                    break;
                }
                else
                {
                    if(nums[mid]>nums[end])
                    {
                        start = mid;
                    }
                    else
                    {
                        end = mid;
                    }
                }
            }
        }
        return answer;
    }
    int binarySearch(vector<int>& nums, int start, int end, int target)
    {
        if(start>end)return -1;
        int mid = (end + start)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid]<target)
            return binarySearch(nums,mid+1, end,target);
        else
            return binarySearch(nums,start, mid-1,target);
    }
};