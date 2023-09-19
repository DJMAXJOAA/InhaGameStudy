class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //알파벳 26글자
        int sAlphabet[26] = {0};
        int tAlphabet[26] = {0};

        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++)
        {
            char a = s[i];
            char b = t[i];
            
            sAlphabet['z' - a]++;
            tAlphabet['z' - b]++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(sAlphabet[i] == tAlphabet[i])
                continue;
            else
                return false;
        }

        return true;
    }
};
