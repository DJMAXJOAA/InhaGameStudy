class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') return 0; // ���ڿ��� ����ų� ������ '0'�� ���� ���ڵ��� �� �����ϴ�.

        // dp[i]�� ���ڿ� s�� i��°������ �κ� ���ڿ��� ���ڵ��ϴ� ����� ���� �����մϴ�.
        vector<int> dp(s.size() + 1);
        dp[0] = 1; // ��� �ִ� ���ڿ��� ���ڵ��ϴ� ����� �ϳ��Դϴ�.
        dp[1] = s[0] != '0' ? 1 : 0; // ù ��° ���ڰ� '0'�� �ƴϸ� ���ڵ��� �� �ֽ��ϴ�.

        for (int i = 2; i <= s.size(); ++i) {
            // �� �ڸ� �� ���ڵ� ������ ���
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // �� �ڸ� ���� ��ȿ�� ���ĺ����� ���ڵ� ������ ��� (10~26)
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