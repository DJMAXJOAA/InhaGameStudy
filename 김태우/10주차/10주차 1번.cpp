class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        if (wordDict.size() == 0) return false;

        unordered_set<string> dict;

        for (int i = 0; i < wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string word = s.substr(j, i - j);
                    if (dict.find(word) != dict.end())
                    {
                        dp[i] = true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
    }

    // aaaaaaa
    // bool wordBreak(string s, vector<string>& wordDict)
    // {
    //     bool ans = true;
    //     map<string, bool> Dict;
    //     string word = ""; 

    //     //Check SubString

    //     for(int i = 0; i < wordDict.size();i++)
    //     {
    //         Dict[wordDict[i]] = true;
    //     }

    //     for(int i = 0; i < s.size(); i++)
    //     {
    //         word+=s[i];
    //         if(Dict[word])
    //         {
    //             word = "";
    //         }
    //     }

    //     if(word !="") 
    //         ans = false;

    //     return ans;
    // }
};