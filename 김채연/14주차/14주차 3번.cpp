
class Solution {
public:
    int numDecodings(string s) {
        s = "00" + s;

        vector<int> dp(s.size(), 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i < s.size(); ++i) {
            if (s[i] != '0')
                dp[i] += dp[i - 1];

            int idx = (int)(s[i - 1] - '0') * 10 + (int)(s[i] - '0');
            if (10 <= idx && idx <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[s.size() - 1];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();

        vector<int> dp(len, 0);
        dp[0] = (s[0] == '0') ? 0 : 1;

        for (int i = 1; i < len; i++) {

            int n1 = s[i - 1] - '0';
            int n2 = s[i] - '0';

            int sum = n1 * 10 + n2;

            if (n2 == 0) {

                if (sum == 10 || sum == 20) {
                    dp[i] = (i - 2 >= 0) ? dp[i - 2] : 1;
                }
                else {
                    return 0;
                }

            }
            else {

                dp[i] = dp[i - 1];

                if (sum >= 10 && sum <= 26) {
                    dp[i] += (i - 2 >= 0) ? dp[i - 2] : 1;
                }
            }

        }
        return dp[len - 1];
    }
};