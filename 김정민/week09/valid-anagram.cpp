class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> M;
        int sum = 0;
        for(int i=0; i<s.size(); i++) {
            M[s[i]]++;
        }

        for(int i=0; i<t.size(); i++) {
            if(M.count(t[i])) {
                M[t[i]]--;
            }
            else return false;
        }

        for(auto iter = M.begin(); iter != M.end(); iter++) {
            if(iter->second > 0) return false;
        }

        return true;
    }
};
