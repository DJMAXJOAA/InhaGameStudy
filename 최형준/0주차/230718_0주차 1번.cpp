/*
https://leetcode.com/problems/two-sum/
�ҿ�ð� : 17�� (14:20 ~ 14:37)
ó���� ���ͷ����ͷ� ���� �� ���̰� Ǯ���� �ߴµ� �ȵǼ� ����
�� 2�� for�� �����ϱ� Ǯ����
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (target == nums[j] + nums[i])
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }
};