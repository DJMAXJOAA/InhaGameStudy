class Solution {
public:
    bool isPalindrome(string s)
    {
        string temp = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57)
            {
                temp += s[i];
            }

            else if (s[i] >= 65 && s[i] <= 90)
            {
                temp += s[i] + 32;
            }
        }

        for (int i = 0; i < temp.size() / 2; i++)
        {
            if (temp[i] != temp[temp.size() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};