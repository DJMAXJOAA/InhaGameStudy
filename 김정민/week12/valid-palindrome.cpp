class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;

        for(int i=0; i<s.size(); i++) {
            char cur = s[i];
            if(('0' <= cur && cur <='9') || 
               ('a' <= cur && cur <='z') ||
               ('A' <= cur && cur <='Z'))
               tmp += cur;
        }

        if(tmp.empty()) return true;

        int sz = tmp.size();
        int l, r;
        if(sz % 2 == 0) {
            l = sz/2-1;
            r = sz/2;
        }
        else {
            l = r = sz/2;
        }

        while(l >=0 && r < tmp.size()) {
            char leftChar = tolower(tmp[l]);
            char rightChar = tolower(tmp[r]);

            if(leftChar != rightChar) return false;
            
            l--;
            r++;
        }

        return true;
    }
};