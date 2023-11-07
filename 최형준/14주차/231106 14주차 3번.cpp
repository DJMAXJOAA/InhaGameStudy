class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') return 0; // 문자열이 비었거나 시작이 '0'인 경우는 디코딩할 수 없습니다.

        // dp[i]는 문자열 s의 i번째까지의 부분 문자열을 디코딩하는 방법의 수를 저장합니다.
        vector<int> dp(s.size() + 1);
        dp[0] = 1; // 비어 있는 문자열을 디코딩하는 방법은 하나입니다.
        dp[1] = s[0] != '0' ? 1 : 0; // 첫 번째 문자가 '0'이 아니면 디코딩할 수 있습니다.

        for (int i = 2; i <= s.size(); ++i) {
            // 한 자리 수 디코딩 가능한 경우
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // 두 자리 수가 유효한 알파벳으로 디코딩 가능한 경우 (10~26)
            int two_digit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.size()];
    }
};

//class Solution {
//public:
//    int numDecodings(string s) {
//        if (s.size() == 1)
//        {
//            if (s[0] == '0') return 0;
//            else return 1;
//        }
//
//        int result;
//        vector<int> dp(s.size());
//        if (s[1] == '0')
//        {
//            if (s[0] == '0') return 0;
//            dp[0] = 1;
//            dp[1] = 1;
//        }
//        else if (s[0] == '0')
//        {
//            if (s[1] == '0') return 0;
//            dp[0] = 0;
//            dp[1] = 0;
//        }
//        else if (s[0] == '2')
//        {
//            dp[0] = 1;
//            if (s[1] >= '7')
//            {
//                dp[1] = 1;
//            }
//            else
//            {
//                dp[1] = 2;
//            }
//        }
//        else if (s[0] >= '3')
//        {
//            dp[0] = 1;
//            dp[1] = 1;
//        }
//        else
//        {
//            dp[0] = 1;
//            dp[1] = 2;
//        }
//
//        int i;
//        for (i = 2; i < s.size(); i++)
//        {
//            if (s[i] == '0')
//            {
//                if (s[i - 1] == '0') return 0;
//                dp[i] = dp[i - 1] - 1;
//            }
//            else if (s[i - 1] == '0')
//            {
//                dp[i] = dp[i - 1];
//            }
//            else if (s[i - 1] == '2')
//            {
//                if (s[i] >= '7')
//                {
//                    dp[i] = dp[i - 1];
//                }
//                else
//                {
//                    dp[i] = dp[i - 1] + dp[i - 2];
//                }
//            }
//            else if (s[i - 1] >= '3')
//            {
//                dp[i] = dp[i - 1];
//            }
//            else
//            {
//                dp[i] = dp[i - 1] + dp[i - 2];
//            }
//        }
//
//        return dp[i - 1];
//    }
//};