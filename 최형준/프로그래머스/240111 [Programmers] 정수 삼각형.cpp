[Programmers] 정수 삼각형 / Lv.3 / https://school.programmers.co.kr/learn/courses/30/lessons/43105
1. dp 테이블을 채울 때 어떤걸 채우고 있는지 잘 확인하기(실수 여지 있음)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp(501, vector<int>(501));

int solution(vector<vector<int>> triangle) {
    if (triangle.size() == 1)
        return triangle[0][0];

    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[0][0] + triangle[1][0];
    dp[1][1] = triangle[0][0] + triangle[1][1];
    for (int i = 2; i < triangle.size(); i++)
    {
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        for (int j = 1; j < triangle[i].size() - 1; j++)
        {
            dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
        dp[i][triangle[i].size() - 1] = triangle[i][triangle[i].size() - 1] + dp[i - 1][triangle[i].size() - 2];
    }

    int answer = 0;
    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
    {
        answer = max(answer, dp[triangle.size() - 1][i]);
    }

    return answer;
}