class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c : s)
        {
            if(!isalnum(c))
                continue;
            if(isupper(c))
                str+=tolower(c);
            else
                str+=c;
        }

        for(int i = 0; i<str.size()/2;i++)
        {
            if(str[i]!=str[str.size()-1-i])
                return false;
        }
        return true;
    }
};