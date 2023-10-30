//중간점 찾기 mid = (l + h) / 2
//키가 중간 지점에 있으면 mid를 반환합니다.
//Else arr[l..mid]가 정렬된 경우
//a) 검색할 키가 arr[l]에서
//arr[mid] 범위에 있으면 arr[l..mid]에 대해 반복됩니다.
//b) 그렇지 않으면 arr[mid + 1..h]에 대해 반복됩니다.
//Else(arr[mid + 1..h]는 정렬되어야 함)
//a) 검색할 키가 arr[mid + 1]에서
//arr[h] 범위에 있으면 arr[mid + 1..h]에 대해 반복됩니다.
//b) arr[l..mid]에 대한 반복

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1, mid;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[beg] <= nums[mid])
            {
                if (target <= nums[mid] && target >= nums[beg])
                    end = mid - 1;
                else
                    beg = mid + 1;
            }

            else
            {
                if (target >= nums[mid] && target <= nums[end])
                    beg = mid + 1;
                else
                    end = mid - 1;
            }

        }
        return -1;
    }
    
};

