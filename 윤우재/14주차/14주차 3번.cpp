class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);

        unordered_map<string, int> map;
        for(int i = 1; i<=26;i++)
        {
            string x = to_string(i);
            map[x] = 1;
        }
        return count(s, 0, map, dp);

    }

    int count(string& s, int idx, unordered_map<string, int> map, vector<int>& dp)
    {
        if(idx == s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];

        int one = 0;
        int two = 0;

        if(map.find(s.substr(idx,1))!= map.end())
            one = count(s, idx + 1, map, dp);
        
        if(idx<s.size()-1)
        {
            if(map.find(s.substr(idx,2))!=map.end())
                two = count(s, idx + 2, map, dp);
        }
        return dp[idx] = one+two;
    }
};