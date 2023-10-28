class Solution {
public:
    string find(string s, int left, int right) {
        string ret = "";
        int l = left;
        int r = right;

        while(0 <= l && r < s.size()) {
            if(s[l] == s[r]) {
                l--;
                r++;
            }
            else {
                break;
            }
        }
        ret = s.substr(l+1, r-l-1);

        return ret;
    }

    string find(string s, int mid) {
        string ret = "";
        int l = mid;
        int r = mid;

        while(0 <= l && r < s.size()) {
            if(s[l] == s[r]) {
                l--;
                r++;
            }
            else {
                break;
            }
        }
        ret = s.substr(l+1, r-l-1);

        return ret;
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            string tmp1 = find(s, i);
            string tmp2 = find(s, i, i+1);
            
            string t;
            if(tmp1.size() > tmp2.size()) {
                t = tmp1;
            }
            else {
                t = tmp2;
            }
            //cout << "i: " << i << ' ' << tmp1 << ' ' << tmp2 << endl;
            if(ans.size() < t.size())
                ans = t;
        }

        return ans;        
    }
};