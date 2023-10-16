class Solution {
public:
    bool isValid(string s) {

        string s2;
        s2 = "({[)}]";

        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] == s2[0])
            {
                if (s[i + 1] != s2[3])
                    return false;
            }
            if (s[i] == s2[1])
            {
                if (s[i + 1] != s2[4])
                    return false;
            }
            if (s[i] == s2[2])
            {
                if (s[i + 1] != s2[5])
                    return false;
            }
        }

        return true;
    }
};