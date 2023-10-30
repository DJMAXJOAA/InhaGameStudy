
class Solution { //timeover
public:
    string longestPalindrome(string s) {

        int cnt = 0;
        string ans[1000];
        int output = 0;
        ans[0] = s.substr(0, 1);

        string temp;

        for (int i = 0; i < s.size() - 1; i++)
        {
            cnt = 1;
            temp.clear();
            for (int j = i + cnt; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    temp = s.substr(i, j - i + 1);

                    reverse(temp.begin(), temp.end()); // <<¾ê ¶§¹®ÀÎ°¡.

                    if (temp == s.substr(i, j - i + 1))
                    {
                        ans[cnt] = s.substr(i, j - i + 1);

                        output = max(output, cnt);
                    }
                }

                cnt++;
            }

        }

        cout << ans[output] << endl;
        return ans[output];

    }
};

class Solution {
public:
    string expandFromCenter(int l, int r, string s) {
        while (l >= 0 && r < s.size() && s[l] == s[r])
            l--, r++;
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string longest = "";
        for (int i = 0; i < s.size(); i++) {
            string odd = expandFromCenter(i, i, s);
            string even = expandFromCenter(i, i + 1, s);
            if (odd.size() > longest.size()) longest = odd;
            if (even.size() > longest.size()) longest = even;
        }
        return longest;
    }
};