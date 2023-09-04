// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> M;
    
        for(int i=0; i<t.size(); i++)
        {
            M[t[i]]++;
        }

        int sz = s.size();
        int l = 0;
        int r = 0;
        int cnt = t.size();

        string ans = "";

        while(r < sz)
        {
            char cur = s[r];

            if(M.find(cur) != M.end())
            {
                if(M[cur] > 0)
                {
                    cnt--;
                }
                M[cur]--;
            }

            r++;

            if(cnt == 0)
            {
                while(cnt == 0 && l < r)
                {
                    char pop = s[l++];

                    if(M.find(pop) != M.end())
                    {
                        if(M[pop] == 0)
                        {
                            cnt++;
                        }
                        M[pop]++;
                    }
                }
            
                if(ans.size() == 0)
                {
                    ans = s.substr(l-1, r - l + 1);
                }
                else
                {
                    ans = (r - l < ans.size()) ? s.substr(l-1, r - l + 1) : ans;
                }
            }
        }

        return ans;
    }
};
