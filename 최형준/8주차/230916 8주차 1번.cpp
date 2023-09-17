[8���� 1��] / Longest Common Subsequence / 1�ð� 32�� / https://leetcode.com/problems/longest-common-subsequence/

[���� ����]
��� �˰��� = ���̳��� ���α׷���
1. 2���� dp ���̺��� ����
2. ���� �� ������� ���̺��� ���鼭 ���� ä��

[������]
1.  ó������ �����̵� ������ �������� �˾�����, dp ��������
�����̵� ������� ���ӵ� �κ� �迭�� ã�� ����(������ ���ӵǴ�)�� ȿ������ ���
�� ���������� �� ���ӵ��� �ʾƵ� ���� �� ����������� ã�� �����ϱ�, �����̵� ������� �������� ����

[�ٸ� Ǯ�� ���]
1. ž �ٿ� ����� ���̳��� ���α׷���

Time taken : 1 hr 32 m 42 s
Runtime 50ms
Beats 62.72 % of users with C++
Memory 24.86MB
Beats 6.83 % of users with C++

//    x  d  f  a
// d  0  1  1  1
// f  0  1  2  2
// x  1  1  2  2
// a  1  1  2  3
// d  1  2  2  3
// e  1  2  2  3

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int size1 = text1.size();
        int size2 = text2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for (int i = 1; i <= size1; i++)
        {
            for (int j = 1; j <= size2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[size1][size2];
    }
};

[�ٸ� Ǯ�� ���]
ž �ٿ� ����� ���̳��� ���α׷���
1. ��� �Լ��� ��� -> ū ������ �ذ��ϱ� ���ؼ� �� ���� ������ �ذ�
2. -1�� �ƴ� �κ��� �̹� ����� ���� �κ��̴ϱ� �ǳʶ�

class Solution {
private:
    int dp[1001][1001];
    string text1, text2;

    int lcs(int i, int j) {
        // Base case
        if (i == 0 || j == 0) return 0;

        // Check memoized value
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i - 1] == text2[j - 1]) {
            return dp[i][j] = 1 + lcs(i - 1, j - 1);
        }
        else {
            return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
        }
    }

public:
    int longestCommonSubsequence(string t1, string t2) {
        text1 = t1;
        text2 = t2;

        memset(dp, -1, sizeof(dp));
        return lcs(text1.size(), text2.size());
    }
};