class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<int> temp_index;
        vector<int>::iterator nums_itr;

        int i = 0;
        for (nums_itr = nums.begin(); nums_itr != nums.end(); ++nums_itr)
        {
            if (*nums_itr <= target)
            {
                temp.push_back(*nums_itr);
                temp_index.push_back(i);
            }
            i++;
        }

        vector<int> result;
        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = i + 1; j < temp.size(); j++)
            {
                if (target == temp[j] + temp[i])
                {
                    result.push_back(temp_index[i]);
                    result.push_back(temp_index[j]);
                    return result;
                }
            }
        }

        return result;
    }
};