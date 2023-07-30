lass Solution {
public:
    bool checkSubStr(const string& s)
    {
        map<char, int> temp;
        for (int i = 0; i < s.size(); i++)
            temp.insert({ s[i],i });

        return temp.size() == s.size();
    }

    int lengthOfLongestSubstring(string s) {
        vector<string> subStrs;
        int len = 1;
        while (1)
        {
            bool flag = false;
            // 문자열 슬라이싱해서 저장해놓기
            for (int i = 0; i < s.size() - len+1; i++)
            {
                subStrs.push_back(s.substr(i, len));
                //cout << s.substr(i, len) << endl;
            }

            for (auto e : subStrs)
            {
                if (checkSubStr(e))
                {
                    len++;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                subStrs.clear();
                continue;
            }
            else
                return len-1;
        }
    }
};