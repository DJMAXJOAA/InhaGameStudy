[14���� 4��] / Palindromic Substrings / 9�� / https://leetcode.com/problems/palindromic-substrings/description/

[���� ����]
��� �˰��� = �߽� Ȯ�� �˰��� : O(n^2), O(1)
1. ¦���� Ȧ�� ��츦 ������ ���Ѵ�
2. �߾ӿ��� ������ �÷��� ���Ѵ�.

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