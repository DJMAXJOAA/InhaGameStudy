class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        
        int size = 0;
        int iMax = 1;
        vector<pair<bool, int>> temp(128);
        for (int i = 0; i < s.size(); i++)
        {
            if (temp[s[i]].first == true)
            {
                int tempi = temp[s[i]].second;

                for (int i = 0; i < temp.size(); i++)
                {
                    temp[i].first = false;
                }
                temp[s[i]].second = i;
                i = tempi;

                iMax = max(iMax, size);
                size = 0;

                continue;
            }
            temp[s[i]].first = true;
            temp[s[i]].second = i;
            size++;
        }
        if (iMax <= size)
            iMax = size;
        return iMax;
    }
};