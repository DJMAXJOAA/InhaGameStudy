// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;

        for(auto& n : nums)
        {
            if(s.contains(n)) return true;
            s.insert(n);
        }

        return false;
    }
};
