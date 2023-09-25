
// 런타임 에러
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
        {
            return false;
        }

        for (int i = 0; i < s.size(); i++)
        {
            t.erase(find(t.begin(), t.end(), 's[i]'));

            if (t.size() == 0)
                return true;
        }

        return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};