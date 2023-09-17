[8주차 1번] / Longest Common Subsequence / 1시간 32분 / https://leetcode.com/problems/longest-common-subsequence/

[문제 접근]
사용 알고리즘 = 다이나믹 프로그래밍
1. 2차원 dp 테이블을 선언
2. 바텀 업 방식으로 테이블을 돌면서 값을 채움

[개선점]
1.  처음에는 슬라이딩 윈도우 문제인줄 알았으나, dp 문제였음
슬라이딩 윈도우는 연속된 부분 배열을 찾는 문제(무조건 연속되는)에 효율적인 방법
이 문제에서는 꼭 연속되지 않아도 제일 긴 서브시퀀스를 찾는 문제니까, 슬라이딩 윈도우는 적합하지 않음

[다른 풀이 방법]
1. 탑 다운 방식의 다이나믹 프로그래밍

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

[다른 풀이 방법]
탑 다운 방식의 다이나믹 프로그래밍
1. 재귀 함수를 사용 -> 큰 문제를 해결하기 위해서 더 작은 문제를 해결
2. -1이 아닌 부분은 이미 계산이 끝난 부분이니까 건너뜀

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