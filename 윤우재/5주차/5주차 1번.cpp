class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(auto e : nums)
        {
            int tempLen = m.size();
            m.insert(make_pair(e,0));
            if(tempLen == m.size())
                return true;
        }
        return false;
    }
};