class Solution {
public:
    int check(string s, int l, int r) {
        int cnt = 0;
        while(0 <= l && r < s.size()) {
            if(s[l] != s[r]) return cnt;
            l--; r++;
            cnt++;
        }

        return cnt;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            ans += check(s, i, i);
            if(i < s.size()-1)
                ans += check(s, i, i+1);
        }

        return ans;
    }
};