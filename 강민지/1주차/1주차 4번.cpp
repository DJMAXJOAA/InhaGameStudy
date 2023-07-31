class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        string temp;
        temp += s[0];
        int size = 0;
        int max = 0;
        int status = 0;

        if(s == " " || s.size() == 1)
            return 1;

        for(int i = 1; i < s.size();i++)
        {
            status = 0;

            for(int j = 0; j < temp.size(); j++)
            {
                size = temp.size();
                if(size > max)  max = size;

                // 중복된 문자열 발견
                if(temp[j] == s[i])
                {
                    temp.erase(0, j + 1);
                    temp += s[i];
                    status = 1;
                    break;
                }
            }
            
            // 중복 발견 X
            if(status == 0)
            {
                temp += s[i];
                size = temp.size();
                if(size > max)  max = size;
            }

        }

        return max;

    }
};
