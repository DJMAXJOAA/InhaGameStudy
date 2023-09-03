#include <vector>
// Q1. 217. Contains Duplicate
// �� �迭�� ���� ���ڰ� 2�� �̻� ������ true ��ȯ.

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

class Solution { //��Ÿ�� ����
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