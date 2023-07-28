// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> box;
        int ans = 0;
        int mx = s.size();

        int l = 0;
        int r = 0;

        while(r < mx)
        {
            char cur = s[r];

            if(box.count(cur) > 0)
            {
                while(l < r)
                {
                    box.erase(s[l++]);
                    if(box.count(cur) == 0) break;
                }
            }
            // cout << l << ' ' << r << endl;
            box.insert(cur);
            ans = max(ans, int(box.size()));
            r++;
        }

        return ans;
    }
};
