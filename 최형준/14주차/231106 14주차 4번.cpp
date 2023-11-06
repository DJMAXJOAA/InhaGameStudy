[14주차 4번] / Palindromic Substrings / 9분 / https://leetcode.com/problems/palindromic-substrings/description/

[문제 접근]
사용 알고리즘 = 중심 확장 알고리즘 : O(n^2), O(1)
1. 짝수와 홀수 경우를 나눠서 비교한다
2. 중앙에서 범위를 늘려서 비교한다.

Time taken : 9 m 32 s
Runtime 5ms
Beats 60.93 % of users with C++
Memory 6.63MB
Beats 77.86 % of users with C++

class Solution {
public:
    bool Palindrome(string& s, int start, int end)
    {
        if (start < 0 || end >= s.size())
        {
            return false;
        }

        return s[start] == s[end];
    }

    int countSubstrings(string s) {
        if (s.size() == 1)
            return 1;

        int result = 0;
        int start, end;
        for (int i = 0; i < s.size(); i++)
        {
            start = i;
            end = i;
            while (Palindrome(s, start, end))
            {
                result++;
                start--;
                end++;
            }
        }

        for (int i = 1; i < s.size(); i++)
        {
            start = i - 1;
            end = i;
            while (Palindrome(s, start, end))
            {
                result++;
                start--;
                end++;
            }
        }

        return result;
    }
};