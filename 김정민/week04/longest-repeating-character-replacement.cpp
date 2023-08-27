// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int getMax(vector<int>& abc)
    {
        int ret = -1;
        for(int v : abc)
        {
            ret = max(ret, v);
        }
        return ret;
    }
    int characterReplacement(string s, int k) {
        vector<int> abc(26, 0);
        int l = 0;
        int r = 0;
        int ans = 0;

        while(r < s.size())
        {
            char cr = s[r++];
            abc[cr - 'A']++;

            int mx = getMax(abc);
            int w = r - l;

            if(w - mx <= k)
            {
                ans = max(ans, w);
            }
            else
            {
                while(l < r && w - mx > k)
                {
                    abc[s[l++] - 'A']--;
                    w = r - l;
                    mx = getMax(abc);
                }
                ans = max(ans, w);
            }
        }

        return ans;
    }
};