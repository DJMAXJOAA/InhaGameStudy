class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int, int> map1;
        int beforeSize = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            beforeSize = map1.size();
            map1.insert({nums[i], i});
            int afterSize = map1.size();

            if(beforeSize == afterSize)
                return true;
        }

        return false;
    }
};
