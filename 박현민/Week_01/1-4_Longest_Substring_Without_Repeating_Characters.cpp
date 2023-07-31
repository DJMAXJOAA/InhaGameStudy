class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int i = 0;
        int j = 0;
        int len = s.length();
        vector<string> subString(len);

        while (i < len)
        {
            size_t found = string::npos;
            while (found == string::npos && j < len)
            {
                subString[i] += s[j];
                j++;
                found = subString[i].find(s[j]);
            }
            i++;
            j = i;
        }

        int ret = 0;

        for (int k = 0; k < len; k++)
        {
            ret = max(ret, (int)subString[k].length());
        }

        return ret;
    }
};