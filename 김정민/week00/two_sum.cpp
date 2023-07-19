// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> M;
        vector<int> V;

        for(int i=0; i<nums.size(); i++)
        {
            int left = target - nums[i];
            if(M.count(left) > 0)
            {
                V.push_back(i);
                V.push_back(M[left]);
                M.erase(left);
            }
            else
            {
                M[nums[i]] = i;
            }
        }

        return V;
    }
};