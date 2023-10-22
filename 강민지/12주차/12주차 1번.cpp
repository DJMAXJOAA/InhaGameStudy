class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;

        if(nums[start] < nums[end])  
            return nums[start];

        // 이진 검색
        while(start < end)
        {
            if(nums[mid] > nums[end]) // 오른쪽 탐색
                start = mid + 1;
            else // 왼쪽 탐색
                end = mid;
            
             mid = (start + end) / 2;
        }
        
        return nums[start];
    }
};
