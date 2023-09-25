class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //if(s.size() != t.size()) return false;
        vector<int> map1(128,0);
        vector<int> map2(128,0);
        for(auto c : s)
        {
            map1[c]++;
        }
        for(auto c : t)
        {
            map2[c]++;
        }
        for(int i = 0; i<128;i++)
        {
            if(map1[i]!=map2[i])
                return false;
        }
        return true;
    }
};