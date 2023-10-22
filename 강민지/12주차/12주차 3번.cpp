class Solution {
public:
    bool isPalindrome(string s) {
        
        vector<char> temp;
        for(int i = 0; i < s.size(); i++)
        {
            if(isalpha(s[i]) != 0 || ('0' <= s[i] && s[i] <= '9')) // 알파벳 & 숫자만
            {
                if(s[i] <= 90) // 소문자 변환
                    s[i] += 32;
                
                temp.push_back(s[i]);
            }
        }

        int tempSize = temp.size();

        for(int i = 0; i < tempSize; i++)
        {
            if(temp[i] == temp[tempSize - i - 1])
                continue;
            else
                return false;
        }

        return true;
    }
};
