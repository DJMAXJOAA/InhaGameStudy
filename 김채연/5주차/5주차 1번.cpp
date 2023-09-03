#include <vector>
// Q1. 217. Contains Duplicate
// 한 배열에 같은 숫자가 2개 이상 있으면 true 반환.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 1 < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }

        return false;
    }
};

class Solution { //런타임 오버
public:
    bool containsDuplicate(vector<int>& nums) {
        int target;

        for (int i = 0; i < nums.size(); i++)
        {
            target = nums[i];

            for (int j = i + 1; i + 1 <= nums.size(); j++)
            {
                if (target == nums[j])
                    return true;
            }
        }

        return false;
    }
};