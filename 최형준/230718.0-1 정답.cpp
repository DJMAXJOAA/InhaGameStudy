/*
https://leetcode.com/problems/two-sum/
소요시간 : 17분 (14:20 ~ 14:37)
처음에 이터레이터로 범위 좀 줄이고 풀려고 했는데 안되서 수정
걍 2중 for문 돌리니까 풀리네
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